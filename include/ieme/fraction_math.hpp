#ifndef IEME_FRACTION_MATH_HPP
#define IEME_FRACTION_MATH_HPP

#include <ieme/fraction.hpp>
#include <ieme/fraction_queries.hpp>
#include <ieme/math_utilities.hpp>
#include <ieme/raw_fraction_math.hpp>
#include <ieme/reduce_mode.hpp>


namespace ieme {


enum class round_mode { trunc, ceil, floor, round };


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reciprocal(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
normalize_signs(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> reduce(const fraction<Rep, Ops>& value,
                                    reduce_mode mode
                                    = reduce_mode::normalize_signs) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_normalize_signs(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_ignore_signs(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> abs(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep to_whole(const fraction<Rep, Ops>& value,
                       round_mode mode = round_mode::round) noexcept;

template <typename Rep, typename Ops>
constexpr Rep trunc(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep ceil(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep floor(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep round(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> redenominate(const fraction<Rep, Ops>& value,
                                          const Rep& new_denominator,
                                          round_mode mode
                                          = round_mode::round) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
trunc_redenominate(const fraction<Rep, Ops>& value,
                   const Rep& new_denominator) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
ceil_redenominate(const fraction<Rep, Ops>& value,
                  const Rep& new_denominator) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
floor_redenominate(const fraction<Rep, Ops>& value,
                   const Rep& new_denominator) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
round_redenominate(const fraction<Rep, Ops>& value,
                   const Rep& new_denominator) noexcept;

template <typename Rep, typename Ops = ops::defaults>
constexpr fraction<Rep, Ops> pow2(int exponent) noexcept;

template <typename Rep, typename Ops = ops::defaults>
constexpr fraction<Rep, Ops> pow(const Rep& base, int exponent) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reciprocal(const fraction<Rep, Ops>& value) noexcept
{
  return reciprocal(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
normalize_signs(const fraction<Rep, Ops>& value) noexcept
{
  return normalize_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> reduce(const fraction<Rep, Ops>& value,
                                    const reduce_mode mode) noexcept
{
  return reduce(value.raw(), mode);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_normalize_signs(const fraction<Rep, Ops>& value) noexcept
{
  return reduce_normalize_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_ignore_signs(const fraction<Rep, Ops>& value) noexcept
{
  return reduce_ignore_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> abs(const fraction<Rep, Ops>& value) noexcept
{
  return is_non_negative(value) ? value : -value;
}

template <typename Rep, typename Ops>
constexpr Rep to_whole(const fraction<Rep, Ops>& value,
                       const round_mode mode) noexcept
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
constexpr Rep trunc(const fraction<Rep, Ops>& value) noexcept
{
  return value.numerator() / value.denominator();
}

template <typename Rep, typename Ops>
constexpr Rep ceil(const fraction<Rep, Ops>& value) noexcept
{
  const auto truncated = trunc(value);

  return (is_integer(value) || truncated < Rep(0)) ? truncated
                                                   : truncated + Rep(1);
}

template <typename Rep, typename Ops>
constexpr Rep floor(const fraction<Rep, Ops>& value) noexcept
{
  const auto truncated = trunc(value);

  return (is_integer(value) || truncated >= Rep(0)) ? truncated
                                                    : truncated - Rep(1);
}

template <typename Rep, typename Ops>
constexpr Rep round(const fraction<Rep, Ops>& value) noexcept
{
  const auto floored = floor(value);

  return (value - floored < fraction<Rep, Ops>(Rep(1), Rep(2)))
           ? floored
           : floored + Rep(1);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> redenominate(const fraction<Rep, Ops>& value,
                                          const Rep& new_denominator,
                                          const round_mode mode) noexcept
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
constexpr fraction<Rep, Ops> trunc_redenominate(const fraction<Rep, Ops>& value,
                                                const Rep& denominator) noexcept
{
  return {trunc(value * denominator), denominator};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> ceil_redenominate(const fraction<Rep, Ops>& value,
                                               const Rep& denominator) noexcept
{
  return {(denominator >= Rep(0)) ? ceil(value * denominator)
                                  : -ceil(value * -denominator),
          denominator};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> floor_redenominate(const fraction<Rep, Ops>& value,
                                                const Rep& denominator) noexcept
{
  return {(denominator >= Rep(0)) ? floor(value * denominator)
                                  : -floor(value * -denominator),
          denominator};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> round_redenominate(const fraction<Rep, Ops>& value,
                                                const Rep& denominator) noexcept
{
  return {round(value * denominator), denominator};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> pow2(const int exponent) noexcept
{
  return (exponent >= 0)
           ? fraction<Rep, Ops>(math_utilities::pow2(Rep(exponent)))
           : fraction<Rep, Ops>(Rep(1), math_utilities::pow2(Rep(-exponent)));
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> pow(const Rep& base, const int exponent) noexcept
{
  return (exponent >= 0)
           ? fraction<Rep, Ops>(math_utilities::pow(base, Rep(exponent)))
           : fraction<Rep, Ops>(Rep(1),
                                math_utilities::pow(base, Rep(-exponent)));
}


}; // namespace ieme


#endif
