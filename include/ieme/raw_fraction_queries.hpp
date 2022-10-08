#ifndef IEME_RAW_FRACTION_QUERIES_HPP
#define IEME_RAW_FRACTION_QUERIES_HPP

#include <ieme/math_utilities.hpp>
#include <ieme/raw_fraction.hpp>

#include <numeric>


namespace ieme {


template <typename Rep>
constexpr bool is_defined(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_undefined(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_positive(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_non_negative(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_zero(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_non_positive(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_negative(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_integer(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_unit_fraction(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_reduced_ignore_signs(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_reduced(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_proper(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool is_improper(raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
constexpr bool are_identical(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right);

template <typename Rep>
constexpr bool are_different(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right);


// =============================================================================


template <typename Rep>
constexpr bool is_defined(raw_fraction<Rep> const& value) noexcept
{
  return value.denominator != Rep(0);
}

template <typename Rep>
constexpr bool is_undefined(raw_fraction<Rep> const& value) noexcept
{
  return !is_defined(value);
}

template <typename Rep>
constexpr bool is_positive(raw_fraction<Rep> const& value) noexcept
{
  return (value.numerator > Rep(0) && value.denominator > Rep(0))
         || (value.numerator < Rep(0) && value.denominator < Rep(0));
}

template <typename Rep>
constexpr bool is_non_negative(raw_fraction<Rep> const& value) noexcept
{
  return (value.numerator >= Rep(0) && value.denominator > Rep(0))
         || (value.numerator <= Rep(0) && value.denominator < Rep(0));
}

template <typename Rep>
constexpr bool is_zero(raw_fraction<Rep> const& value) noexcept
{
  return is_defined(value) && value.numerator == Rep(0);
}

template <typename Rep>
constexpr bool is_non_positive(raw_fraction<Rep> const& value) noexcept
{
  return (value.numerator >= Rep(0) && value.denominator < Rep(0))
         || (value.numerator <= Rep(0) && value.denominator > Rep(0));
}

template <typename Rep>
constexpr bool is_negative(raw_fraction<Rep> const& value) noexcept
{
  return (value.numerator > Rep(0) && value.denominator < Rep(0))
         || (value.numerator < Rep(0) && value.denominator > Rep(0));
}

template <typename Rep>
constexpr bool is_integer(raw_fraction<Rep> const& value) noexcept
{
  return is_defined(value) && value.numerator % value.denominator == Rep(0);
}

template <typename Rep>
constexpr bool is_unit_fraction(raw_fraction<Rep> const& value) noexcept
{
  return is_defined(value) && value.numerator != Rep(0)
         && value.denominator % value.numerator == Rep(0);
}

template <typename Rep>
constexpr bool is_reduced_ignore_signs(raw_fraction<Rep> const& value) noexcept
{
  return is_defined(value)
         && std::gcd(value.numerator, value.denominator) == Rep(1);
}

template <typename Rep>
constexpr bool is_reduced(raw_fraction<Rep> const& value) noexcept
{
  return (value.numerator > Rep(0) || value.denominator > Rep(0))
         && is_reduced_ignore_signs(value);
}

template <typename Rep>
constexpr bool is_proper(raw_fraction<Rep> const& value) noexcept
{
  return math_utilities::abs(value.numerator)
         < math_utilities::abs(value.denominator);
}

template <typename Rep>
constexpr bool is_improper(raw_fraction<Rep> const& value) noexcept
{
  return !is_proper(value);
}

template <typename Rep>
constexpr bool are_identical(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right)
{
  return left.numerator == right.numerator
         && left.denominator == right.denominator;
}

template <typename Rep>
constexpr bool are_different(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right)
{
  return !are_identical(left, right);
}


}; // namespace ieme


#endif
