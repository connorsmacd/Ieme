#pragma once

#include <ieme/raw_fraction.hpp>


namespace ieme {
namespace ops {


class strict {

public:
  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const raw_fraction<Rep>& left,
             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(const raw_fraction<Rep>& value) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const raw_fraction<Rep>& right) noexcept;
};


class safe {

public:
  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const raw_fraction<Rep>& left,
             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(const raw_fraction<Rep>& value) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const raw_fraction<Rep>& right) noexcept;
};


class fast {

public:
  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(const raw_fraction<Rep>& left, const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(const raw_fraction<Rep>& left,
             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(const raw_fraction<Rep>& left,
          const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(const raw_fraction<Rep>& value) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(const raw_fraction<Rep>& left,
                                 const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(const raw_fraction<Rep>& left,
                                      const raw_fraction<Rep>& right) noexcept;
};


// =============================================================================


template <typename Rep>
constexpr raw_fraction<Rep>
strict::plus(const raw_fraction<Rep>& left,
             const raw_fraction<Rep>& right) noexcept
{
  return reduce(safe::plus(left, right));
}

template <typename Rep>
constexpr raw_fraction<Rep>
strict::minus(const raw_fraction<Rep>& left,
              const raw_fraction<Rep>& right) noexcept
{
  return reduce(safe::minus(left, right));
}

template <typename Rep>
constexpr raw_fraction<Rep>
strict::multiplies(const raw_fraction<Rep>& left,
                   const raw_fraction<Rep>& right) noexcept
{
  return reduce(safe::multiplies(left, right));
}

template <typename Rep>
constexpr raw_fraction<Rep>
strict::divides(const raw_fraction<Rep>& left,
                const raw_fraction<Rep>& right) noexcept
{
  return reduce(safe::divides(left, right));
}

template <typename Rep>
constexpr raw_fraction<Rep>
strict::modulus(const raw_fraction<Rep>& left,
                const raw_fraction<Rep>& right) noexcept
{
  return reduce(safe::modulus(left, right));
}

template <typename Rep>
constexpr raw_fraction<Rep>
strict::negate(const raw_fraction<Rep>& value) noexcept
{
  return reduce(safe::negate(value));
}

template <typename Rep>
constexpr bool strict::equal_to(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept
{
  return safe::equal_to(left, right);
}

template <typename Rep>
constexpr bool strict::not_equal_to(const raw_fraction<Rep>& left,
                                    const raw_fraction<Rep>& right) noexcept
{
  return safe::not_equal_to(left, right);
}

template <typename Rep>
constexpr bool strict::less(const raw_fraction<Rep>& left,
                            const raw_fraction<Rep>& right) noexcept
{
  return safe::less(left, right);
}

template <typename Rep>
constexpr bool strict::less_equal(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return safe::less_equal(left, right);
}

template <typename Rep>
constexpr bool strict::greater(const raw_fraction<Rep>& left,
                               const raw_fraction<Rep>& right) noexcept
{
  return safe::greater(left, right);
}

template <typename Rep>
constexpr bool strict::greater_equal(const raw_fraction<Rep>& left,
                                     const raw_fraction<Rep>& right) noexcept
{
  return safe::greater_equal(left, right);
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::plus(const raw_fraction<Rep>& left,
                                       const raw_fraction<Rep>& right) noexcept
{
  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  const auto lcm
    = std::lcm(left_reduced.denominator, right_reduced.denominator);

  return {lcm / left_reduced.denominator * left_reduced.numerator
            + lcm / right_reduced.denominator * right_reduced.numerator,
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::minus(const raw_fraction<Rep>& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  const auto lcm
    = std::lcm(left_reduced.denominator, right_reduced.denominator);

  return {lcm / left_reduced.denominator * left_reduced.numerator
            - lcm / right_reduced.denominator * right_reduced.numerator,
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::multiplies(const raw_fraction<Rep>& left,
                 const raw_fraction<Rep>& right) noexcept
{
  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  return {left_reduced.numerator * right_reduced.numerator,
          left_reduced.denominator * right_reduced.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::divides(const raw_fraction<Rep>& left,
              const raw_fraction<Rep>& right) noexcept
{
  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  return {left_reduced.numerator * right_reduced.denominator,
          left_reduced.denominator * right_reduced.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::modulus(const raw_fraction<Rep>& left,
              const raw_fraction<Rep>& right) noexcept
{
  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  const auto lcm
    = std::lcm(left_reduced.denominator, right_reduced.denominator);

  return {(lcm / left_reduced.denominator * left_reduced.numerator)
            % (lcm / right_reduced.denominator * right_reduced.numerator),
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::negate(const raw_fraction<Rep>& value) noexcept
{
  return {-value.numerator, value.denominator};
}

template <typename Rep>
constexpr bool safe::equal_to(const raw_fraction<Rep>& left,
                              const raw_fraction<Rep>& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  const auto lcm
    = std::lcm(left_reduced.denominator, right_reduced.denominator);

  return lcm / left_reduced.denominator * left_reduced.numerator
         == lcm / right_reduced.denominator * right_reduced.numerator;
}

template <typename Rep>
constexpr bool safe::not_equal_to(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool safe::less(const raw_fraction<Rep>& left,
                          const raw_fraction<Rep>& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  const auto lcm
    = std::lcm(left_reduced.denominator, right_reduced.denominator);

  return lcm / left_reduced.denominator * left_reduced.numerator
         < lcm / right_reduced.denominator * right_reduced.numerator;
}

template <typename Rep>
constexpr bool safe::less_equal(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  const auto lcm
    = std::lcm(left_reduced.denominator, right_reduced.denominator);

  return lcm / left_reduced.denominator * left_reduced.numerator
         <= lcm / right_reduced.denominator * right_reduced.numerator;
}

template <typename Rep>
constexpr bool safe::greater(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  const auto lcm
    = std::lcm(left_reduced.denominator, right_reduced.denominator);

  return lcm / left_reduced.denominator * left_reduced.numerator
         > lcm / right_reduced.denominator * right_reduced.numerator;
}

template <typename Rep>
constexpr bool safe::greater_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  const auto left_reduced = reduce(left);
  const auto right_reduced = reduce(right);

  const auto lcm
    = std::lcm(left_reduced.denominator, right_reduced.denominator);

  return lcm / left_reduced.denominator * left_reduced.numerator
         >= lcm / right_reduced.denominator * right_reduced.numerator;
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::plus(const raw_fraction<Rep>& left,
                                       const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator() * right.denominator()
            + right.numerator() * left.denominator(),
          left.denominator() * right.denominator()};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::minus(const raw_fraction<Rep>& left,
                                        const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator() * right.denominator()
            - right.numerator() * left.denominator(),
          left.denominator() * right.denominator()};
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
constexpr raw_fraction<Rep>
fast::divides(const raw_fraction<Rep>& left,
              const raw_fraction<Rep>& right) noexcept
{
  return {left.numerator * right.denominator,
          left.denominator * right.numerator};
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
constexpr raw_fraction<Rep>
fast::negate(const raw_fraction<Rep>& value) noexcept
{
  return {-value.numerator, value.denominator};
}

template <typename Rep>
constexpr bool fast::equal_to(const raw_fraction<Rep>& left,
                              const raw_fraction<Rep>& right) noexcept
{
  if (isUndefined(left) || isUndefined(right))
    return false;

  return left.numerator() * right.denominator()
         == right.numerator() * left.denominator();
}

template <typename Rep>
constexpr bool fast::not_equal_to(const raw_fraction<Rep>& left,
                                  const raw_fraction<Rep>& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool fast::less(const raw_fraction<Rep>& left,
                          const raw_fraction<Rep>& right) noexcept
{
  if (isUndefined(left) || isUndefined(right))
    return false;

  return left.numerator() * right.denominator()
         < right.numerator() * left.denominator();
}

template <typename Rep>
constexpr bool fast::less_equal(const raw_fraction<Rep>& left,
                                const raw_fraction<Rep>& right) noexcept
{
  if (isUndefined(left) || isUndefined(right))
    return false;

  return left.numerator() * right.denominator()
         <= right.numerator() * left.denominator();
}

template <typename Rep>
constexpr bool fast::greater(const raw_fraction<Rep>& left,
                             const raw_fraction<Rep>& right) noexcept
{
  if (isUndefined(left) || isUndefined(right))
    return false;

  return left.numerator() * right.denominator()
         > right.numerator() * left.denominator();
}

template <typename Rep>
constexpr bool fast::greater_equal(const raw_fraction<Rep>& left,
                                   const raw_fraction<Rep>& right) noexcept
{
  if (isUndefined(left) || isUndefined(right))
    return false;

  return left.numerator() * right.denominator()
         >= right.numerator() * left.denominator();
}


}; // namespace ops
}; // namespace ieme
