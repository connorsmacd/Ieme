#ifndef IEME_RAW_FRACTION_MATH_HPP
#define IEME_RAW_FRACTION_MATH_HPP

#include <ieme/raw_fraction.hpp>

#include <numeric>


namespace ieme {


template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_ignore_signs(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep> reduce(const raw_fraction<Rep>& value) noexcept;


// =============================================================================


template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(const raw_fraction<Rep>& value) noexcept
{
  return {value.denominator, value.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_ignore_signs(const raw_fraction<Rep>& value) noexcept
{
  if (is_undefined(value))
    return {Rep(0), Rep(0)};

  const auto gcd = std::gcd(value.numerator, value.denominator);

  return {value.numerator / gcd, value.denominator / gcd};
}

template <typename Rep>
constexpr raw_fraction<Rep> reduce(const raw_fraction<Rep>& value) noexcept
{
  const auto reduced_signs_ignored = reduce_ignore_signs(value);

  return (reduced_signs_ignored.numerator > 0
          || reduced_signs_ignored.denominator > 0)
           ? reduced_signs_ignored
           : raw_fraction<Rep> {-reduced_signs_ignored.numerator,
                                -reduced_signs_ignored.denominator};
}


}; // namespace ieme


#endif
