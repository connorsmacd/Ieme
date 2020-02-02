#ifndef IEME_FRACTION_MATH_HPP
#define IEME_FRACTION_MATH_HPP

#include <ieme/fraction.hpp>
#include <ieme/fraction_queries.hpp>


namespace ieme {


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reciprocal(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_ignore_signs(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> reduce(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> abs(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep trunc(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep ceil(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep floor(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep round(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops = ops::defaults>
constexpr fraction<Rep, Ops> pow2(const Rep& exponent) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reciprocal(const fraction<Rep, Ops>& value) noexcept
{
  return reciprocal(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reduce_ignore_signs(const fraction<Rep, Ops>& value) noexcept
{
  return reduce_ignore_signs(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> reduce(const fraction<Rep, Ops>& value) noexcept
{
  return reduce(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> abs(const fraction<Rep, Ops>& value) noexcept
{
  return is_positive(value) ? value : -value;
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

  return (is_integer(value) || truncated < 0) ? truncated : truncated + 1;
}

template <typename Rep, typename Ops>
constexpr Rep floor(const fraction<Rep, Ops>& value) noexcept
{
  const auto truncated = trunc(value);

  return (is_integer(value) || truncated >= 0) ? truncated : truncated - 1;
}

template <typename Rep, typename Ops>
constexpr Rep round(const fraction<Rep, Ops>& value) noexcept
{
  const auto floored = floor(value);

  return (value - floored < fraction<Rep, Ops>(1, 2)) ? floored : floored + 1;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> pow2(const Rep& exponent) noexcept
{
  const auto constexpr_pow2 = [=](const Rep& exponent) {
    using unsigned_type = std::make_unsigned_t<Rep>;
    return Rep(unsigned_type(1) << unsigned_type(exponent));
  };

  return (exponent >= 0) ? fraction<Rep, Ops>(constexpr_pow2(exponent))
                         : fraction<Rep, Ops>(1, constexpr_pow2(-exponent));
}


}; // namespace ieme


#endif
