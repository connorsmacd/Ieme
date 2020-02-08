#ifndef IEME_FLOATING_POINT_HPP
#define IEME_FLOATING_POINT_HPP

#include <ieme/endian.hpp>
#include <ieme/fraction.hpp>
#include <ieme/fraction_math.hpp>

#include <cstdint>
#include <limits>
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


template <typename Rep,
          typename Ops,
          typename Float,
          typename IntegerRep,
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

template <typename Rep,
          typename Ops,
          typename Float,
          typename IntegerRep,
          auto NumMantissaBits,
          auto NumExponentBits>
constexpr fraction<Rep, Ops>
floating_point_to_fraction(const Float value) noexcept
{
  const auto [sign_part, exponent_part, mantissa_part] = [=]() {
    union superposition {
      IntegerRep integer_rep_part;
      Float float_part;
      superposition(const Float init) : float_part {init} {}
    };

    const auto as_integer_rep = superposition(value).integer_rep_part;

    const auto extract_bit_field
      = [=](const IntegerRep position, const IntegerRep size) -> IntegerRep {
      return (as_integer_rep >> position)
             & ((IntegerRep(1) << size) - IntegerRep(1));
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

  const auto sign = (sign_part == IntegerRep(0)) ? Rep(1) : Rep(-1);

  const auto exponent_bias
    = math_utilities::pow2(Rep(NumExponentBits) - Rep(1)) - Rep(1);
  const auto exponent = Rep(exponent_part) - exponent_bias;

  const auto mantissa
    = Rep(1) + Rep(mantissa_part) / pow2<Rep, Ops>(NumMantissaBits);

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
