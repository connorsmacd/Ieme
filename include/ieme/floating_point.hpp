#ifndef IEME_FLOATING_POINT_HPP
#define IEME_FLOATING_POINT_HPP

#include <ieme/fraction.hpp>
#include <ieme/fraction_math.hpp>
#include <ieme/limits.hpp>
#include <ieme/numbers.hpp>
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
constexpr float to_float(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr double to_double(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr long double to_long_double(fraction<Rep, Ops> const& value) noexcept;

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
fraction<Rep, Ops> floating_point_to_fraction(Float value) noexcept;

template <typename Float, typename Rep, typename Ops>
constexpr Float
fraction_to_floating_point(fraction<Rep, Ops> const& value) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
fraction<Rep, Ops> to_fraction(float const value) noexcept
{
  static_assert(std::numeric_limits<float>::is_iec559, "");

  return floating_point_to_fraction<Rep, Ops, float, uint32_t, 23, 8>(value);
}

template <typename Rep, typename Ops>
fraction<Rep, Ops> to_fraction(double const value) noexcept
{
  static_assert(std::numeric_limits<double>::is_iec559, "");

  return floating_point_to_fraction<Rep, Ops, double, uint64_t, 52, 11>(value);
}

template <typename Rep, typename Ops>
constexpr float to_float(fraction<Rep, Ops> const& value) noexcept
{
  return fraction_to_floating_point<float>(value);
}

template <typename Rep, typename Ops>
constexpr double to_double(fraction<Rep, Ops> const& value) noexcept
{
  return fraction_to_floating_point<double>(value);
}

template <typename Rep, typename Ops>
constexpr long double to_long_double(fraction<Rep, Ops> const& value) noexcept
{
  return fraction_to_floating_point<long double>(value);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
floating_point_string_to_fraction(std::string_view const string) noexcept
{
  auto const scan_results = parse_utilities::scan_floating_point_string(string);

  if (!scan_results.is_valid)
    return limits<fraction<Rep, Ops>>::undefined();

  auto const base_as_rep = static_cast<Rep>(scan_results.base);

  auto const whole
    = parse_utilities::digit_sequence_to_int(scan_results.whole, base_as_rep);

  auto const fractional_num = parse_utilities::digit_sequence_to_int(
    scan_results.fractional, base_as_rep);
  auto const fractional_den = math_utilities::pow(
    base_as_rep, static_cast<Rep>(scan_results.fractional_precision));

  auto const exponent_base = (scan_results.base == 10U) ? _10<Rep> : _2<Rep>;
  auto const exponent_sign_multiplier = [&] {
    switch (scan_results.exponent_sign)
    {
      case parse_utilities::sign::negative:
        return -1;
      case parse_utilities::sign::positive:
        return +1;
    }
  }();
  auto const exponent
    = exponent_sign_multiplier
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
fraction<Rep, Ops> floating_point_to_fraction(Float const value) noexcept
{
  auto const make_repeating_1s
    = [](UintRep const count) { return (_1<UintRep> << count) - _1<UintRep>; };

  auto const [sign_part, exponent_part, mantissa_part] = [&]() {
    auto const as_uint_rep = [&]() {
      UintRep result {};
      // TODO: use std::bit_cast when it's available so
      // floating_point_to_fraction can be constexpr
      std::memcpy(static_cast<void*>(&result),
                  static_cast<void const*>(&value),
                  sizeof(Float));
      return result;
    }();

    auto const extract_bit_field
      = [&](UintRep const position, UintRep const size) -> UintRep {
      return (as_uint_rep >> position) & make_repeating_1s(size);
    };

    static constexpr auto num_sign_bits = _1<UintRep>;
    static constexpr auto num_exponent_bits = number<NumExponentBits, UintRep>;
    static constexpr auto num_mantissa_bits = number<NumMantissaBits, UintRep>;

    struct bitfield_offsets {
      UintRep sign_bit = {};
      UintRep exponent_bits = {};
      UintRep mantissa_bits = {};
    };

    static constexpr auto offsets = []() -> bitfield_offsets {
      switch (endian::native)
      {
        case endian::little:
          return {num_mantissa_bits + num_exponent_bits,
                  num_mantissa_bits,
                  _0<UintRep>};
        case endian::big:
          return {
            _0<UintRep>, num_sign_bits, num_sign_bits + num_exponent_bits};
      }
    }();

    return std::make_tuple(
      extract_bit_field(offsets.sign_bit, num_sign_bits),
      extract_bit_field(offsets.exponent_bits, num_exponent_bits),
      extract_bit_field(offsets.mantissa_bits, num_mantissa_bits));
  }();

  if (auto const is_NaN = exponent_part == make_repeating_1s(NumExponentBits)
                          && mantissa_part != _0<UintRep>;
      is_NaN)
    return limits<fraction<Rep, Ops>>::undefined();

  auto const sign = (sign_part == _0<UintRep>) ? _1<Rep> : -_1<Rep>;

  static constexpr auto exponent_bias
    = math_utilities::pow2(number<NumExponentBits, int> - 1) - 1;

  auto const exponent = static_cast<int>(exponent_part) - exponent_bias;

  static constexpr auto mantissa_fraction_denominator
    = math_utilities::pow2(number<NumMantissaBits, Rep>);

  auto const mantissa_fraction_numerator = static_cast<Rep>(mantissa_part);

  auto const mantissa_fraction = fraction<Rep, Ops>(
    mantissa_fraction_numerator, mantissa_fraction_denominator);

  auto const mantissa = _1<Rep> + mantissa_fraction;

  return sign * mantissa * pow2<Rep, Ops>(exponent);
}

template <typename Float, typename Rep, typename Ops>
constexpr Float
fraction_to_floating_point(fraction<Rep, Ops> const& value) noexcept
{
  auto const reduced = reduce(value);

  return static_cast<Float>(reduced.num()) / static_cast<Float>(reduced.den());
}


}; // namespace ieme


#endif
