#ifndef IEME_OPS_HPP
#define IEME_OPS_HPP

#include <ieme/raw_fraction.hpp>
#include <ieme/raw_fraction_math.hpp>
#include <ieme/raw_fraction_queries.hpp>

#define IEME_DEFAULT_OPS_FALLBACK safe_reduced_io


namespace ieme {
namespace ops {


class safe {

public:
  ~safe() = delete;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(const raw_fraction<Rep>& value) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> plus(const raw_fraction<Rep>& left,
                                          const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> minus(const raw_fraction<Rep>& left,
                                           const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const raw_fraction<Rep>& left,
             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> multiplies(const raw_fraction<Rep>& left,
                                                const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> divides(const raw_fraction<Rep>& left,
                                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> modulus(const raw_fraction<Rep>& left,
                                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const Rep& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const Rep& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const Rep& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const Rep& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const Rep& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const Rep& left,
                                      const raw_fraction<Rep>& right) noexcept;
};


class fast {

public:
  ~fast() = delete;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(const raw_fraction<Rep>& value) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> plus(const raw_fraction<Rep>& left,
                                          const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> minus(const raw_fraction<Rep>& left,
                                           const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const raw_fraction<Rep>& left,
             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> multiplies(const raw_fraction<Rep>& left,
                                                const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> divides(const raw_fraction<Rep>& left,
                                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> modulus(const raw_fraction<Rep>& left,
                                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const Rep& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const Rep& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const Rep& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const Rep& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const Rep& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const Rep& left,
                                      const raw_fraction<Rep>& right) noexcept;
};


template <typename Ops, reduce_mode Mode = reduce_mode::ignore_signs>
class reduced_input {

public:
  using ops_type = Ops;

  static constexpr reduce_mode mode = Mode;

  ~reduced_input() = delete;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(const raw_fraction<Rep>& value) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> plus(const raw_fraction<Rep>& left,
                                          const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> minus(const raw_fraction<Rep>& left,
                                           const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const raw_fraction<Rep>& left,
             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> multiplies(const raw_fraction<Rep>& left,
                                                const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> divides(const raw_fraction<Rep>& left,
                                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> modulus(const raw_fraction<Rep>& left,
                                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const Rep& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const Rep& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const Rep& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const Rep& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const Rep& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const Rep& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const Rep& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const Rep& left,
                                      const raw_fraction<Rep>& right) noexcept;
};


template <typename Ops, reduce_mode Mode = reduce_mode::normalize_signs>
class reduced_output {

public:
  using ops_type = Ops;

  static constexpr reduce_mode mode = Mode;

  ~reduced_output() = delete;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(const raw_fraction<Rep>& value) noexcept;

  template <typename Left, typename Right>
  static constexpr auto plus(const Left& left, const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr auto minus(const Left& left, const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr auto multiplies(const Left& left,
                                   const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr auto divides(const Left& left, const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr auto modulus(const Left& left, const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool equal_to(const Left& left, const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool not_equal_to(const Left& left,
                                     const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool less(const Left& left, const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool less_equal(const Left& left,
                                   const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool greater(const Left& left, const Right& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool greater_equal(const Left& left,
                                      const Right& right) noexcept;
};


using safe_reduced_i = reduced_input<safe>;
using safe_reduced_o = reduced_output<safe>;
using safe_reduced_io = reduced_input<safe_reduced_o>;
using fast_reduced_i = reduced_input<fast>;
using fast_reduced_o = reduced_output<fast>;
using fast_reduced_io = reduced_input<fast_reduced_o>;

#if defined(IEME_DEFAULT_OPS_SAFE)
using defaults = safe;
#elif defined(IEME_DEFAULT_OPS_SAFE_REDUCED_I)
using defaults = safe_reduced_i;
#elif defined(IEME_DEFAULT_OPS_SAFE_REDUCED_O)
using defaults = safe_reduced_o;
#elif defined(IEME_DEFAULT_OPS_SAFE_REDUCED_IO)
using defaults = safe_reduced_io;
#elif defined(IEME_DEFAULT_OPS_FAST)
using defaults = fast;
#elif defined(IEME_DEFAULT_OPS_FAST_REDUCED_I)
using defaults = fast_reduced_i;
#elif defined(IEME_DEFAULT_OPS_FAST_REDUCED_O)
using defaults = fast_reduced_o;
#elif defined(IEME_DEFAULT_OPS_FAST_REDUCED_IO)
using defaults = fast_reduced_io;
#else
using defaults = IEME_DEFAULT_OPS_FALLBACK;
#endif


// =============================================================================


template <typename Rep>
constexpr raw_fraction<Rep>
safe::negate(const raw_fraction<Rep>& value) noexcept
{
  return {-value.numerator, value.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::plus(const raw_fraction<Rep>& left,
                                       const raw_fraction<Rep>& right) noexcept
{
  const auto lcm = std::lcm(left.denominator, right.denominator);

  return {lcm / left.denominator * left.numerator
            + lcm / right.denominator * right.numerator,
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::plus(const raw_fraction<Rep>& left,
                                       const Rep& right) noexcept
{
  return {left.numerator + right * left.denominator, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::plus(const Rep& left,
                                       const raw_fraction<Rep>& right) noexcept
{
  return plus(right, left);
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::minus(const raw_fraction<Rep>& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  const auto lcm = std::lcm(left.denominator, right.denominator);

  return {lcm / left.denominator * left.numerator
            - lcm / right.denominator * right.numerator,
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::minus(const raw_fraction<Rep>& left,
                                        const Rep& right) noexcept
{
  return {left.numerator - right * left.denominator, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::minus(const Rep& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return {left * right.denominator - right.numerator, right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::multiplies(const raw_fraction<Rep>& left,
                 const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator * right.numerator,
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::multiplies(const raw_fraction<Rep>& left,
                                             const Rep& right) noexcept
{
  return {left.numerator * right, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::multiplies(const Rep& left, const raw_fraction<Rep>& right) noexcept
{
  return multiplies(right, left);
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::divides(const raw_fraction<Rep>& left,
              const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator * right.denominator,
          left.denominator * right.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::divides(const raw_fraction<Rep>& left,
                                          const Rep& right) noexcept
{
  return {left.numerator, left.denominator * right};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::divides(const Rep& left, const raw_fraction<Rep>& right) noexcept
{
  return {left * right.denominator, right.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::modulus(const raw_fraction<Rep>& left,
              const raw_fraction<Rep>& right) noexcept
{
  const auto lcm = std::lcm(left.denominator, right.denominator);

  return {(lcm / left.denominator * left.numerator)
            % (lcm / right.denominator * right.numerator),
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::modulus(const raw_fraction<Rep>& left,
                                          const Rep& right) noexcept
{
  return {left.numerator % (left.denominator * right), left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::modulus(const Rep& left, const raw_fraction<Rep>& right) noexcept
{
  return {(right.denominator * left) % right.numerator, right.denominator};
}

template <typename Rep>
constexpr bool safe::equal_to(const raw_fraction<Rep>& left,
                              const raw_fraction<Rep>& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  const auto lcm = std::lcm(left.denominator, right.denominator);

  return lcm / left.denominator * left.numerator
         == lcm / right.denominator * right.numerator;
}

template <typename Rep>
constexpr bool safe::equal_to(const raw_fraction<Rep>& left,
                              const Rep& right) noexcept
{
  return left.numerator == right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool safe::equal_to(const Rep& left,
                              const raw_fraction<Rep>& right) noexcept
{
  return equal_to(right, left);
}

template <typename Rep>
constexpr bool safe::not_equal_to(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool safe::not_equal_to(const raw_fraction<Rep>& left,
                                  const Rep& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool safe::not_equal_to(const Rep& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return not_equal_to(right, left);
}

template <typename Rep>
constexpr bool safe::less(const raw_fraction<Rep>& left,
                          const raw_fraction<Rep>& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  const auto lcm = std::lcm(left.denominator, right.denominator);

  return lcm / left.denominator * left.numerator
         < lcm / right.denominator * right.numerator;
}

template <typename Rep>
constexpr bool safe::less(const raw_fraction<Rep>& left,
                          const Rep& right) noexcept
{
  return left.numerator < right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool safe::less(const Rep& left,
                          const raw_fraction<Rep>& right) noexcept
{
  return left * right.denominator < right.numerator && is_defined(right);
}

template <typename Rep>
constexpr bool safe::less_equal(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  const auto lcm = std::lcm(left.denominator, right.denominator);

  return lcm / left.denominator * left.numerator
         <= lcm / right.denominator * right.numerator;
}

template <typename Rep>
constexpr bool safe::less_equal(const raw_fraction<Rep>& left,
                                const Rep& right) noexcept
{
  return left.numerator <= right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool safe::less_equal(const Rep& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return left * right.denominator <= right.numerator && is_defined(right);
}

template <typename Rep>
constexpr bool safe::greater(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool safe::greater(const raw_fraction<Rep>& left,
                             const Rep& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool safe::greater(const Rep& left,
                             const raw_fraction<Rep>& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool safe::greater_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  return less_equal(right, left);
}

template <typename Rep>
constexpr bool safe::greater_equal(const raw_fraction<Rep>& left,
                                   const Rep& right) noexcept
{
  return less_equal(right, left);
}

template <typename Rep>
constexpr bool safe::greater_equal(const Rep& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  return less_equal(right, left);
}


template <typename Rep>
constexpr raw_fraction<Rep>
fast::negate(const raw_fraction<Rep>& value) noexcept
{
  return {-value.numerator, value.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::plus(const raw_fraction<Rep>& left,
                                       const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator * right.denominator
            + right.numerator * left.denominator,
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::plus(const raw_fraction<Rep>& left,
                                       const Rep& right) noexcept
{
  return {left.numerator + right * left.denominator, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::plus(const Rep& left,
                                       const raw_fraction<Rep>& right) noexcept
{
  return plus(right, left);
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::minus(const raw_fraction<Rep>& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator * right.denominator
            - right.numerator * left.denominator,
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::minus(const raw_fraction<Rep>& left,
                                        const Rep& right) noexcept
{
  return {left.numerator - right * left.denominator, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::minus(const Rep& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return {left * right.denominator - right.numerator, right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::multiplies(const raw_fraction<Rep>& left,
                 const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator * right.numerator,
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::multiplies(const raw_fraction<Rep>& left,
                                             const Rep& right) noexcept
{
  return {left.numerator * right, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::multiplies(const Rep& left, const raw_fraction<Rep>& right) noexcept
{
  return multiplies(right, left);
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::divides(const raw_fraction<Rep>& left,
              const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator * right.denominator,
          left.denominator * right.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::divides(const raw_fraction<Rep>& left,
                                          const Rep& right) noexcept
{
  return {left.numerator, left.denominator * right};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::divides(const Rep& left, const raw_fraction<Rep>& right) noexcept
{
  return {left * right.denominator, right.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::modulus(const raw_fraction<Rep>& left,
              const raw_fraction<Rep>& right) noexcept
{
  return {(left.numerator * right.denominator)
            % (right.numerator * left.denominator),
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::modulus(const raw_fraction<Rep>& left,
                                          const Rep& right) noexcept
{
  return {left.numerator % (right * left.denominator), left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::modulus(const Rep& left, const raw_fraction<Rep>& right) noexcept
{
  return {(left * right.denominator) % right.numerator, right.denominator};
}

template <typename Rep>
constexpr bool fast::equal_to(const raw_fraction<Rep>& left,
                              const raw_fraction<Rep>& right) noexcept
{
  return left.numerator * right.denominator
           == right.numerator * left.denominator
         && is_defined(left) && is_defined(right);
}

template <typename Rep>
constexpr bool fast::equal_to(const raw_fraction<Rep>& left,
                              const Rep& right) noexcept
{
  return left.numerator == right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool fast::equal_to(const Rep& left,
                              const raw_fraction<Rep>& right) noexcept
{
  return equal_to(right, left);
}

template <typename Rep>
constexpr bool fast::not_equal_to(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool fast::not_equal_to(const raw_fraction<Rep>& left,
                                  const Rep& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool fast::not_equal_to(const Rep& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool fast::less(const raw_fraction<Rep>& left,
                          const raw_fraction<Rep>& right) noexcept
{
  return left.numerator * right.denominator < right.numerator * left.denominator
         && is_defined(left) && is_defined(right);
}

template <typename Rep>
constexpr bool fast::less(const raw_fraction<Rep>& left,
                          const Rep& right) noexcept
{
  return left.numerator < right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool fast::less(const Rep& left,
                          const raw_fraction<Rep>& right) noexcept
{
  return left * right.denominator < right.numerator && is_defined(right);
}

template <typename Rep>
constexpr bool fast::less_equal(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return left.numerator * right.denominator
           <= right.numerator * left.denominator
         && is_defined(left) && is_defined(right);
}

template <typename Rep>
constexpr bool fast::less_equal(const raw_fraction<Rep>& left,
                                const Rep& right) noexcept
{
  return left.numerator <= right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool fast::less_equal(const Rep& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return left * right.denominator <= right.numerator && is_defined(right);
}

template <typename Rep>
constexpr bool fast::greater(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool fast::greater(const raw_fraction<Rep>& left,
                             const Rep& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool fast::greater(const Rep& left,
                             const raw_fraction<Rep>& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool fast::greater_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  return less_equal(right, left);
}

template <typename Rep>
constexpr bool fast::greater_equal(const raw_fraction<Rep>& left,
                                   const Rep& right) noexcept
{
  return less_equal(right, left);
}

template <typename Rep>
constexpr bool fast::greater_equal(const Rep& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  return less_equal(right, left);
}


template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::negate(const raw_fraction<Rep>& value) noexcept
{
  return ops_type::negate(reduce(value));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::plus(const raw_fraction<Rep>& left,
                               const raw_fraction<Rep>& right) noexcept
{
  return ops_type::plus(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::plus(const raw_fraction<Rep>& left,
                               const Rep& right) noexcept
{
  return ops_type::plus(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::plus(const Rep& left,
                               const raw_fraction<Rep>& right) noexcept
{
  return ops_type::plus(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::minus(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return ops_type::minus(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::minus(const raw_fraction<Rep>& left,
                                const Rep& right) noexcept
{
  return ops_type::minus(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::minus(const Rep& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return ops_type::minus(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::multiplies(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return ops_type::multiplies(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::multiplies(const raw_fraction<Rep>& left,
                                     const Rep& right) noexcept
{
  return ops_type::multiplies(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::multiplies(const Rep& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return ops_type::multiplies(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::divides(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return ops_type::divides(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::divides(const raw_fraction<Rep>& left,
                                  const Rep& right) noexcept
{
  return ops_type::divides(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::divides(const Rep& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return ops_type::divides(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::modulus(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return ops_type::modulus(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::modulus(const raw_fraction<Rep>& left,
                                  const Rep& right) noexcept
{
  return ops_type::modulus(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::modulus(const Rep& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return ops_type::modulus(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::equal_to(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  return ops_type::equal_to(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool reduced_input<Ops, Mode>::equal_to(const raw_fraction<Rep>& left,
                                                  const Rep& right) noexcept
{
  return ops_type::equal_to(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::equal_to(const Rep& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  return ops_type::equal_to(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::not_equal_to(const raw_fraction<Rep>& left,
                                       const raw_fraction<Rep>& right) noexcept
{
  return ops_type::not_equal_to(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::not_equal_to(const raw_fraction<Rep>& left,
                                       const Rep& right) noexcept
{
  return ops_type::not_equal_to(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::not_equal_to(const Rep& left,
                                       const raw_fraction<Rep>& right) noexcept
{
  return ops_type::not_equal_to(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less(const raw_fraction<Rep>& left,
                               const raw_fraction<Rep>& right) noexcept
{
  return ops_type::less(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool reduced_input<Ops, Mode>::less(const raw_fraction<Rep>& left,
                                              const Rep& right) noexcept
{
  return ops_type::less(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less(const Rep& left,
                               const raw_fraction<Rep>& right) noexcept
{
  return ops_type::less(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less_equal(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return ops_type::less_equal(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less_equal(const raw_fraction<Rep>& left,
                                     const Rep& right) noexcept
{
  return ops_type::less_equal(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less_equal(const Rep& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return ops_type::less_equal(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return ops_type::greater(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool reduced_input<Ops, Mode>::greater(const raw_fraction<Rep>& left,
                                                 const Rep& right) noexcept
{
  return ops_type::greater(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater(const Rep& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return ops_type::greater(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater_equal(const raw_fraction<Rep>& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return ops_type::greater_equal(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater_equal(const raw_fraction<Rep>& left,
                                        const Rep& right) noexcept
{
  return ops_type::greater_equal(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater_equal(const Rep& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return ops_type::greater_equal(left, reduce(right, mode));
}


template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_output<Ops, Mode>::negate(const raw_fraction<Rep>& value) noexcept
{
  return reduce(ops_type::negate(value), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto reduced_output<Ops, Mode>::plus(const Left& left,
                                               const Right& right) noexcept
{
  return reduce(ops_type::plus(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto reduced_output<Ops, Mode>::minus(const Left& left,
                                                const Right& right) noexcept
{
  return reduce(ops_type::minus(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto
reduced_output<Ops, Mode>::multiplies(const Left& left,
                                      const Right& right) noexcept
{
  return reduce(ops_type::multiplies(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto reduced_output<Ops, Mode>::divides(const Left& left,
                                                  const Right& right) noexcept
{
  return reduce(ops_type::divides(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto reduced_output<Ops, Mode>::modulus(const Left& left,
                                                  const Right& right) noexcept
{
  return reduce(ops_type::modulus(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool reduced_output<Ops, Mode>::equal_to(const Left& left,
                                                   const Right& right) noexcept
{
  return ops_type::equal_to(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool
reduced_output<Ops, Mode>::not_equal_to(const Left& left,
                                        const Right& right) noexcept
{
  return ops_type::not_equal_to(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool reduced_output<Ops, Mode>::less(const Left& left,
                                               const Right& right) noexcept
{
  return ops_type::less(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool
reduced_output<Ops, Mode>::less_equal(const Left& left,
                                      const Right& right) noexcept
{
  return ops_type::less_equal(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool reduced_output<Ops, Mode>::greater(const Left& left,
                                                  const Right& right) noexcept
{
  return ops_type::greater(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool
reduced_output<Ops, Mode>::greater_equal(const Left& left,
                                         const Right& right) noexcept
{
  return ops_type::greater_equal(left, right);
}


}; // namespace ops
}; // namespace ieme


#endif
