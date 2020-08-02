#ifndef IEME_FLOATING_POINT_HPP
#define IEME_FLOATING_POINT_HPP

#include <ieme/fraction.hpp>
#include <ieme/fraction_math.hpp>
#include <ieme/limits.hpp>
#include <ieme/parse_utilities.hpp>

#include <cstdint>
#include <limits>
#include <string>
#include <string_view>
#include <tuple>


namespace ieme {


template <typename Rep, typename Ops = ops::defaults>
fraction<Rep, Ops> to_fraction(float value) noexcept;

template <typename Rep, typename Ops = ops::defaults>
fraction<Rep, Ops> to_fraction(double value) noexcept;

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

// TODO: use std::bit_cast when it's available so this can be constexpr
template <typename Rep,
          typename Ops,
          typename Float,
          typename UintRep,
          auto NumMantissaBits,
          auto NumExponentBits>
fraction<Rep, Ops> floating_point_to_fraction(Float value) noexcept;

template <typename Float, typename Rep, typename Ops>
constexpr Float
fraction_to_floating_point(const fraction<Rep, Ops>& value) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
fraction<Rep, Ops> to_fraction(const float value) noexcept
{
  static_assert(std::numeric_limits<float>::is_iec559, "");

  return floating_point_to_fraction<Rep, Ops, float, uint32_t, 23, 8>(value);
}

template <typename Rep, typename Ops>
fraction<Rep, Ops> to_fraction(const double value) noexcept
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

  const auto base_as_rep = Rep(scan_results.base);

  const auto whole
    = parse_utilities::digit_sequence_to_int(scan_results.whole, base_as_rep);

  const auto fractional_num = parse_utilities::digit_sequence_to_int(
    scan_results.fractional, base_as_rep);
  const auto fractional_den
    = math_utilities::pow(base_as_rep, Rep(scan_results.fractional_precision));

  const auto exponent_base = (scan_results.base == 10U) ? Rep(10) : Rep(2);
  const auto exponent
    = (scan_results.exponent_sign == '-' ? -1 : 1)
      * parse_utilities::digit_sequence_to_int(scan_results.exponent, 10);

  return (whole + fraction<Rep, Ops>(fractional_num, fractional_den))
         * pow<Rep, Ops>(exponent_base, exponent);
}

template <typename Rep,
          typename Ops,
          typename Float,
          typename UintRep,
          auto NumMantissaBits,
          auto NumExponentBits>
fraction<Rep, Ops> floating_point_to_fraction(const Float value) noexcept
{
  const auto make_repeating_1s
    = [](const UintRep count) { return (UintRep(1) << count) - UintRep(1); };

  const auto [sign_part, exponent_part, mantissa_part] = [&]() {
    const auto as_uint_rep = [&]() {
      UintRep result {};
      std::memcpy(reinterpret_cast<void*>(&result),
                  reinterpret_cast<const void*>(&value),
                  sizeof(Float));
      return result;
    }();

    const auto extract_bit_field
      = [&](const UintRep position, const UintRep size) -> UintRep {
      return (as_uint_rep >> position) & make_repeating_1s(size);
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

  if (exponent_part == make_repeating_1s(NumExponentBits)
      && mantissa_part != UintRep(0))
    return limits<fraction<Rep, Ops>>::undefined();

  const auto sign = (sign_part == UintRep(0)) ? Rep(1) : Rep(-1);

  const auto exponent_bias = math_utilities::pow2(int(NumExponentBits) - 1) - 1;
  const auto exponent = int(exponent_part) - exponent_bias;

  const auto mantissa
    = Rep(1)
      + fraction<Rep, Ops>(Rep(mantissa_part),
                           math_utilities::pow2(Rep(NumMantissaBits)));

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
