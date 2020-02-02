#ifndef IEME_LITERALS_HPP
#define IEME_LITERALS_HPP

#include <ieme/fraction.hpp>

#include <type_traits>


namespace ieme {
namespace literals {


template <bool IsSigned, typename Ops = ops::defaults>
class fraction_denominator_literal final {

public:
  static constexpr const bool is_signed = IsSigned;

  using unsigned_type = unsigned long long int;
  using signed_type = std::make_signed_t<unsigned_type>;
  using intermediate_type
    = std::conditional_t<IsSigned, signed_type, unsigned_type>;
  using ops_type = Ops;

  constexpr fraction_denominator_literal(intermediate_type value) noexcept;

  constexpr intermediate_type value() const noexcept { return value_; }

private:
  intermediate_type value_;
};

constexpr fraction_denominator_literal<false>
operator""_Fr(unsigned long long int value) noexcept;

template <bool IsSigned, typename Ops>
constexpr fraction_denominator_literal<IsSigned, Ops>
operator+(const fraction_denominator_literal<IsSigned, Ops>& value) noexcept;

template <bool IsSigned, typename Ops>
constexpr fraction_denominator_literal<true, Ops>
operator-(const fraction_denominator_literal<IsSigned, Ops>& value) noexcept;

template <bool IsSigned, typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const fraction<Rep, Ops>& left,
          const fraction_denominator_literal<IsSigned, Ops>& right) noexcept;

template <bool IsSigned, typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const Rep& left,
          const fraction_denominator_literal<IsSigned, Ops>& right) noexcept;


// =============================================================================


template <bool IsSigned, typename Ops>
constexpr fraction_denominator_literal<IsSigned, Ops>::
  fraction_denominator_literal(const intermediate_type value) noexcept :
  value_ {value}
{
}

constexpr fraction_denominator_literal<false>
operator""_Fr(const unsigned long long int value) noexcept
{
  return value;
}

template <bool IsSigned, typename Ops>
constexpr fraction_denominator_literal<IsSigned, Ops>
operator+(const fraction_denominator_literal<IsSigned, Ops>& value) noexcept
{
  return value;
}

template <bool IsSigned, typename Ops>
constexpr fraction_denominator_literal<true, Ops>
operator-(const fraction_denominator_literal<IsSigned, Ops>& value) noexcept
{
  return -typename fraction_denominator_literal<true, Ops>::intermediate_type(
    value.value());
}

template <bool IsSigned, typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const fraction<Rep, Ops>& left,
          const fraction_denominator_literal<IsSigned, Ops>& right) noexcept
{
  return left / Rep(right.value());
}

template <bool IsSigned, typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const Rep& left,
          const fraction_denominator_literal<IsSigned, Ops>& right) noexcept
{
  return {left, Rep(right.value())};
}


}; // namespace literals
}; // namespace ieme


#endif
