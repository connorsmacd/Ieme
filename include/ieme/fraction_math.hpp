#ifndef IEME_FRACTION_MATH_HPP
#define IEME_FRACTION_MATH_HPP

#include <ieme/fraction.hpp>
#include <ieme/fraction_queries.hpp>
#include <ieme/math_utilities.hpp>
#include <ieme/numbers.hpp>
#include <ieme/raw_fraction_math.hpp>
#include <ieme/reduce_mode.hpp>


namespace ieme {


enum class round_mode { trunc, ceil, floor, round };


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reciprocal(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
normalize_signs(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> reduce(fraction<Rep, Ops> const& value,
                                    reduce_mode mode
                                    = reduce_mode::normalize_signs) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_normalize_signs(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_ignore_signs(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> abs(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep to_whole(fraction<Rep, Ops> const& value,
                       round_mode mode = round_mode::round) noexcept;

template <typename Rep, typename Ops>
constexpr Rep trunc(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep ceil(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep floor(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep round(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> redenominate(fraction<Rep, Ops> const& value,
                                          Rep const& new_denominator,
                                          round_mode mode
                                          = round_mode::round) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
trunc_redenominate(fraction<Rep, Ops> const& value,
                   Rep const& new_denominator) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
ceil_redenominate(fraction<Rep, Ops> const& value,
                  Rep const& new_denominator) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
floor_redenominate(fraction<Rep, Ops> const& value,
                   Rep const& new_denominator) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
round_redenominate(fraction<Rep, Ops> const& value,
                   Rep const& new_denominator) noexcept;

template <typename Rep, typename Ops = ops::defaults>
constexpr fraction<Rep, Ops> pow2(int exponent) noexcept;

template <typename Rep, typename Ops = ops::defaults>
constexpr fraction<Rep, Ops> pow(Rep const& base, int exponent) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reciprocal(fraction<Rep, Ops> const& value) noexcept
{
  return reciprocal(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
normalize_signs(fraction<Rep, Ops> const& value) noexcept
{
  return normalize_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> reduce(fraction<Rep, Ops> const& value,
                                    reduce_mode const mode) noexcept
{
  return reduce(value.raw(), mode);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_normalize_signs(fraction<Rep, Ops> const& value) noexcept
{
  return reduce_normalize_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_ignore_signs(fraction<Rep, Ops> const& value) noexcept
{
  return reduce_ignore_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> abs(fraction<Rep, Ops> const& value) noexcept
{
  return is_non_negative(value) ? value : -value;
}

template <typename Rep, typename Ops>
constexpr Rep to_whole(fraction<Rep, Ops> const& value,
                       round_mode const mode) noexcept
{
  switch (mode)
  {
    case round_mode::trunc:
      return trunc(value);
    case round_mode::ceil:
      return ceil(value);
    case round_mode::floor:
      return floor(value);
    case round_mode::round:
      return round(value);
  }

  return to_whole(value);
}

template <typename Rep, typename Ops>
constexpr Rep trunc(fraction<Rep, Ops> const& value) noexcept
{
  return value.numerator() / value.denominator();
}

template <typename Rep, typename Ops>
constexpr Rep ceil(fraction<Rep, Ops> const& value) noexcept
{
  auto const truncated = trunc(value);

  return (is_integer(value) || truncated < _0<Rep>) ? truncated
                                                    : truncated + _1<Rep>;
}

template <typename Rep, typename Ops>
constexpr Rep floor(fraction<Rep, Ops> const& value) noexcept
{
  auto const truncated = trunc(value);

  return (is_integer(value) || truncated >= _0<Rep>) ? truncated
                                                     : truncated - _1<Rep>;
}

template <typename Rep, typename Ops>
constexpr Rep round(fraction<Rep, Ops> const& value) noexcept
{
  auto const floored = floor(value);

  return (value - floored < fraction<Rep, Ops>(_1<Rep>, _2<Rep>))
           ? floored
           : floored + _1<Rep>;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> redenominate(fraction<Rep, Ops> const& value,
                                          Rep const& new_denominator,
                                          round_mode const mode) noexcept
{
  switch (mode)
  {
    case round_mode::trunc:
      return trunc_redenominate(value, new_denominator);
    case round_mode::ceil:
      return ceil_redenominate(value, new_denominator);
    case round_mode::floor:
      return floor_redenominate(value, new_denominator);
    case round_mode::round:
      return round_redenominate(value, new_denominator);
  }

  return redenominate(value, new_denominator);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> trunc_redenominate(fraction<Rep, Ops> const& value,
                                                Rep const& denominator) noexcept
{
  return {trunc(value * denominator), denominator};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> ceil_redenominate(fraction<Rep, Ops> const& value,
                                               Rep const& denominator) noexcept
{
  return {(denominator >= _0<Rep>) ? ceil(value * denominator)
                                   : -ceil(value * -denominator),
          denominator};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> floor_redenominate(fraction<Rep, Ops> const& value,
                                                Rep const& denominator) noexcept
{
  return {(denominator >= _0<Rep>) ? floor(value * denominator)
                                   : -floor(value * -denominator),
          denominator};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> round_redenominate(fraction<Rep, Ops> const& value,
                                                Rep const& denominator) noexcept
{
  return {round(value * denominator), denominator};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> pow2(int const exponent) noexcept
{
  return (exponent >= 0)
           ? fraction<Rep, Ops>(math_utilities::pow2(Rep(exponent)))
           : fraction<Rep, Ops>(_1<Rep>, math_utilities::pow2(Rep(-exponent)));
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> pow(Rep const& base, int const exponent) noexcept
{
  return (exponent >= 0)
           ? fraction<Rep, Ops>(math_utilities::pow(base, Rep(exponent)))
           : fraction<Rep, Ops>(_1<Rep>,
                                math_utilities::pow(base, Rep(-exponent)));
}


}; // namespace ieme


#endif
