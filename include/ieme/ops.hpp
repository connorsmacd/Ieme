#ifndef IEME_OPS_HPP
#define IEME_OPS_HPP

#include <ieme/raw_fraction.hpp>
#include <ieme/raw_fraction_queries.hpp>


namespace ieme {
namespace ops {


class safe;

class fast;

template <typename DecorateeOps>
class reduced_input;

template <typename DecorateeOps>
class reduced_output;

using defaults = reduced_output<reduced_input<safe>>;


class safe {

public:
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


template <typename DecorateeOps>
class reduced_input {

public:
  using decoratee_ops_type = DecorateeOps;

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


template <typename DecorateeOps>
class reduced_output {

public:
  using decoratee_ops_type = DecorateeOps;

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
  return is_defined(left) && left.numerator == right * left.denominator;
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
  return is_defined(left) && left.numerator < right * left.denominator;
}

template <typename Rep>
constexpr bool safe::less(const Rep& left,
                          const raw_fraction<Rep>& right) noexcept
{
  return is_defined(right) && left * right.denominator < right.numerator;
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
  return is_defined(left) && left.numerator <= right * left.denominator;
}

template <typename Rep>
constexpr bool safe::less_equal(const Rep& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return is_defined(right) && left * right.denominator <= right.numerator;
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
  return is_defined(left) && is_defined(right)
         && left.numerator * right.denominator
              == right.numerator * left.denominator;
}

template <typename Rep>
constexpr bool fast::equal_to(const raw_fraction<Rep>& left,
                              const Rep& right) noexcept
{
  return is_defined(left) && left.numerator == right * left.denominator;
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
  return is_defined(left) && is_defined(right)
         && left.numerator * right.denominator
              < right.numerator * left.denominator;
}

template <typename Rep>
constexpr bool fast::less(const raw_fraction<Rep>& left,
                          const Rep& right) noexcept
{
  return is_defined(left) && left.numerator < right * left.denominator;
}

template <typename Rep>
constexpr bool fast::less(const Rep& left,
                          const raw_fraction<Rep>& right) noexcept
{
  return is_defined(right) && left * right.denominator < right.numerator;
}

template <typename Rep>
constexpr bool fast::less_equal(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return is_defined(left) && is_defined(right)
         && left.numerator * right.denominator
              <= right.numerator * left.denominator;
}

template <typename Rep>
constexpr bool fast::less_equal(const raw_fraction<Rep>& left,
                                const Rep& right) noexcept
{
  return is_defined(left) && left.numerator <= right * left.denominator;
}

template <typename Rep>
constexpr bool fast::less_equal(const Rep& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return is_defined(right) && left * right.denominator <= right.numerator;
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


template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::negate(const raw_fraction<Rep>& value) noexcept
{
  return DecorateeOps::negate(reduce(value));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::plus(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::plus(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::plus(const raw_fraction<Rep>& left,
                                  const Rep& right) noexcept
{
  return DecorateeOps::plus(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::plus(const Rep& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::plus(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::minus(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::minus(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::minus(const raw_fraction<Rep>& left,
                                   const Rep& right) noexcept
{
  return DecorateeOps::minus(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::minus(const Rep& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::minus(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::multiplies(const raw_fraction<Rep>& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::multiplies(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::multiplies(const raw_fraction<Rep>& left,
                                        const Rep& right) noexcept
{
  return DecorateeOps::multiplies(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::multiplies(const Rep& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::multiplies(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::divides(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::divides(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::divides(const raw_fraction<Rep>& left,
                                     const Rep& right) noexcept
{
  return DecorateeOps::divides(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::divides(const Rep& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::divides(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::modulus(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::modulus(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::modulus(const raw_fraction<Rep>& left,
                                     const Rep& right) noexcept
{
  return DecorateeOps::modulus(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<DecorateeOps>::modulus(const Rep& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::modulus(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::equal_to(const raw_fraction<Rep>& left,
                                      const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::equal_to(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::equal_to(const raw_fraction<Rep>& left,
                                      const Rep& right) noexcept
{
  return DecorateeOps::equal_to(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::equal_to(const Rep& left,
                                      const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::equal_to(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool reduced_input<DecorateeOps>::not_equal_to(
  const raw_fraction<Rep>& left,
  const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::not_equal_to(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::not_equal_to(const raw_fraction<Rep>& left,
                                          const Rep& right) noexcept
{
  return DecorateeOps::not_equal_to(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool reduced_input<DecorateeOps>::not_equal_to(
  const Rep& left,
  const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::not_equal_to(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::less(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::less(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool reduced_input<DecorateeOps>::less(const raw_fraction<Rep>& left,
                                                 const Rep& right) noexcept
{
  return DecorateeOps::less(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::less(const Rep& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::less(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::less_equal(const raw_fraction<Rep>& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::less_equal(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::less_equal(const raw_fraction<Rep>& left,
                                        const Rep& right) noexcept
{
  return DecorateeOps::less_equal(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::less_equal(const Rep& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::less_equal(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::greater(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::greater(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::greater(const raw_fraction<Rep>& left,
                                     const Rep& right) noexcept
{
  return DecorateeOps::greater(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::greater(const Rep& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::greater(left, reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool reduced_input<DecorateeOps>::greater_equal(
  const raw_fraction<Rep>& left,
  const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::greater_equal(reduce(left), reduce(right));
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool
reduced_input<DecorateeOps>::greater_equal(const raw_fraction<Rep>& left,
                                           const Rep& right) noexcept
{
  return DecorateeOps::greater_equal(reduce(left), right);
}

template <typename DecorateeOps>
template <typename Rep>
constexpr bool reduced_input<DecorateeOps>::greater_equal(
  const Rep& left,
  const raw_fraction<Rep>& right) noexcept
{
  return DecorateeOps::greater_equal(left, reduce(right));
}


template <typename DecorateeOps>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_output<DecorateeOps>::negate(const raw_fraction<Rep>& value) noexcept
{
  return reduce(DecorateeOps::negate(value));
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr auto reduced_output<DecorateeOps>::plus(const Left& left,
                                                  const Right& right) noexcept
{
  return reduce(DecorateeOps::plus(left, right));
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr auto reduced_output<DecorateeOps>::minus(const Left& left,
                                                   const Right& right) noexcept
{
  return reduce(DecorateeOps::minus(left, right));
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr auto
reduced_output<DecorateeOps>::multiplies(const Left& left,
                                         const Right& right) noexcept
{
  return reduce(DecorateeOps::multiplies(left, right));
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr auto
reduced_output<DecorateeOps>::divides(const Left& left,
                                      const Right& right) noexcept
{
  return reduce(DecorateeOps::divides(left, right));
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr auto
reduced_output<DecorateeOps>::modulus(const Left& left,
                                      const Right& right) noexcept
{
  return reduce(DecorateeOps::modulus(left, right));
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr bool
reduced_output<DecorateeOps>::equal_to(const Left& left,
                                       const Right& right) noexcept
{
  return DecorateeOps::equal_to(left, right);
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr bool
reduced_output<DecorateeOps>::not_equal_to(const Left& left,
                                           const Right& right) noexcept
{
  return DecorateeOps::not_equal_to(left, right);
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr bool reduced_output<DecorateeOps>::less(const Left& left,
                                                  const Right& right) noexcept
{
  return DecorateeOps::less(left, right);
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr bool
reduced_output<DecorateeOps>::less_equal(const Left& left,
                                         const Right& right) noexcept
{
  return DecorateeOps::less_equal(left, right);
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr bool
reduced_output<DecorateeOps>::greater(const Left& left,
                                      const Right& right) noexcept
{
  return DecorateeOps::greater(left, right);
}

template <typename DecorateeOps>
template <typename Left, typename Right>
constexpr bool
reduced_output<DecorateeOps>::greater_equal(const Left& left,
                                            const Right& right) noexcept
{
  return DecorateeOps::greater_equal(left, right);
}


}; // namespace ops
}; // namespace ieme


#endif
