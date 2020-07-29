#ifndef IEME_FLOATING_POINT_HPP
#define IEME_FLOATING_POINT_HPP

#include <ieme/fraction.hpp>
#include <ieme/fraction_math.hpp>
#include <ieme/limits.hpp>
#include <ieme/parse_utilities.hpp>

#include <cstdint>
#include <limits>
#include <string_view>
#include <tuple>


namespace ieme {


template <typename Rep, typename Ops = ops::defaults>
constexpr fraction<Rep, Ops> to_fraction(float value) noexcept;

template <typename Rep, typename Ops = ops::defaults>
constexpr fraction<Rep, Ops> to_fraction(double value) noexcept;

template <typename Rep, typename Ops>
constexpr float to_float(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr double to_double(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr long double to_long_double(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops = ops::defaults>
constexpr fraction<Rep, Ops>
floating_point_string_to_fraction(std::string_view string) noexcept;


enum class endian {
#ifdef _WIN32
  little = 0,
  big = 1,
  native = little
#else
  little = __ORDER_LITTLE_ENDIAN__,
  big = __ORDER_BIG_ENDIAN__,
  native = __BYTE_ORDER__
#endif
};

template <typename Rep,
          typename Ops,
          typename Float,
          typename UintRep,
          auto NumMantissaBits,
          auto NumExponentBits>
constexpr fraction<Rep, Ops> floating_point_to_fraction(Float value) noexcept;

template <typename Float, typename Rep, typename Ops>
constexpr Float
fraction_to_floating_point(const fraction<Rep, Ops>& value) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> to_fraction(const float value) noexcept
{
  static_assert(std::numeric_limits<float>::is_iec559, "");

  return floating_point_to_fraction<Rep, Ops, float, uint32_t, 23, 8>(value);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> to_fraction(const double value) noexcept
{
  static_assert(std::numeric_limits<double>::is_iec559, "");

  return floating_point_to_fraction<Rep, Ops, double, uint64_t, 52, 11>(value);
}

template <typename Rep, typename Ops>
constexpr float to_float(const fraction<Rep, Ops>& value) noexcept
{
  return fraction_to_floating_point<float>(value);
}

template <typename Rep, typename Ops>
constexpr double to_double(const fraction<Rep, Ops>& value) noexcept
{
  return fraction_to_floating_point<double>(value);
}

template <typename Rep, typename Ops>
constexpr long double to_long_double(const fraction<Rep, Ops>& value) noexcept
{
  return fraction_to_floating_point<long double>(value);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
floating_point_string_to_fraction(const std::string_view string) noexcept
{
  const auto scan_results = parse_utilities::scan_floating_point_string(string);

  if (!scan_results.is_valid)
    return limits<fraction<Rep, Ops>>::undefined();

  const auto base = Rep(scan_results.base);

  const auto digits_to_int
    = [&](const std::string_view digits, const Rep digit_base) -> Rep {
    auto result = Rep(0);
    auto base_power = Rep(1);

    for (auto it = digits.rbegin(); it != digits.rend(); ++it)
    {
      if (*it == '\'')
        continue;

      const auto digit_as_int = [&]() {
        if (*it >= 'A' && *it <= 'F')
          return Rep(*it - 'A' + 10);

        if (*it >= 'a' && *it <= 'f')
          return Rep(*it - 'a' + 10);

        return Rep(*it - '0');
      }();

      result += digit_as_int * base_power;
      base_power *= digit_base;
    }

    return result;
  };

  const auto whole = digits_to_int(scan_results.whole, base);

  const auto fractional_num = digits_to_int(scan_results.fractional, base);
  const auto fractional_den
    = math_utilities::pow(base, Rep(scan_results.fractional_precision));

  const auto exponent_base = (base == Rep(10)) ? Rep(10) : Rep(2);
  const auto exponent = (scan_results.exponent_sign == '-' ? Rep(-1) : Rep(1))
                        * digits_to_int(scan_results.exponent, 10U);

  return (whole + fraction<Rep, Ops>(fractional_num, fractional_den))
         * pow<Rep, Ops>(exponent_base, exponent);
}

template <typename Rep,
          typename Ops,
          typename Float,
          typename UintRep,
          auto NumMantissaBits,
          auto NumExponentBits>
constexpr fraction<Rep, Ops>
floating_point_to_fraction(const Float value) noexcept
{
  const auto makeRepeating1s
    = [](const UintRep count) { return (UintRep(1) << count) - UintRep(1); };

  const auto [sign_part, exponent_part, mantissa_part] = [&]() {
    union float_and_uint_union {
      UintRep uint_rep_part;
      Float float_part;
      float_and_uint_union(const Float init) : float_part {init} {}
    };

    const auto as_uint_rep = float_and_uint_union(value).uint_rep_part;

    const auto extract_bit_field
      = [&](const UintRep position, const UintRep size) -> UintRep {
      return (as_uint_rep >> position) & makeRepeating1s(size);
    };

    if constexpr (endian::native == endian::little)
      return std::make_tuple(
        extract_bit_field(NumMantissaBits + NumExponentBits, 1),
        extract_bit_field(NumMantissaBits, NumExponentBits),
        extract_bit_field(0, NumMantissaBits));
    else if (endian::native == endian::big)
      return std::make_tuple(
        extract_bit_field(0, 1),
        extract_bit_field(1, NumExponentBits),
        extract_bit_field(NumExponentBits + 1, NumMantissaBits));
  }();

  if (exponent_part == makeRepeating1s(NumExponentBits)
      && mantissa_part != UintRep(0))
    return limits<fraction<Rep, Ops>>::undefined();

  const auto sign = (sign_part == UintRep(0)) ? Rep(1) : Rep(-1);

  const auto exponent_bias
    = math_utilities::pow2(Rep(NumExponentBits) - Rep(1)) - Rep(1);
  const auto exponent = Rep(exponent_part) - exponent_bias;

  const auto mantissa
    = Rep(1)
      + fraction<Rep, Ops>(Rep(mantissa_part),
                           math_utilities::pow2<Rep>(Rep(NumMantissaBits)));

  return sign * mantissa * pow2<Rep, Ops>(exponent);
}

template <typename Float, typename Rep, typename Ops>
constexpr Float
fraction_to_floating_point(const fraction<Rep, Ops>& value) noexcept
{
  const auto reduced = reduce(value);

  return Float(reduced.num()) / Float(reduced.den());
}


}; // namespace ieme


#endif
