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
  negate(raw_fraction<Rep> const& value) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(raw_fraction<Rep> const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> plus(raw_fraction<Rep> const& left,
                                          Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(raw_fraction<Rep> const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> minus(raw_fraction<Rep> const& left,
                                           Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(raw_fraction<Rep> const& left,
             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> multiplies(raw_fraction<Rep> const& left,
                                                Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(raw_fraction<Rep> const& left,
          raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> divides(raw_fraction<Rep> const& left,
                                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(raw_fraction<Rep> const& left,
          raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> modulus(raw_fraction<Rep> const& left,
                                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(raw_fraction<Rep> const& left,
                                 raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(raw_fraction<Rep> const& left,
                                 Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(Rep const& left,
                                 raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(raw_fraction<Rep> const& left,
                                     raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(raw_fraction<Rep> const& left,
                                     Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(Rep const& left,
                                     raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(raw_fraction<Rep> const& left,
                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(Rep const& left,
                             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(raw_fraction<Rep> const& left,
                                   raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(raw_fraction<Rep> const& left,
                                   Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(Rep const& left,
                                   raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(raw_fraction<Rep> const& left,
                                raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(raw_fraction<Rep> const& left,
                                Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(Rep const& left,
                                raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(raw_fraction<Rep> const& left,
                                      raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(raw_fraction<Rep> const& left,
                                      Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(Rep const& left,
                                      raw_fraction<Rep> const& right) noexcept;
};


class fast {

public:
  ~fast() = delete;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(raw_fraction<Rep> const& value) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(raw_fraction<Rep> const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> plus(raw_fraction<Rep> const& left,
                                          Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(raw_fraction<Rep> const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> minus(raw_fraction<Rep> const& left,
                                           Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(raw_fraction<Rep> const& left,
             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> multiplies(raw_fraction<Rep> const& left,
                                                Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(raw_fraction<Rep> const& left,
          raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> divides(raw_fraction<Rep> const& left,
                                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(raw_fraction<Rep> const& left,
          raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> modulus(raw_fraction<Rep> const& left,
                                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(raw_fraction<Rep> const& left,
                                 raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(raw_fraction<Rep> const& left,
                                 Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(Rep const& left,
                                 raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(raw_fraction<Rep> const& left,
                                     raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(raw_fraction<Rep> const& left,
                                     Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(Rep const& left,
                                     raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(raw_fraction<Rep> const& left,
                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(Rep const& left,
                             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(raw_fraction<Rep> const& left,
                                   raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(raw_fraction<Rep> const& left,
                                   Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(Rep const& left,
                                   raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(raw_fraction<Rep> const& left,
                                raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(raw_fraction<Rep> const& left,
                                Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(Rep const& left,
                                raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(raw_fraction<Rep> const& left,
                                      raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(raw_fraction<Rep> const& left,
                                      Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(Rep const& left,
                                      raw_fraction<Rep> const& right) noexcept;
};


template <typename Ops, reduce_mode Mode = reduce_mode::ignore_signs>
class reduced_input {

public:
  using ops_type = Ops;

  static constexpr reduce_mode mode = Mode;

  ~reduced_input() = delete;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(raw_fraction<Rep> const& value) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(raw_fraction<Rep> const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> plus(raw_fraction<Rep> const& left,
                                          Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  plus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(raw_fraction<Rep> const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> minus(raw_fraction<Rep> const& left,
                                           Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  minus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(raw_fraction<Rep> const& left,
             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> multiplies(raw_fraction<Rep> const& left,
                                                Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  multiplies(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(raw_fraction<Rep> const& left,
          raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> divides(raw_fraction<Rep> const& left,
                                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  divides(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(raw_fraction<Rep> const& left,
          raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep> modulus(raw_fraction<Rep> const& left,
                                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  modulus(Rep const& left, raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(raw_fraction<Rep> const& left,
                                 raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(raw_fraction<Rep> const& left,
                                 Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool equal_to(Rep const& left,
                                 raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(raw_fraction<Rep> const& left,
                                     raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(raw_fraction<Rep> const& left,
                                     Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool not_equal_to(Rep const& left,
                                     raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(raw_fraction<Rep> const& left,
                             Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool less(Rep const& left,
                             raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(raw_fraction<Rep> const& left,
                                   raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(raw_fraction<Rep> const& left,
                                   Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool less_equal(Rep const& left,
                                   raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(raw_fraction<Rep> const& left,
                                raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(raw_fraction<Rep> const& left,
                                Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater(Rep const& left,
                                raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(raw_fraction<Rep> const& left,
                                      raw_fraction<Rep> const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(raw_fraction<Rep> const& left,
                                      Rep const& right) noexcept;

  template <typename Rep>
  static constexpr bool greater_equal(Rep const& left,
                                      raw_fraction<Rep> const& right) noexcept;
};


template <typename Ops, reduce_mode Mode = reduce_mode::normalize_signs>
class reduced_output {

public:
  using ops_type = Ops;

  static constexpr reduce_mode mode = Mode;

  ~reduced_output() = delete;

  template <typename Rep>
  static constexpr raw_fraction<Rep>
  negate(raw_fraction<Rep> const& value) noexcept;

  template <typename Left, typename Right>
  static constexpr auto plus(Left const& left, Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr auto minus(Left const& left, Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr auto multiplies(Left const& left,
                                   Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr auto divides(Left const& left, Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr auto modulus(Left const& left, Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool equal_to(Left const& left, Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool not_equal_to(Left const& left,
                                     Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool less(Left const& left, Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool less_equal(Left const& left,
                                   Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool greater(Left const& left, Right const& right) noexcept;

  template <typename Left, typename Right>
  static constexpr bool greater_equal(Left const& left,
                                      Right const& right) noexcept;
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
safe::negate(raw_fraction<Rep> const& value) noexcept
{
  return {-value.numerator, value.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::plus(raw_fraction<Rep> const& left,
                                       raw_fraction<Rep> const& right) noexcept
{
  auto const lcm = std::lcm(left.denominator, right.denominator);

  return {lcm / left.denominator * left.numerator
            + lcm / right.denominator * right.numerator,
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::plus(raw_fraction<Rep> const& left,
                                       Rep const& right) noexcept
{
  return {left.numerator + right * left.denominator, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::plus(Rep const& left,
                                       raw_fraction<Rep> const& right) noexcept
{
  return plus(right, left);
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::minus(raw_fraction<Rep> const& left,
                                        raw_fraction<Rep> const& right) noexcept
{
  auto const lcm = std::lcm(left.denominator, right.denominator);

  return {lcm / left.denominator * left.numerator
            - lcm / right.denominator * right.numerator,
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::minus(raw_fraction<Rep> const& left,
                                        Rep const& right) noexcept
{
  return {left.numerator - right * left.denominator, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::minus(Rep const& left,
                                        raw_fraction<Rep> const& right) noexcept
{
  return {left * right.denominator - right.numerator, right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::multiplies(raw_fraction<Rep> const& left,
                 raw_fraction<Rep> const& right) noexcept
{
  return {left.numerator * right.numerator,
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::multiplies(raw_fraction<Rep> const& left,
                                             Rep const& right) noexcept
{
  return {left.numerator * right, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::multiplies(Rep const& left, raw_fraction<Rep> const& right) noexcept
{
  return multiplies(right, left);
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::divides(raw_fraction<Rep> const& left,
              raw_fraction<Rep> const& right) noexcept
{
  return {left.numerator * right.denominator,
          left.denominator * right.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::divides(raw_fraction<Rep> const& left,
                                          Rep const& right) noexcept
{
  return {left.numerator, left.denominator * right};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::divides(Rep const& left, raw_fraction<Rep> const& right) noexcept
{
  return {left * right.denominator, right.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::modulus(raw_fraction<Rep> const& left,
              raw_fraction<Rep> const& right) noexcept
{
  auto const lcm = std::lcm(left.denominator, right.denominator);

  return {(lcm / left.denominator * left.numerator)
            % (lcm / right.denominator * right.numerator),
          lcm};
}

template <typename Rep>
constexpr raw_fraction<Rep> safe::modulus(raw_fraction<Rep> const& left,
                                          Rep const& right) noexcept
{
  return {left.numerator % (left.denominator * right), left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
safe::modulus(Rep const& left, raw_fraction<Rep> const& right) noexcept
{
  return {(right.denominator * left) % right.numerator, right.denominator};
}

template <typename Rep>
constexpr bool safe::equal_to(raw_fraction<Rep> const& left,
                              raw_fraction<Rep> const& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  auto const lcm = std::lcm(left.denominator, right.denominator);

  return lcm / left.denominator * left.numerator
         == lcm / right.denominator * right.numerator;
}

template <typename Rep>
constexpr bool safe::equal_to(raw_fraction<Rep> const& left,
                              Rep const& right) noexcept
{
  return left.numerator == right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool safe::equal_to(Rep const& left,
                              raw_fraction<Rep> const& right) noexcept
{
  return equal_to(right, left);
}

template <typename Rep>
constexpr bool safe::not_equal_to(raw_fraction<Rep> const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool safe::not_equal_to(raw_fraction<Rep> const& left,
                                  Rep const& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool safe::not_equal_to(Rep const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return not_equal_to(right, left);
}

template <typename Rep>
constexpr bool safe::less(raw_fraction<Rep> const& left,
                          raw_fraction<Rep> const& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  auto const lcm = std::lcm(left.denominator, right.denominator);

  return lcm / left.denominator * left.numerator
         < lcm / right.denominator * right.numerator;
}

template <typename Rep>
constexpr bool safe::less(raw_fraction<Rep> const& left,
                          Rep const& right) noexcept
{
  return left.numerator < right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool safe::less(Rep const& left,
                          raw_fraction<Rep> const& right) noexcept
{
  return left * right.denominator < right.numerator && is_defined(right);
}

template <typename Rep>
constexpr bool safe::less_equal(raw_fraction<Rep> const& left,
                                raw_fraction<Rep> const& right) noexcept
{
  if (is_undefined(left) || is_undefined(right))
    return false;

  auto const lcm = std::lcm(left.denominator, right.denominator);

  return lcm / left.denominator * left.numerator
         <= lcm / right.denominator * right.numerator;
}

template <typename Rep>
constexpr bool safe::less_equal(raw_fraction<Rep> const& left,
                                Rep const& right) noexcept
{
  return left.numerator <= right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool safe::less_equal(Rep const& left,
                                raw_fraction<Rep> const& right) noexcept
{
  return left * right.denominator <= right.numerator && is_defined(right);
}

template <typename Rep>
constexpr bool safe::greater(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool safe::greater(raw_fraction<Rep> const& left,
                             Rep const& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool safe::greater(Rep const& left,
                             raw_fraction<Rep> const& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool safe::greater_equal(raw_fraction<Rep> const& left,
                                   raw_fraction<Rep> const& right) noexcept
{
  return less_equal(right, left);
}

template <typename Rep>
constexpr bool safe::greater_equal(raw_fraction<Rep> const& left,
                                   Rep const& right) noexcept
{
  return less_equal(right, left);
}

template <typename Rep>
constexpr bool safe::greater_equal(Rep const& left,
                                   raw_fraction<Rep> const& right) noexcept
{
  return less_equal(right, left);
}


template <typename Rep>
constexpr raw_fraction<Rep>
fast::negate(raw_fraction<Rep> const& value) noexcept
{
  return {-value.numerator, value.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::plus(raw_fraction<Rep> const& left,
                                       raw_fraction<Rep> const& right) noexcept
{
  return {left.numerator * right.denominator
            + right.numerator * left.denominator,
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::plus(raw_fraction<Rep> const& left,
                                       Rep const& right) noexcept
{
  return {left.numerator + right * left.denominator, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::plus(Rep const& left,
                                       raw_fraction<Rep> const& right) noexcept
{
  return plus(right, left);
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::minus(raw_fraction<Rep> const& left,
                                        raw_fraction<Rep> const& right) noexcept
{
  return {left.numerator * right.denominator
            - right.numerator * left.denominator,
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::minus(raw_fraction<Rep> const& left,
                                        Rep const& right) noexcept
{
  return {left.numerator - right * left.denominator, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::minus(Rep const& left,
                                        raw_fraction<Rep> const& right) noexcept
{
  return {left * right.denominator - right.numerator, right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::multiplies(raw_fraction<Rep> const& left,
                 raw_fraction<Rep> const& right) noexcept
{
  return {left.numerator * right.numerator,
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::multiplies(raw_fraction<Rep> const& left,
                                             Rep const& right) noexcept
{
  return {left.numerator * right, left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::multiplies(Rep const& left, raw_fraction<Rep> const& right) noexcept
{
  return multiplies(right, left);
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::divides(raw_fraction<Rep> const& left,
              raw_fraction<Rep> const& right) noexcept
{
  return {left.numerator * right.denominator,
          left.denominator * right.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::divides(raw_fraction<Rep> const& left,
                                          Rep const& right) noexcept
{
  return {left.numerator, left.denominator * right};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::divides(Rep const& left, raw_fraction<Rep> const& right) noexcept
{
  return {left * right.denominator, right.numerator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::modulus(raw_fraction<Rep> const& left,
              raw_fraction<Rep> const& right) noexcept
{
  return {(left.numerator * right.denominator)
            % (right.numerator * left.denominator),
          left.denominator * right.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep> fast::modulus(raw_fraction<Rep> const& left,
                                          Rep const& right) noexcept
{
  return {left.numerator % (right * left.denominator), left.denominator};
}

template <typename Rep>
constexpr raw_fraction<Rep>
fast::modulus(Rep const& left, raw_fraction<Rep> const& right) noexcept
{
  return {(left * right.denominator) % right.numerator, right.denominator};
}

template <typename Rep>
constexpr bool fast::equal_to(raw_fraction<Rep> const& left,
                              raw_fraction<Rep> const& right) noexcept
{
  return left.numerator * right.denominator
           == right.numerator * left.denominator
         && is_defined(left) && is_defined(right);
}

template <typename Rep>
constexpr bool fast::equal_to(raw_fraction<Rep> const& left,
                              Rep const& right) noexcept
{
  return left.numerator == right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool fast::equal_to(Rep const& left,
                              raw_fraction<Rep> const& right) noexcept
{
  return equal_to(right, left);
}

template <typename Rep>
constexpr bool fast::not_equal_to(raw_fraction<Rep> const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool fast::not_equal_to(raw_fraction<Rep> const& left,
                                  Rep const& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool fast::not_equal_to(Rep const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return !equal_to(left, right);
}

template <typename Rep>
constexpr bool fast::less(raw_fraction<Rep> const& left,
                          raw_fraction<Rep> const& right) noexcept
{
  return left.numerator * right.denominator < right.numerator * left.denominator
         && is_defined(left) && is_defined(right);
}

template <typename Rep>
constexpr bool fast::less(raw_fraction<Rep> const& left,
                          Rep const& right) noexcept
{
  return left.numerator < right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool fast::less(Rep const& left,
                          raw_fraction<Rep> const& right) noexcept
{
  return left * right.denominator < right.numerator && is_defined(right);
}

template <typename Rep>
constexpr bool fast::less_equal(raw_fraction<Rep> const& left,
                                raw_fraction<Rep> const& right) noexcept
{
  return left.numerator * right.denominator
           <= right.numerator * left.denominator
         && is_defined(left) && is_defined(right);
}

template <typename Rep>
constexpr bool fast::less_equal(raw_fraction<Rep> const& left,
                                Rep const& right) noexcept
{
  return left.numerator <= right * left.denominator && is_defined(left);
}

template <typename Rep>
constexpr bool fast::less_equal(Rep const& left,
                                raw_fraction<Rep> const& right) noexcept
{
  return left * right.denominator <= right.numerator && is_defined(right);
}

template <typename Rep>
constexpr bool fast::greater(raw_fraction<Rep> const& left,
                             raw_fraction<Rep> const& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool fast::greater(raw_fraction<Rep> const& left,
                             Rep const& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool fast::greater(Rep const& left,
                             raw_fraction<Rep> const& right) noexcept
{
  return less(right, left);
}

template <typename Rep>
constexpr bool fast::greater_equal(raw_fraction<Rep> const& left,
                                   raw_fraction<Rep> const& right) noexcept
{
  return less_equal(right, left);
}

template <typename Rep>
constexpr bool fast::greater_equal(raw_fraction<Rep> const& left,
                                   Rep const& right) noexcept
{
  return less_equal(right, left);
}

template <typename Rep>
constexpr bool fast::greater_equal(Rep const& left,
                                   raw_fraction<Rep> const& right) noexcept
{
  return less_equal(right, left);
}


template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::negate(raw_fraction<Rep> const& value) noexcept
{
  return ops_type::negate(reduce(value));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::plus(raw_fraction<Rep> const& left,
                               raw_fraction<Rep> const& right) noexcept
{
  return ops_type::plus(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::plus(raw_fraction<Rep> const& left,
                               Rep const& right) noexcept
{
  return ops_type::plus(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::plus(Rep const& left,
                               raw_fraction<Rep> const& right) noexcept
{
  return ops_type::plus(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::minus(raw_fraction<Rep> const& left,
                                raw_fraction<Rep> const& right) noexcept
{
  return ops_type::minus(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::minus(raw_fraction<Rep> const& left,
                                Rep const& right) noexcept
{
  return ops_type::minus(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::minus(Rep const& left,
                                raw_fraction<Rep> const& right) noexcept
{
  return ops_type::minus(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::multiplies(raw_fraction<Rep> const& left,
                                     raw_fraction<Rep> const& right) noexcept
{
  return ops_type::multiplies(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::multiplies(raw_fraction<Rep> const& left,
                                     Rep const& right) noexcept
{
  return ops_type::multiplies(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::multiplies(Rep const& left,
                                     raw_fraction<Rep> const& right) noexcept
{
  return ops_type::multiplies(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::divides(raw_fraction<Rep> const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return ops_type::divides(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::divides(raw_fraction<Rep> const& left,
                                  Rep const& right) noexcept
{
  return ops_type::divides(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::divides(Rep const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return ops_type::divides(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::modulus(raw_fraction<Rep> const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return ops_type::modulus(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::modulus(raw_fraction<Rep> const& left,
                                  Rep const& right) noexcept
{
  return ops_type::modulus(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_input<Ops, Mode>::modulus(Rep const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return ops_type::modulus(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::equal_to(raw_fraction<Rep> const& left,
                                   raw_fraction<Rep> const& right) noexcept
{
  return ops_type::equal_to(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool reduced_input<Ops, Mode>::equal_to(raw_fraction<Rep> const& left,
                                                  Rep const& right) noexcept
{
  return ops_type::equal_to(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::equal_to(Rep const& left,
                                   raw_fraction<Rep> const& right) noexcept
{
  return ops_type::equal_to(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::not_equal_to(raw_fraction<Rep> const& left,
                                       raw_fraction<Rep> const& right) noexcept
{
  return ops_type::not_equal_to(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::not_equal_to(raw_fraction<Rep> const& left,
                                       Rep const& right) noexcept
{
  return ops_type::not_equal_to(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::not_equal_to(Rep const& left,
                                       raw_fraction<Rep> const& right) noexcept
{
  return ops_type::not_equal_to(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less(raw_fraction<Rep> const& left,
                               raw_fraction<Rep> const& right) noexcept
{
  return ops_type::less(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool reduced_input<Ops, Mode>::less(raw_fraction<Rep> const& left,
                                              Rep const& right) noexcept
{
  return ops_type::less(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less(Rep const& left,
                               raw_fraction<Rep> const& right) noexcept
{
  return ops_type::less(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less_equal(raw_fraction<Rep> const& left,
                                     raw_fraction<Rep> const& right) noexcept
{
  return ops_type::less_equal(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less_equal(raw_fraction<Rep> const& left,
                                     Rep const& right) noexcept
{
  return ops_type::less_equal(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::less_equal(Rep const& left,
                                     raw_fraction<Rep> const& right) noexcept
{
  return ops_type::less_equal(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater(raw_fraction<Rep> const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return ops_type::greater(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool reduced_input<Ops, Mode>::greater(raw_fraction<Rep> const& left,
                                                 Rep const& right) noexcept
{
  return ops_type::greater(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater(Rep const& left,
                                  raw_fraction<Rep> const& right) noexcept
{
  return ops_type::greater(left, reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater_equal(raw_fraction<Rep> const& left,
                                        raw_fraction<Rep> const& right) noexcept
{
  return ops_type::greater_equal(reduce(left, mode), reduce(right, mode));
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater_equal(raw_fraction<Rep> const& left,
                                        Rep const& right) noexcept
{
  return ops_type::greater_equal(reduce(left, mode), right);
}

template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr bool
reduced_input<Ops, Mode>::greater_equal(Rep const& left,
                                        raw_fraction<Rep> const& right) noexcept
{
  return ops_type::greater_equal(left, reduce(right, mode));
}


template <typename Ops, reduce_mode Mode>
template <typename Rep>
constexpr raw_fraction<Rep>
reduced_output<Ops, Mode>::negate(raw_fraction<Rep> const& value) noexcept
{
  return reduce(ops_type::negate(value), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto reduced_output<Ops, Mode>::plus(Left const& left,
                                               Right const& right) noexcept
{
  return reduce(ops_type::plus(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto reduced_output<Ops, Mode>::minus(Left const& left,
                                                Right const& right) noexcept
{
  return reduce(ops_type::minus(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto
reduced_output<Ops, Mode>::multiplies(Left const& left,
                                      Right const& right) noexcept
{
  return reduce(ops_type::multiplies(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto reduced_output<Ops, Mode>::divides(Left const& left,
                                                  Right const& right) noexcept
{
  return reduce(ops_type::divides(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr auto reduced_output<Ops, Mode>::modulus(Left const& left,
                                                  Right const& right) noexcept
{
  return reduce(ops_type::modulus(left, right), mode);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool reduced_output<Ops, Mode>::equal_to(Left const& left,
                                                   Right const& right) noexcept
{
  return ops_type::equal_to(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool
reduced_output<Ops, Mode>::not_equal_to(Left const& left,
                                        Right const& right) noexcept
{
  return ops_type::not_equal_to(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool reduced_output<Ops, Mode>::less(Left const& left,
                                               Right const& right) noexcept
{
  return ops_type::less(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool
reduced_output<Ops, Mode>::less_equal(Left const& left,
                                      Right const& right) noexcept
{
  return ops_type::less_equal(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool reduced_output<Ops, Mode>::greater(Left const& left,
                                                  Right const& right) noexcept
{
  return ops_type::greater(left, right);
}

template <typename Ops, reduce_mode Mode>
template <typename Left, typename Right>
constexpr bool
reduced_output<Ops, Mode>::greater_equal(Left const& left,
                                         Right const& right) noexcept
{
  return ops_type::greater_equal(left, right);
}


}; // namespace ops
}; // namespace ieme


#endif
