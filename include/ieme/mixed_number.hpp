#ifndef IEME_MIXED_NUMBER_HPP
#define IEME_MIXED_NUMBER_HPP

#include <ieme/fraction.hpp>
#include <ieme/fraction_math.hpp>
#include <ieme/fraction_queries.hpp>


namespace ieme {


template <typename WRep, typename FRep = WRep, typename Ops = ops::defaults>
class mixed_number {

public:
  using whole_type = WRep;
  using fractional_rep_type = FRep;
  using ops_type = Ops;
  using fractional_type = fraction<fractional_rep_type, ops_type>;
  using common_rep_type = std::common_type_t<whole_type, fractional_rep_type>;

  constexpr mixed_number() noexcept = default;

  constexpr mixed_number(whole_type const& whole,
                         fractional_type const& fractional = {}) noexcept;

  template <typename OtherFRep>
  constexpr mixed_number(fraction<OtherFRep, ops_type> const& value) noexcept;

  template <typename OtherFRep, typename OtherOps>
  explicit constexpr mixed_number(
    fraction<OtherFRep, OtherOps> const& value) noexcept;

  constexpr fraction<common_rep_type, ops_type> as_fraction() const noexcept;

  constexpr operator fraction<common_rep_type, ops_type>() const noexcept;

  constexpr whole_type const& whole() const noexcept;

  constexpr fractional_type const& fractional() const noexcept;

private:
  constexpr void fix() noexcept;

  whole_type whole_ = {};
  fractional_type fractional_ = {};
};

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>
operator+(mixed_number<WRep, FRep, Ops> const& value) noexcept;

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>
operator-(mixed_number<WRep, FRep, Ops> const& value) noexcept;

template <typename WRep1,
          typename FRep1,
          typename WRep2,
          typename FRep2,
          typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(mixed_number<WRep1, FRep1, Ops> const& left,
          mixed_number<WRep2, FRep2, Ops> const& right) noexcept;

template <typename WRep1, typename FRep1, typename FRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, FRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(mixed_number<WRep1, FRep1, Ops> const& left,
          fraction<FRep2, Ops> const& right) noexcept;

template <typename WRep1, typename FRep1, typename FRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, FRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(fraction<FRep2, Ops> const& left,
          mixed_number<WRep1, FRep1, Ops> const& right) noexcept;

template <typename WRep1, typename FRep, typename WRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>, FRep, Ops>
operator+(mixed_number<WRep1, FRep, Ops> const& left,
          WRep2 const& right) noexcept;

template <typename WRep1, typename WRep2, typename FRep, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>, FRep, Ops>
operator+(WRep1 const& left,
          mixed_number<WRep2, FRep, Ops> const& right) noexcept;


// =============================================================================


template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>::mixed_number(
  whole_type const& whole,
  fractional_type const& fractional) noexcept :
  whole_ {whole}, fractional_ {fractional}
{
  fix();
}

template <typename WRep, typename FRep, typename Ops>
template <typename OtherFRep>
constexpr mixed_number<WRep, FRep, Ops>::mixed_number(
  fraction<OtherFRep, ops_type> const& value) noexcept :
  whole_ {whole_type(trunc(value))},
  fractional_ {fractional_type(value - static_cast<OtherFRep>(whole_))}
{
}

template <typename WRep, typename FRep, typename Ops>
template <typename OtherFRep, typename OtherOps>
constexpr mixed_number<WRep, FRep, Ops>::mixed_number(
  fraction<OtherFRep, OtherOps> const& value) noexcept :
  mixed_number {fraction<OtherFRep, Ops>(value)}
{
}

template <typename WRep, typename FRep, typename Ops>
constexpr auto mixed_number<WRep, FRep, Ops>::as_fraction() const noexcept
  -> fraction<common_rep_type, ops_type>
{
  return common_rep_type(whole_)
         + fraction<common_rep_type, ops_type>(fractional_);
}

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>::operator fraction<common_rep_type,
                                                           ops_type>()
  const noexcept
{
  return as_fraction();
}

template <typename WRep, typename FRep, typename Ops>
constexpr auto mixed_number<WRep, FRep, Ops>::whole() const noexcept
  -> whole_type const&
{
  return whole_;
}

template <typename WRep, typename FRep, typename Ops>
constexpr auto mixed_number<WRep, FRep, Ops>::fractional() const noexcept
  -> fractional_type const&
{
  return fractional_;
}

template <typename WRep, typename FRep, typename Ops>
constexpr void mixed_number<WRep, FRep, Ops>::fix() noexcept
{
  if (is_improper(fractional_))
  {
    auto const truncated_fractional = trunc(fractional_);

    whole_ += static_cast<whole_type>(truncated_fractional);
    fractional_ -= truncated_fractional;
  }

  if (whole_ > _0<whole_type> && is_negative(fractional_))
  {
    whole_ -= _1<whole_type>;
    fractional_ = _1<fractional_rep_type> + fractional_;
  }
  else if (whole_ < _0<whole_type> && is_positive(fractional_))
  {
    whole_ += _1<whole_type>;
    fractional_ = -_1<fractional_rep_type> + fractional_;
  }
}

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>
operator+(mixed_number<WRep, FRep, Ops> const& value) noexcept
{
  return value;
}

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>
operator-(mixed_number<WRep, FRep, Ops> const& value) noexcept
{
  return {-value.whole(), -value.fractional()};
}

template <typename WRep1,
          typename FRep1,
          typename WRep2,
          typename FRep2,
          typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(mixed_number<WRep1, FRep1, Ops> const& left,
          mixed_number<WRep2, FRep2, Ops> const& right) noexcept
{
  using whole_type = std::common_type_t<WRep1, WRep2>;
  using fractional_type = ieme::fraction<std::common_type_t<FRep1, FRep2>, Ops>;

  auto const whole = static_cast<whole_type>(left.whole())
                     + static_cast<whole_type>(right.whole());
  auto const fractional = static_cast<fractional_type>(left.fractional())
                          + static_cast<fractional_type>(right.fractional());

  return {whole, fractional};
}

template <typename WRep, typename FRep1, typename FRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep, FRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(mixed_number<WRep, FRep1, Ops> const& left,
          fraction<FRep2, Ops> const& right) noexcept
{
  return left + mixed_number<FRep2, FRep2, Ops>(right);
}

template <typename WRep1, typename FRep1, typename FRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, FRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(fraction<FRep2, Ops> const& left,
          mixed_number<WRep1, FRep1, Ops> const& right) noexcept
{
  return right + left;
}

template <typename WRep1, typename FRep, typename WRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>, FRep, Ops>
operator+(mixed_number<WRep1, FRep, Ops> const& left,
          WRep2 const& right) noexcept
{
  using whole_type = std::common_type_t<WRep1, WRep2>;

  return {static_cast<whole_type>(left.whole())
            + static_cast<whole_type>(right),
          left.fractional()};
}

template <typename WRep1, typename WRep2, typename FRep, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>, FRep, Ops>
operator+(WRep1 const& left,
          mixed_number<WRep2, FRep, Ops> const& right) noexcept
{
  return right + left;
}


}; // namespace ieme


#endif
