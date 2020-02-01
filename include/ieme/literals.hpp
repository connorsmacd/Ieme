#ifndef IEME_LITERALS_HPP
#define IEME_LITERALS_HPP

#include <ieme/fraction.hpp>


namespace ieme {
namespace literals {


template <typename Rep, typename Ops = ops::defaults>
class fraction_denominator_literal final {

public:
  using fraction_type = fraction<Rep, Ops>;
  using rep_type = typename fraction<Rep, Ops>::rep_type;
  using ops_type = typename fraction<Rep, Ops>::ops_type;

  constexpr fraction_denominator_literal(const Rep& value) noexcept;

  constexpr const Rep& value() const noexcept { return value_; }

private:
  Rep value_;
};

template <typename Rep, typename Ops>
constexpr fraction_denominator_literal<Rep, Ops>
operator+(const fraction_denominator_literal<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction_denominator_literal<Rep, Ops>
operator-(const fraction_denominator_literal<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const fraction<Rep, Ops>& left,
          const fraction_denominator_literal<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const Rep& left,
          const fraction_denominator_literal<Rep, Ops>& right) noexcept;

constexpr fraction_denominator_literal<int>
operator""_Fr(unsigned long long int value) noexcept;

constexpr fraction_denominator_literal<unsigned int>
operator""_uFr(unsigned long long int value) noexcept;

constexpr fraction_denominator_literal<long int>
operator""_lFr(unsigned long long int value) noexcept;

constexpr fraction_denominator_literal<unsigned long int>
operator""_ulFr(unsigned long long int value) noexcept;

constexpr fraction_denominator_literal<long long int>
operator""_llFr(unsigned long long int value) noexcept;

constexpr fraction_denominator_literal<unsigned long long int>
operator""_ullFr(unsigned long long int value) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr fraction_denominator_literal<Rep, Ops>::fraction_denominator_literal(
  const Rep& value) noexcept :
  value_ {value}
{
}

template <typename Rep, typename Ops>
constexpr fraction_denominator_literal<Rep, Ops>
operator+(const fraction_denominator_literal<Rep, Ops>& value) noexcept
{
  return value;
}

template <typename Rep, typename Ops>
constexpr fraction_denominator_literal<Rep, Ops>
operator-(const fraction_denominator_literal<Rep, Ops>& value) noexcept
{
  return -value.value();
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const fraction<Rep, Ops>& left,
          const fraction_denominator_literal<Rep, Ops>& right) noexcept
{
  return left / right.value();
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const Rep& left,
          const fraction_denominator_literal<Rep, Ops>& right) noexcept
{
  return {left, right.value()};
}

constexpr fraction_denominator_literal<int>
operator""_Fr(const unsigned long long int value) noexcept
{
  return value;
}

constexpr fraction_denominator_literal<unsigned int>
operator""_uFr(const unsigned long long int value) noexcept
{
  return value;
}

constexpr fraction_denominator_literal<long int>
operator""_lFr(const unsigned long long int value) noexcept
{
  return value;
}

constexpr fraction_denominator_literal<unsigned long int>
operator""_ulFr(const unsigned long long int value) noexcept
{
  return value;
}

constexpr fraction_denominator_literal<long long int>
operator""_llFr(const unsigned long long int value) noexcept
{
  return value;
}

constexpr fraction_denominator_literal<unsigned long long int>
operator""_ullFr(const unsigned long long int value) noexcept
{
  return value;
}


}; // namespace literals
}; // namespace ieme


#endif
