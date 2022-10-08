#ifndef IEME_RAW_FRACTION_MATH_HPP
#define IEME_RAW_FRACTION_MATH_HPP

#include <ieme/raw_fraction.hpp>
#include <ieme/reduce_mode.hpp>

#include <numeric>


namespace ieme {


template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
normalize_signs(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep> reduce(raw_fraction<Rep> const& value,
                                   reduce_mode mode
                                   = reduce_mode::normalize_signs) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_normalize_signs(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_ignore_signs(raw_fraction<Rep> const& value) noexcept;


// =============================================================================


template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(raw_fraction<Rep> const& value) noexcept
{
  return {value.denominator, value.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
normalize_signs(raw_fraction<Rep> const& value) noexcept
{
  return (value.denominator > Rep(0))
           ? value
           : raw_fraction<Rep>(-value.numerator, -value.denominator);
}

template <typename Rep>
constexpr raw_fraction<Rep> reduce(raw_fraction<Rep> const& value,
                                   reduce_mode const mode) noexcept
{
  switch (mode)
  {
    case reduce_mode::normalize_signs:
      return reduce_normalize_signs(value);
    case reduce_mode::ignore_signs:
      return reduce_ignore_signs(value);
  }

  return {Rep(0), Rep(0)};
}

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_normalize_signs(raw_fraction<Rep> const& value) noexcept
{
  return normalize_signs(reduce_ignore_signs(value));
}

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_ignore_signs(raw_fraction<Rep> const& value) noexcept
{
  if (is_undefined(value))
    return {Rep(0), Rep(0)};

  auto const gcd = std::gcd(value.numerator, value.denominator);

  return {value.numerator / gcd, value.denominator / gcd};
}


}; // namespace ieme


#endif
