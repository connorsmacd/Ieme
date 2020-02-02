#ifndef IEME_FRACTION_QUERIES_HPP
#define IEME_FRACTION_QUERIES_HPP

#include <ieme/fraction.hpp>
#include <ieme/raw_fraction_math.hpp>


namespace ieme {


template <typename Rep, typename Ops>
constexpr bool is_defined(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_undefined(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_positive(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_non_negative(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_zero(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_non_positive(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_negative(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_integer(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_unit_fraction(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool
is_reduced_ignore_signs(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_reduced(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_proper(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_improper(const fraction<Rep, Ops>& value) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr bool is_defined(const fraction<Rep, Ops>& value) noexcept
{
  return is_defined(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_undefined(const fraction<Rep, Ops>& value) noexcept
{
  return is_undefined(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_positive(const fraction<Rep, Ops>& value) noexcept
{
  return is_positive(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_non_negative(const fraction<Rep, Ops>& value) noexcept
{
  return is_non_negative(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_zero(const fraction<Rep, Ops>& value) noexcept
{
  return is_zero(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_non_positive(const fraction<Rep, Ops>& value) noexcept
{
  return is_non_positive(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_negative(const fraction<Rep, Ops>& value) noexcept
{
  return is_negative(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_integer(const fraction<Rep, Ops>& value) noexcept
{
  return is_integer(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_unit_fraction(const fraction<Rep, Ops>& value) noexcept
{
  return is_unit_fraction(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_reduced_ignore_signs(const fraction<Rep, Ops>& value) noexcept
{
  return is_reduced_ignore_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_reduced(const fraction<Rep, Ops>& value) noexcept
{
  return is_reduced(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_proper(const fraction<Rep, Ops>& value) noexcept
{
  return is_proper(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_improper(const fraction<Rep, Ops>& value) noexcept
{
  return is_improper(value.raw());
}


}; // namespace ieme


#endif
