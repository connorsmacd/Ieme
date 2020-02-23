#ifndef IEME_FRACTION_HPP
#define IEME_FRACTION_HPP

#include <ieme/ops.hpp>
#include <ieme/raw_fraction.hpp>

#include <istream>
#include <ostream>
#include <ratio>


namespace ieme {


template <typename Rep, typename Ops = ops::defaults>
class fraction final {

public:
  using raw_fraction_type = raw_fraction<Rep>;
  using rep_type = typename raw_fraction_type::rep_type;
  using ops_type = Ops;

  constexpr fraction() = default;

  constexpr fraction(const raw_fraction_type& raw) noexcept;

  constexpr fraction(const Rep& numerator, const Rep& denominator = 1) noexcept;

  template <typename OtherRep, typename OtherOps>
  constexpr fraction(const fraction<OtherRep, OtherOps>& other) noexcept;

  template <std::intmax_t Numerator, std::intmax_t Denominator>
  constexpr fraction(std::ratio<Numerator, Denominator> ratio) noexcept;

  constexpr const Rep& numerator() const noexcept;
  constexpr Rep& numerator() noexcept;

  constexpr const Rep& denominator() const noexcept;
  constexpr Rep& denominator() noexcept;

  constexpr const Rep& num() const noexcept { return numerator(); }
  constexpr Rep& num() noexcept { return numerator(); }

  constexpr const Rep& den() const noexcept { return denominator(); }
  constexpr Rep& den() noexcept { return denominator(); }

