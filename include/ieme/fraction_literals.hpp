#ifndef IEME_LITERALS_HPP
#define IEME_LITERALS_HPP

#include <ieme/floating_point.hpp>
#include <ieme/fraction.hpp>
#include <ieme/ops.hpp>

#include <type_traits>


namespace ieme {
inline namespace literals {
inline namespace fraction_literals {


template <bool IsSigned, typename Ops = ops::defaults>
class denominator_literal final {

public:
  static constexpr bool is_signed = IsSigned;

  using value_type
    = std::conditional_t<IsSigned, long long int, unsigned long long int>;
  using ops_type = Ops;

  constexpr denominator_literal(value_type value) noexcept;

  constexpr value_type value() const noexcept { return value_; }

private:
  value_type value_;
};

constexpr denominator_literal<false>
operator""_fr(unsigned long long int value) noexcept;

template <bool IsSigned, typename Ops>
constexpr denominator_literal<IsSigned, Ops>
operator+(denominator_literal<IsSigned, Ops> const& value) noexcept;

template <bool IsSigned, typename Ops>
constexpr denominator_literal<true, Ops>
operator-(denominator_literal<IsSigned, Ops> const& value) noexcept;

template <bool IsSigned, typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(fraction<Rep, Ops> const& left,
          denominator_literal<IsSigned, Ops> const& right) noexcept;

template <bool IsSigned, typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(Rep const& left,
          denominator_literal<IsSigned, Ops> const& right) noexcept;


constexpr fraction<std::intmax_t, ops::defaults>
operator""_dec(char const* string);


// =============================================================================


template <bool IsSigned, typename Ops>
constexpr denominator_literal<IsSigned, Ops>::denominator_literal(
  value_type const value) noexcept :
  value_ {value}
{
}

constexpr denominator_literal<false>
operator""_fr(unsigned long long int const value) noexcept
{
  return value;
}

template <bool IsSigned, typename Ops>
constexpr denominator_literal<IsSigned, Ops>
operator+(denominator_literal<IsSigned, Ops> const& value) noexcept
{
  return value;
}

template <bool IsSigned, typename Ops>
constexpr denominator_literal<true, Ops>
operator-(denominator_literal<IsSigned, Ops> const& value) noexcept
{
  return -typename denominator_literal<true, Ops>::value_type(value.value());
}

template <bool IsSigned, typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(fraction<Rep, Ops> const& left,
          denominator_literal<IsSigned, Ops> const& right) noexcept
{
  return left / Rep(right.value());
}

template <bool IsSigned, typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(Rep const& left,
          denominator_literal<IsSigned, Ops> const& right) noexcept
{
  return {left, Rep(right.value())};
}

constexpr fraction<std::intmax_t, ops::defaults>
operator""_dec(char const* const string)
{
  auto const result
    = floating_point_string_to_fraction<std::intmax_t, ops::defaults>(string);

  return is_defined(result) ? result : throw "invalid floating point literal";
}


}; // namespace fraction_literals
}; // namespace literals
}; // namespace ieme


#endif
