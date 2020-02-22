#ifndef IEME_RAW_FRACTION_MATH_HPP
#define IEME_RAW_FRACTION_MATH_HPP

#include <ieme/raw_fraction.hpp>

#include <numeric>


namespace ieme {


enum class reduce_type { ignore_signs, cancel_signs, normalize_signs };


template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
cancel_signs(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
normalize_signs(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep> reduce(const raw_fraction<Rep>& value,
                                   reduce_type reduce_type
                                   = reduce_type::normalize_signs) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_ignore_signs(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_cancel_signs(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_normalize_signs(const raw_fraction<Rep>& value) noexcept;


// =============================================================================


template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(const raw_fraction<Rep>& value) noexcept
{
  return {value.denominator, value.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
cancel_signs(const raw_fraction<Rep>& value) noexcept
{
  return (value.numerator > 0 || value.denominator > 0)
           ? value
           : raw_fraction<Rep>(-value.numerator, -value.denominator);
}

template <typename Rep>
constexpr raw_fraction<Rep>
normalize_signs(const raw_fraction<Rep>& value) noexcept
{
  return (value.denominator > 0)
           ? value
           : raw_fraction<Rep>(-value.numerator, -value.denominator);
}

template <typename Rep>
constexpr raw_fraction<Rep> reduce(const raw_fraction<Rep>& value,
                                   const reduce_type reduce_type) noexcept
{
  switch (reduce_type)
  {
    case reduce_type::ignore_signs:
      return reduce_ignore_signs(value);
    case reduce_type::cancel_signs:
      return reduce_cancel_signs(value);
    case reduce_type::normalize_signs:
      return reduce_normalize_signs(value);
  }

  return {Rep(0), Rep(0)};
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
constexpr raw_fraction<Rep>
reduce_cancel_signs(const raw_fraction<Rep>& value) noexcept
{
  return cancel_signs(reduce_ignore_signs(value));
}

template <typename Rep>
constexpr raw_fraction<Rep>
reduce_normalize_signs(const raw_fraction<Rep>& value) noexcept
{
  return normalize_signs(reduce_ignore_signs(value));
}


}; // namespace ieme


#endif