  constexpr const raw_fraction_type& raw() const noexcept { return raw_; }
  constexpr raw_fraction_type& raw() noexcept { return raw_; }

private:
  raw_fraction_type raw_ = {0, 1};
};

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator+(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator-(const fraction<Rep, Ops>& value) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator+(const fraction<LeftRep, Ops>& left,
          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator+(const fraction<LeftRep, Ops>& left, const RightRep& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator+(const LeftRep& left, const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator-(const fraction<LeftRep, Ops>& left,
          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator-(const fraction<LeftRep, Ops>& left, const RightRep& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator-(const LeftRep& left, const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator*(const fraction<LeftRep, Ops>& left,
          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator*(const fraction<LeftRep, Ops>& left, const RightRep& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator*(const LeftRep& left, const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator/(const fraction<LeftRep, Ops>& left,
          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator/(const fraction<LeftRep, Ops>& left, const RightRep& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator/(const LeftRep& left, const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator%(const fraction<LeftRep, Ops>& left,
          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator%(const fraction<LeftRep, Ops>& left, const RightRep& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator%(const LeftRep& left, const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator+=(fraction<LeftRep, Ops>& left,
           const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator+=(fraction<LeftRep, Ops>& left,
                                             const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator-=(fraction<LeftRep, Ops>& left,
           const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator-=(fraction<LeftRep, Ops>& left,
                                             const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator*=(fraction<LeftRep, Ops>& left,
           const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator*=(fraction<LeftRep, Ops>& left,
                                             const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator/=(fraction<LeftRep, Ops>& left,
           const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator/=(fraction<LeftRep, Ops>& left,
                                             const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator%=(fraction<LeftRep, Ops>& left,
           const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator%=(fraction<LeftRep, Ops>& left,
                                             const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator==(const fraction<LeftRep, Ops>& left,
                          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator==(const fraction<LeftRep, Ops>& left,
                          const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator==(const LeftRep& left,
                          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator!=(const fraction<LeftRep, Ops>& left,
                          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator!=(const fraction<LeftRep, Ops>& left,
                          const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator!=(const LeftRep& left,
                          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<(const fraction<LeftRep, Ops>& left,
                         const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<(const fraction<LeftRep, Ops>& left,
                         const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<(const LeftRep& left,
                         const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<=(const fraction<LeftRep, Ops>& left,
                          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<=(const fraction<LeftRep, Ops>& left,
                          const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<=(const LeftRep& left,
                          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>(const fraction<LeftRep, Ops>& left,
                         const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>(const fraction<LeftRep, Ops>& left,
                         const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>(const LeftRep& left,
                         const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>=(const fraction<LeftRep, Ops>& left,
                          const fraction<RightRep, Ops>& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>=(const fraction<LeftRep, Ops>& left,
                          const RightRep& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>=(const LeftRep& left,
                          const fraction<RightRep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
std::ostream& operator<<(std::ostream& stream,
                         const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
std::istream& operator>>(std::istream& stream,
                         fraction<Rep, Ops>& value) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>::fraction(const raw_fraction_type& raw) noexcept :
  raw_ {raw}
{
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>::fraction(const Rep& numerator,
                                       const Rep& denominator) noexcept :
  raw_ {numerator, denominator}
{
}

template <typename Rep, typename Ops>
template <typename OtherRep, typename OtherOps>
constexpr fraction<Rep, Ops>::fraction(
  const fraction<OtherRep, OtherOps>& other) noexcept :
  raw_ {Rep(other.raw_.numerator, other.raw_.denominator)}
{
}

template <typename Rep, typename Ops>
template <std::intmax_t Numerator, std::intmax_t Denominator>
constexpr fraction<Rep, Ops>::fraction(
  std::ratio<Numerator, Denominator>) noexcept :
  raw_ {std::ratio<Numerator, Denominator>::num,
        std::ratio<Numerator, Denominator>::den}
{
}

template <typename Rep, typename Ops>
constexpr const Rep& fraction<Rep, Ops>::numerator() const noexcept
{
  return raw_.numerator;
}

template <typename Rep, typename Ops>
constexpr Rep& fraction<Rep, Ops>::numerator() noexcept
{
  return raw_.numerator;
}

template <typename Rep, typename Ops>
constexpr const Rep& fraction<Rep, Ops>::denominator() const noexcept
{
  return raw_.denominator;
}

template <typename Rep, typename Ops>
constexpr Rep& fraction<Rep, Ops>::denominator() noexcept
{
  return raw_.denominator;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator+(const fraction<Rep, Ops>& value) noexcept
{
  return value;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator-(const fraction<Rep, Ops>& value) noexcept
{
  return Ops::negate(value.raw());
}

#define IEME_DO_FRACTION_AND_FRACTION_OP(function)                             \
  using common_rep_type = std::common_type_t<LeftRep, RightRep>;               \
  using common_raw_type = raw_fraction<common_rep_type>;                       \
                                                                               \
  if constexpr (std::is_same_v<LeftRep, RightRep>)                             \
    return Ops::function(left.raw(), right.raw());                             \
  else if constexpr (std::is_same_v<LeftRep, common_rep_type>)                 \
    return Ops::function(left.raw(), common_raw_type(right.raw()));            \
  else if constexpr (std::is_same_v<RightRep, common_rep_type>)                \
    return Ops::function(common_raw_type(left.raw()), right.raw());            \
  else                                                                         \
    return Ops::function(common_raw_type(left.raw()),                          \
                         common_raw_type(right.raw()));

#define IEME_DO_FRACTION_AND_REP_OP(function)                                  \
  using common_rep_type = std::common_type_t<LeftRep, RightRep>;               \
  using common_raw_type = raw_fraction<common_rep_type>;                       \
                                                                               \
  if constexpr (std::is_same_v<LeftRep, RightRep>)                             \
    return Ops::function(left.raw(), right);                                   \
  else if constexpr (std::is_same_v<LeftRep, common_rep_type>)                 \
    return Ops::function(left.raw(), common_rep_type(right));                  \
  else if constexpr (std::is_same_v<RightRep, common_rep_type>)                \
    return Ops::function(common_raw_type(left.raw()), right);                  \
  else                                                                         \
    return Ops::function(common_raw_type(left.raw()), common_rep_type(right));

#define IEME_DO_REP_AND_FRACTION_OP(function)                                  \
  using common_rep_type = std::common_type_t<LeftRep, RightRep>;               \
  using common_raw_type = raw_fraction<common_rep_type>;                       \
                                                                               \
  if constexpr (std::is_same_v<LeftRep, RightRep>)                             \
    return Ops::function(left, right.raw());                                   \
  else if constexpr (std::is_same_v<LeftRep, common_rep_type>)                 \
    return Ops::function(left, common_raw_type(right.raw()));                  \
  else if constexpr (std::is_same_v<RightRep, common_rep_type>)                \
    return Ops::function(common_rep_type(left), right.raw());                  \
  else                                                                         \
    return Ops::function(common_rep_type(left), common_raw_type(right.raw()));

#define IEME_FRACTION_DEFINE_ARITHMETIC_OPS(symbol, function)                  \
  template <typename LeftRep, typename RightRep, typename Ops>                 \
  constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>               \
  operator symbol(const fraction<LeftRep, Ops>& left,                          \
                  const fraction<RightRep, Ops>& right) noexcept               \
  {                                                                            \
    IEME_DO_FRACTION_AND_FRACTION_OP(function)                                 \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops>                 \
  constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>               \
  operator symbol(const fraction<LeftRep, Ops>& left,                          \
                  const RightRep& right) noexcept                              \
  {                                                                            \
    IEME_DO_FRACTION_AND_REP_OP(function)                                      \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops>                 \
  constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>               \
  operator symbol(const LeftRep& left,                                         \
                  const fraction<RightRep, Ops>& right) noexcept               \
  {                                                                            \
    IEME_DO_REP_AND_FRACTION_OP(function)                                      \
  }

IEME_FRACTION_DEFINE_ARITHMETIC_OPS(+, plus)
IEME_FRACTION_DEFINE_ARITHMETIC_OPS(-, minus)
IEME_FRACTION_DEFINE_ARITHMETIC_OPS(*, multiplies)
IEME_FRACTION_DEFINE_ARITHMETIC_OPS(/, divides)
IEME_FRACTION_DEFINE_ARITHMETIC_OPS(%, modulus)

#define IEME_DEFINE_COMPOUND_ASSIGNMENT_OPS(symbol)                            \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr fraction<LeftRep, Ops>& operator symbol##=(                        \
    fraction<LeftRep, Ops>& left,                                              \
    const fraction<RightRep, Ops>& right) noexcept                             \
  {                                                                            \
    using common_rep_type = std::common_type_t<LeftRep, RightRep>;             \
    using common_raw_type = raw_fraction<common_rep_type>;                     \
                                                                               \
    if constexpr (std::is_same_v<LeftRep, RightRep>)                           \
      return left = left symbol right;                                         \
    else                                                                       \
      return left = left symbol common_raw_type(right.raw());                  \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr fraction<LeftRep, Ops>& operator symbol##=(                        \
    fraction<LeftRep, Ops>& left, const RightRep& right) noexcept              \
  {                                                                            \
    using common_rep_type = std::common_type_t<LeftRep, RightRep>;             \
                                                                               \
    if constexpr (std::is_same_v<LeftRep, RightRep>)                           \
      return left = left symbol right;                                         \
    else                                                                       \
      return left = left symbol common_rep_type(right);                        \
  }

IEME_DEFINE_COMPOUND_ASSIGNMENT_OPS(+)
IEME_DEFINE_COMPOUND_ASSIGNMENT_OPS(-)
IEME_DEFINE_COMPOUND_ASSIGNMENT_OPS(*)
IEME_DEFINE_COMPOUND_ASSIGNMENT_OPS(/)
IEME_DEFINE_COMPOUND_ASSIGNMENT_OPS(%)

#define IEME_FRACTION_DEFINE_COMPARISON_OPS(symbol, function)                  \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr bool operator symbol(                                              \
    const fraction<LeftRep, Ops>& left,                                        \
    const fraction<RightRep, Ops>& right) noexcept                             \
  {                                                                            \
    IEME_DO_FRACTION_AND_FRACTION_OP(function)                                 \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr bool operator symbol(const fraction<LeftRep, Ops>& left,           \
                                 const RightRep& right) noexcept               \
  {                                                                            \
    IEME_DO_FRACTION_AND_REP_OP(function)                                      \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr bool operator symbol(                                              \
    const LeftRep& left, const fraction<RightRep, Ops>& right) noexcept        \
  {                                                                            \
    IEME_DO_REP_AND_FRACTION_OP(function)                                      \
  }

IEME_FRACTION_DEFINE_COMPARISON_OPS(==, equal_to)
IEME_FRACTION_DEFINE_COMPARISON_OPS(!=, not_equal_to)
IEME_FRACTION_DEFINE_COMPARISON_OPS(<, less)
IEME_FRACTION_DEFINE_COMPARISON_OPS(<=, less_equal)
IEME_FRACTION_DEFINE_COMPARISON_OPS(>, greater)
IEME_FRACTION_DEFINE_COMPARISON_OPS(>=, greater_equal)

template <typename Rep, typename Ops>
std::ostream& operator<<(std::ostream& stream,
                         const fraction<Rep, Ops>& value) noexcept
{
  return stream << value.raw();
}

template <typename Rep, typename Ops>
std::istream& operator>>(std::istream& stream,
                         fraction<Rep, Ops>& value) noexcept
{
  return stream >> value.raw();
}


}; // namespace ieme


#endif
