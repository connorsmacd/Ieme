#ifndef IEME_RAW_FRACTION_HPP
#define IEME_RAW_FRACTION_HPP

#include <numeric>


namespace ieme {


template <typename Rep>
struct raw_fraction {
  using rep_type = Rep;
  Rep numerator = {}, denominator = {};
};

template <typename Rep>
constexpr raw_fraction<Rep> reduce(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_positive(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_negative(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_zero(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_integer(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_unit_fraction(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_defined(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr bool is_undefined(const raw_fraction<Rep>& value) noexcept;


// =============================================================================


template <typename Rep>
constexpr raw_fraction<Rep> reduce(const raw_fraction<Rep>& value) noexcept
{
  const auto gcd = std::gcd(value.numerator, value.denominator);

  const auto gcd_with_sign
    = (value.numerator < 0 && value.denominator < 0) ? -gcd : gcd;

  return {value.numerator / gcd_with_sign, value.denominator / gcd_with_sign};
}

template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(const raw_fraction<Rep>& value) noexcept
{
  return {value.denominator, value.numerator};
}

template <typename Rep>
constexpr bool is_positive(const raw_fraction<Rep>& value) noexcept
{
  return (value.numerator > 0 && value.denominator > 0)
         || (value.numerator < 0 && value.denominator < 0);
}

template <typename Rep>
constexpr bool is_negative(const raw_fraction<Rep>& value) noexcept
{
  return (value.numerator > 0 && value.denominator < 0)
         || (value.numerator < 0 && value.denominator > 0);
}

template <typename Rep>
constexpr bool is_zero(const raw_fraction<Rep>& value) noexcept
{
  return is_defined(value) && value.numerator == 0;
}

template <typename Rep>
constexpr bool is_integer(const raw_fraction<Rep>& value) noexcept
{
  return is_defined(value) && value.numerator % value.denominator == 0;
}

template <typename Rep>
constexpr bool is_unit_fraction(const raw_fraction<Rep>& value) noexcept
{
  return is_integer(reciprocal(value));
}

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


}; // namespace ieme


#endif
