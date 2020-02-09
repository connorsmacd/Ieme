#ifndef IEME_RAW_FRACTION_QUERIES_HPP
#define IEME_RAW_FRACTION_QUERIES_HPP

#include <ieme/math_utilities.hpp>
#include <ieme/raw_fraction.hpp>

#include <numeric>


namespace ieme {


template <typename Rep>
constexpr bool is_defined(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_undefined(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_positive(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_non_negative(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_zero(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_non_positive(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_negative(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_integer(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_unit_fraction(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_reduced_ignore_signs(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_reduced(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_proper(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_improper(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool are_identical(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right);

template <typename Rep>
constexpr bool are_different(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right);


// =============================================================================


template <typename Rep>
constexpr bool is_defined(const raw_fraction<Rep>& value) noexcept
{
  return value.denominator != 0;
}

template <typename Rep>
constexpr bool is_undefined(const raw_fraction<Rep>& value) noexcept
{
  return !is_defined(value);
}

template <typename Rep>
constexpr bool is_positive(const raw_fraction<Rep>& value) noexcept
{
  return (value.numerator > 0 && value.denominator > 0)
         || (value.numerator < 0 && value.denominator < 0);
}

template <typename Rep>
constexpr bool is_non_negative(const raw_fraction<Rep>& value) noexcept
{
  return (value.numerator >= 0 && value.denominator > 0)
         || (value.numerator <= 0 && value.denominator < 0);
}

template <typename Rep>
constexpr bool is_zero(const raw_fraction<Rep>& value) noexcept
{
  return is_defined(value) && value.numerator == 0;
}

template <typename Rep>
constexpr bool is_non_positive(const raw_fraction<Rep>& value) noexcept
{
  return (value.numerator >= 0 && value.denominator < 0)
         || (value.numerator <= 0 && value.denominator > 0);
}

template <typename Rep>
constexpr bool is_negative(const raw_fraction<Rep>& value) noexcept
{
  return (value.numerator > 0 && value.denominator < 0)
         || (value.numerator < 0 && value.denominator > 0);
}

template <typename Rep>
constexpr bool is_integer(const raw_fraction<Rep>& value) noexcept
{
  return is_defined(value) && value.numerator % value.denominator == 0;
}

template <typename Rep>
constexpr bool is_unit_fraction(const raw_fraction<Rep>& value) noexcept
{
  return is_defined(value) && value.numerator != 0
         && value.denominator % value.numerator == 0;
}

template <typename Rep>
constexpr bool is_reduced_ignore_signs(const raw_fraction<Rep>& value) noexcept
{
  return is_defined(value) && std::gcd(value.numerator, value.denominator) == 1;
}

template <typename Rep>
constexpr bool is_reduced(const raw_fraction<Rep>& value) noexcept
{
  return (value.numerator > 0 || value.denominator > 0)
         && is_reduced_ignore_signs(value);
}

template <typename Rep>
constexpr bool is_proper(const raw_fraction<Rep>& value) noexcept
{
  return math_utilities::abs(value.numerator)
         < math_utilities::abs(value.denominator);
}

template <typename Rep>
constexpr bool is_improper(const raw_fraction<Rep>& value) noexcept
{
  return !is_proper(value);
}

template <typename Rep>
constexpr bool are_identical(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right)
{
  return left.numerator == right.numerator
         && left.denominator == right.denominator;
}

template <typename Rep>
constexpr bool are_different(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right)
{
  return !are_identical(left, right);
}


}; // namespace ieme


#endif
