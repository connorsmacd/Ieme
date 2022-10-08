#ifndef IEME_FRACTION_QUERIES_HPP
#define IEME_FRACTION_QUERIES_HPP

#include <ieme/fraction.hpp>
#include <ieme/raw_fraction_math.hpp>


namespace ieme {


template <typename Rep, typename Ops>
constexpr bool is_defined(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_undefined(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_positive(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_non_negative(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_zero(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_non_positive(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_negative(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_integer(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_unit_fraction(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool
is_reduced_ignore_signs(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_reduced(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_proper(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_improper(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename LeftOps, typename RightOps>
constexpr bool are_identical(const fraction<Rep, LeftOps>& left,
                             const fraction<Rep, RightOps>& right) noexcept;

template <typename Rep, typename LeftOps, typename RightOps>
constexpr bool are_different(const fraction<Rep, LeftOps>& left,
                             const fraction<Rep, RightOps>& right) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr bool is_defined(fraction<Rep, Ops> const& value) noexcept
{
  return is_defined(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_undefined(fraction<Rep, Ops> const& value) noexcept
{
  return is_undefined(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_positive(fraction<Rep, Ops> const& value) noexcept
{
  return is_positive(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_non_negative(fraction<Rep, Ops> const& value) noexcept
{
  return is_non_negative(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_zero(fraction<Rep, Ops> const& value) noexcept
{
  return is_zero(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_non_positive(fraction<Rep, Ops> const& value) noexcept
{
  return is_non_positive(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_negative(fraction<Rep, Ops> const& value) noexcept
{
  return is_negative(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_integer(fraction<Rep, Ops> const& value) noexcept
{
  return is_integer(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_unit_fraction(fraction<Rep, Ops> const& value) noexcept
{
  return is_unit_fraction(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_reduced_ignore_signs(fraction<Rep, Ops> const& value) noexcept
{
  return is_reduced_ignore_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_reduced(fraction<Rep, Ops> const& value) noexcept
{
  return is_reduced(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_proper(fraction<Rep, Ops> const& value) noexcept
{
  return is_proper(value.raw());
}

template <typename Rep, typename Ops>
constexpr bool is_improper(fraction<Rep, Ops> const& value) noexcept
{
  return is_improper(value.raw());
}

template <typename Rep, typename LeftOps, typename RightOps>
constexpr bool are_identical(const fraction<Rep, LeftOps>& left,
                             const fraction<Rep, RightOps>& right) noexcept
{
  return are_identical(left.raw(), right.raw());
}

template <typename Rep, typename LeftOps, typename RightOps>
constexpr bool are_different(const fraction<Rep, LeftOps>& left,
                             const fraction<Rep, RightOps>& right) noexcept
{
  return are_different(left.raw(), right.raw());
}


}; // namespace ieme


#endif
