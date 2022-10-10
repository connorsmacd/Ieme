#ifndef IEME_FRACTION_HPP
#define IEME_FRACTION_HPP

#include <ieme/ops.hpp>
#include <ieme/raw_fraction.hpp>

#include <istream>
#include <ostream>
#include <ratio>


namespace ieme {


template <typename Rep, typename Ops>
class fraction;


template <typename Rep, typename Ops>
std::ostream& operator<<(std::ostream& stream,
                         fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
std::istream& operator>>(std::istream& stream,
                         fraction<Rep, Ops>& value) noexcept;


template <typename Rep, typename Ops = ops::defaults>
class fraction final {

public:
  using raw_fraction_type = raw_fraction<Rep>;
  using rep_type = typename raw_fraction_type::rep_type;
  using ops_type = Ops;

  constexpr fraction() = default;

  constexpr fraction(raw_fraction_type const& raw) noexcept;

  constexpr fraction(Rep const& numerator, Rep const& denominator = 1) noexcept;

  template <typename OtherRep>
  constexpr fraction(fraction<OtherRep, Ops> const& other) noexcept;

  template <typename OtherRep, typename OtherOps>
  explicit constexpr fraction(
    fraction<OtherRep, OtherOps> const& other) noexcept;

  template <std::intmax_t Numerator, std::intmax_t Denominator>
  constexpr fraction(std::ratio<Numerator, Denominator> ratio) noexcept;

  constexpr Rep const& numerator() const noexcept;
  constexpr Rep& numerator() noexcept;

  constexpr Rep const& denominator() const noexcept;
  constexpr Rep& denominator() noexcept;

  constexpr Rep const& num() const noexcept { return numerator(); }
  constexpr Rep& num() noexcept { return numerator(); }

  constexpr Rep const& den() const noexcept { return denominator(); }
  constexpr Rep& den() noexcept { return denominator(); }

  constexpr raw_fraction_type const& raw() const noexcept { return raw_; }
  constexpr raw_fraction_type& raw() noexcept { return raw_; }

private:
  raw_fraction_type raw_ = {_0<rep_type>, _1<rep_type>};

  friend std::ostream& operator<< <>(std::ostream& stream,
                                     fraction<Rep, Ops> const& value) noexcept;

  friend std::istream& operator>><>(std::istream& stream,
                                    fraction<Rep, Ops>& value) noexcept;
};

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator+(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator-(fraction<Rep, Ops> const& value) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator+(fraction<LeftRep, Ops> const& left,
          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator+(fraction<LeftRep, Ops> const& left, RightRep const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator+(LeftRep const& left, fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator+(fraction<LeftRep, LeftOps> const& left,
          fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator-(fraction<LeftRep, Ops> const& left,
          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator-(fraction<LeftRep, Ops> const& left, RightRep const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator-(LeftRep const& left, fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator-(fraction<LeftRep, LeftOps> const& left,
          fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator*(fraction<LeftRep, Ops> const& left,
          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator*(fraction<LeftRep, Ops> const& left, RightRep const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator*(LeftRep const& left, fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator*(fraction<LeftRep, LeftOps> const& left,
          fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator/(fraction<LeftRep, Ops> const& left,
          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator/(fraction<LeftRep, Ops> const& left, RightRep const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator/(LeftRep const& left, fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator/(fraction<LeftRep, LeftOps> const& left,
          fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator%(fraction<LeftRep, Ops> const& left,
          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator%(fraction<LeftRep, Ops> const& left, RightRep const& right) noexcept;

template <typename LeftRep, typename RightRep, typename Ops>
constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>
operator%(LeftRep const& left, fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator%(fraction<LeftRep, LeftOps> const& left,
          fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator+=(fraction<LeftRep, Ops>& left,
           fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator+=(fraction<LeftRep, Ops>& left,
                                             RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator+=(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator-=(fraction<LeftRep, Ops>& left,
           fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator-=(fraction<LeftRep, Ops>& left,
                                             RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator-=(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator*=(fraction<LeftRep, Ops>& left,
           fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator*=(fraction<LeftRep, Ops>& left,
                                             RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator*=(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator/=(fraction<LeftRep, Ops>& left,
           fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator/=(fraction<LeftRep, Ops>& left,
                                             RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator/=(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>&
operator%=(fraction<LeftRep, Ops>& left,
           fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::enable_if_t<std::is_convertible_v<RightRep, LeftRep>>>
constexpr fraction<LeftRep, Ops>& operator%=(fraction<LeftRep, Ops>& left,
                                             RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator%=(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator==(fraction<LeftRep, Ops> const& left,
                          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator==(fraction<LeftRep, Ops> const& left,
                          RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator==(LeftRep const& left,
                          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator==(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator!=(fraction<LeftRep, Ops> const& left,
                          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator!=(fraction<LeftRep, Ops> const& left,
                          RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator!=(LeftRep const& left,
                          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator!=(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<(fraction<LeftRep, Ops> const& left,
                         fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<(fraction<LeftRep, Ops> const& left,
                         RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<(LeftRep const& left,
                         fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator<(fraction<LeftRep, LeftOps> const& left,
          fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<=(fraction<LeftRep, Ops> const& left,
                          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<=(fraction<LeftRep, Ops> const& left,
                          RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator<=(LeftRep const& left,
                          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator<=(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>(fraction<LeftRep, Ops> const& left,
                         fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>(fraction<LeftRep, Ops> const& left,
                         RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>(LeftRep const& left,
                         fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator>(fraction<LeftRep, LeftOps> const& left,
          fraction<RightRep, RightOps> const& right) noexcept = delete;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>=(fraction<LeftRep, Ops> const& left,
                          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>=(fraction<LeftRep, Ops> const& left,
                          RightRep const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename Ops,
          typename = std::common_type_t<LeftRep, RightRep>>
constexpr bool operator>=(LeftRep const& left,
                          fraction<RightRep, Ops> const& right) noexcept;

template <typename LeftRep,
          typename RightRep,
          typename LeftOps,
          typename RightOps,
          typename = std::enable_if_t<!std::is_same_v<LeftOps, RightOps>>>
constexpr void
operator>=(fraction<LeftRep, LeftOps> const& left,
           fraction<RightRep, RightOps> const& right) noexcept = delete;


// =============================================================================


template <typename Rep, typename Ops>
std::ostream& operator<<(std::ostream& stream,
                         fraction<Rep, Ops> const& value) noexcept
{
  return stream << value.raw_;
}

template <typename Rep, typename Ops>
std::istream& operator>>(std::istream& stream,
                         fraction<Rep, Ops>& value) noexcept
{
  return stream >> value.raw_;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>::fraction(raw_fraction_type const& raw) noexcept :
  raw_ {raw}
{
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>::fraction(Rep const& numerator,
                                       Rep const& denominator) noexcept :
  raw_ {numerator, denominator}
{
}

template <typename Rep, typename Ops>
template <typename OtherRep>
constexpr fraction<Rep, Ops>::fraction(
  fraction<OtherRep, Ops> const& other) noexcept :
  raw_ {other.raw()}
{
}

template <typename Rep, typename Ops>
template <typename OtherRep, typename OtherOps>
constexpr fraction<Rep, Ops>::fraction(
  fraction<OtherRep, OtherOps> const& other) noexcept :
  raw_ {other.raw()}
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
constexpr Rep const& fraction<Rep, Ops>::numerator() const noexcept
{
  return raw_.numerator;
}

template <typename Rep, typename Ops>
constexpr Rep& fraction<Rep, Ops>::numerator() noexcept
{
  return raw_.numerator;
}

template <typename Rep, typename Ops>
constexpr Rep const& fraction<Rep, Ops>::denominator() const noexcept
{
  return raw_.denominator;
}

template <typename Rep, typename Ops>
constexpr Rep& fraction<Rep, Ops>::denominator() noexcept
{
  return raw_.denominator;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator+(fraction<Rep, Ops> const& value) noexcept
{
  return value;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator-(fraction<Rep, Ops> const& value) noexcept
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
    return Ops::function(left.raw(),                                           \
                         static_cast<common_raw_type>(right.raw()));           \
  else if constexpr (std::is_same_v<RightRep, common_rep_type>)                \
    return Ops::function(static_cast<common_raw_type>(left.raw()),             \
                         right.raw());                                         \
  else                                                                         \
    return Ops::function(static_cast<common_raw_type>(left.raw()),             \
                         static_cast<common_raw_type>(right.raw()));

#define IEME_DO_FRACTION_AND_REP_OP(function)                                  \
  using common_rep_type = std::common_type_t<LeftRep, RightRep>;               \
  using common_raw_type = raw_fraction<common_rep_type>;                       \
                                                                               \
  if constexpr (std::is_same_v<LeftRep, RightRep>)                             \
    return Ops::function(left.raw(), right);                                   \
  else if constexpr (std::is_same_v<LeftRep, common_rep_type>)                 \
    return Ops::function(left.raw(), static_cast<common_rep_type>(right));     \
  else if constexpr (std::is_same_v<RightRep, common_rep_type>)                \
    return Ops::function(static_cast<common_raw_type>(left.raw()), right);     \
  else                                                                         \
    return Ops::function(static_cast<common_raw_type>(left.raw()),             \
                         static_cast<common_rep_type>(right));

#define IEME_DO_REP_AND_FRACTION_OP(function)                                  \
  using common_rep_type = std::common_type_t<LeftRep, RightRep>;               \
  using common_raw_type = raw_fraction<common_rep_type>;                       \
                                                                               \
  if constexpr (std::is_same_v<LeftRep, RightRep>)                             \
    return Ops::function(left, right.raw());                                   \
  else if constexpr (std::is_same_v<LeftRep, common_rep_type>)                 \
    return Ops::function(left, static_cast<common_raw_type>(right.raw()));     \
  else if constexpr (std::is_same_v<RightRep, common_rep_type>)                \
    return Ops::function(static_cast<common_rep_type>(left), right.raw());     \
  else                                                                         \
    return Ops::function(static_cast<common_rep_type>(left),                   \
                         static_cast<common_raw_type>(right.raw()));

#define IEME_DEFINE_FRACTION_ARITHMETIC_OPS(symbol, function)                  \
  template <typename LeftRep, typename RightRep, typename Ops>                 \
  constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>               \
  operator symbol(fraction<LeftRep, Ops> const& left,                          \
                  fraction<RightRep, Ops> const& right) noexcept               \
  {                                                                            \
    IEME_DO_FRACTION_AND_FRACTION_OP(function)                                 \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops>                 \
  constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>               \
  operator symbol(fraction<LeftRep, Ops> const& left,                          \
                  RightRep const& right) noexcept                              \
  {                                                                            \
    IEME_DO_FRACTION_AND_REP_OP(function)                                      \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops>                 \
  constexpr fraction<std::common_type_t<LeftRep, RightRep>, Ops>               \
  operator symbol(LeftRep const& left,                                         \
                  fraction<RightRep, Ops> const& right) noexcept               \
  {                                                                            \
    IEME_DO_REP_AND_FRACTION_OP(function)                                      \
  }

IEME_DEFINE_FRACTION_ARITHMETIC_OPS(+, plus)
IEME_DEFINE_FRACTION_ARITHMETIC_OPS(-, minus)
IEME_DEFINE_FRACTION_ARITHMETIC_OPS(*, multiplies)
IEME_DEFINE_FRACTION_ARITHMETIC_OPS(/, divides)
IEME_DEFINE_FRACTION_ARITHMETIC_OPS(%, modulus)

#define IEME_DEFINE_FRACTION_COMPOUND_ASSIGNMENT_OPS(symbol)                   \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr fraction<LeftRep, Ops>& operator symbol##=(                        \
    fraction<LeftRep, Ops>& left,                                              \
    fraction<RightRep, Ops> const& right) noexcept                             \
  {                                                                            \
    if constexpr (std::is_same_v<LeftRep, RightRep>)                           \
      return left = left symbol right;                                         \
    else                                                                       \
      return left = left symbol fraction<LeftRep, Ops>(right);                 \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr fraction<LeftRep, Ops>& operator symbol##=(                        \
    fraction<LeftRep, Ops>& left, RightRep const& right) noexcept              \
  {                                                                            \
    if constexpr (std::is_same_v<LeftRep, RightRep>)                           \
      return left = left symbol right;                                         \
    else                                                                       \
      return left = left symbol static_cast<LeftRep>(right);                   \
  }

IEME_DEFINE_FRACTION_COMPOUND_ASSIGNMENT_OPS(+)
IEME_DEFINE_FRACTION_COMPOUND_ASSIGNMENT_OPS(-)
IEME_DEFINE_FRACTION_COMPOUND_ASSIGNMENT_OPS(*)
IEME_DEFINE_FRACTION_COMPOUND_ASSIGNMENT_OPS(/)
IEME_DEFINE_FRACTION_COMPOUND_ASSIGNMENT_OPS(%)

#define IEME_DEFINE_FRACTION_COMPARISON_OPS(symbol, function)                  \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr bool operator symbol(                                              \
    fraction<LeftRep, Ops> const& left,                                        \
    fraction<RightRep, Ops> const& right) noexcept                             \
  {                                                                            \
    IEME_DO_FRACTION_AND_FRACTION_OP(function)                                 \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr bool operator symbol(fraction<LeftRep, Ops> const& left,           \
                                 RightRep const& right) noexcept               \
  {                                                                            \
    IEME_DO_FRACTION_AND_REP_OP(function)                                      \
  }                                                                            \
                                                                               \
  template <typename LeftRep, typename RightRep, typename Ops, typename>       \
  constexpr bool operator symbol(                                              \
    LeftRep const& left, fraction<RightRep, Ops> const& right) noexcept        \
  {                                                                            \
    IEME_DO_REP_AND_FRACTION_OP(function)                                      \
  }

IEME_DEFINE_FRACTION_COMPARISON_OPS(==, equal_to)
IEME_DEFINE_FRACTION_COMPARISON_OPS(!=, not_equal_to)
IEME_DEFINE_FRACTION_COMPARISON_OPS(<, less)
IEME_DEFINE_FRACTION_COMPARISON_OPS(<=, less_equal)
IEME_DEFINE_FRACTION_COMPARISON_OPS(>, greater)
IEME_DEFINE_FRACTION_COMPARISON_OPS(>=, greater_equal)


}; // namespace ieme


#endif
