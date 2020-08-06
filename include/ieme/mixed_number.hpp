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

  constexpr mixed_number(const whole_type& whole,
                         const fractional_type& fractional = {}) noexcept;

  template <typename OtherFRep>
  constexpr mixed_number(const fraction<OtherFRep, ops_type>& value) noexcept;

  template <typename OtherFRep, typename OtherOps>
  explicit constexpr mixed_number(
    const fraction<OtherFRep, OtherOps>& value) noexcept;

  constexpr fraction<common_rep_type, ops_type> as_fraction() const noexcept;

  constexpr operator fraction<common_rep_type, ops_type>() const noexcept;

  constexpr const whole_type& whole() const noexcept;

  constexpr const fractional_type& fractional() const noexcept;

private:
  constexpr void fix() noexcept;

  whole_type whole_ = {};
  fractional_type fractional_ = {};
};

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>
operator+(const mixed_number<WRep, FRep, Ops>& value) noexcept;

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>
operator-(const mixed_number<WRep, FRep, Ops>& value) noexcept;

template <typename WRep1,
          typename FRep1,
          typename WRep2,
          typename FRep2,
          typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(const mixed_number<WRep1, FRep1, Ops>& left,
          const mixed_number<WRep2, FRep2, Ops>& right) noexcept;

template <typename WRep1, typename FRep1, typename FRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, FRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(const mixed_number<WRep1, FRep1, Ops>& left,
          const fraction<FRep2, Ops>& right) noexcept;

template <typename WRep1, typename FRep1, typename FRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, FRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(const fraction<FRep2, Ops>& left,
          const mixed_number<WRep1, FRep1, Ops>& right) noexcept;

template <typename WRep1, typename FRep, typename WRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>, FRep, Ops>
operator+(const mixed_number<WRep1, FRep, Ops>& left,
          const WRep2& right) noexcept;

template <typename WRep1, typename WRep2, typename FRep, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>, FRep, Ops>
operator+(const WRep1& left,
          const mixed_number<WRep2, FRep, Ops>& right) noexcept;


// =============================================================================


template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>::mixed_number(
  const whole_type& whole,
  const fractional_type& fractional) noexcept :
  whole_ {whole},
  fractional_ {fractional}
{
  fix();
}

template <typename WRep, typename FRep, typename Ops>
template <typename OtherFRep>
constexpr mixed_number<WRep, FRep, Ops>::mixed_number(
  const fraction<OtherFRep, ops_type>& value) noexcept :
  whole_ {whole_type(trunc(value))},
  fractional_ {fractional_type(value - OtherFRep(whole_))}
{
}

template <typename WRep, typename FRep, typename Ops>
template <typename OtherFRep, typename OtherOps>
constexpr mixed_number<WRep, FRep, Ops>::mixed_number(
  const fraction<OtherFRep, OtherOps>& value) noexcept :
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
constexpr mixed_number<WRep, FRep, Ops>::
operator fraction<common_rep_type, ops_type>() const noexcept
{
  return as_fraction();
}

template <typename WRep, typename FRep, typename Ops>
constexpr auto mixed_number<WRep, FRep, Ops>::whole() const noexcept
  -> const whole_type&
{
  return whole_;
}

template <typename WRep, typename FRep, typename Ops>
constexpr auto mixed_number<WRep, FRep, Ops>::fractional() const noexcept
  -> const fractional_type&
{
  return fractional_;
}

template <typename WRep, typename FRep, typename Ops>
constexpr void mixed_number<WRep, FRep, Ops>::fix() noexcept
{
  if (is_improper(fractional_))
  {
    const auto truncated_fractional = trunc(fractional_);

    whole_ += whole_type(truncated_fractional);
    fractional_ -= truncated_fractional;
  }

  if (whole_ > 0 && is_negative(fractional_))
  {
    whole_ -= whole_type(1);
    fractional_ = fractional_rep_type(1) + fractional_;
  }
  else if (whole_ < 0 && is_positive(fractional_))
  {
    whole_ += whole_type(1);
    fractional_ = fractional_rep_type(-1) + fractional_;
  }
}

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>
operator+(const mixed_number<WRep, FRep, Ops>& value) noexcept
{
  return value;
}

template <typename WRep, typename FRep, typename Ops>
constexpr mixed_number<WRep, FRep, Ops>
operator-(const mixed_number<WRep, FRep, Ops>& value) noexcept
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
operator+(const mixed_number<WRep1, FRep1, Ops>& left,
          const mixed_number<WRep2, FRep2, Ops>& right) noexcept
{
  using whole_type = std::common_type_t<WRep1, WRep2>;
  using fractional_type = ieme::fraction<std::common_type_t<FRep1, FRep2>, Ops>;

  const auto whole = static_cast<whole_type>(left.whole())
                     + static_cast<whole_type>(right.whole());
  const auto fractional = static_cast<fractional_type>(left.fractional())
                          + static_cast<fractional_type>(right.fractional());

  return {whole, fractional};
}

template <typename WRep, typename FRep1, typename FRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep, FRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(const mixed_number<WRep, FRep1, Ops>& left,
          const fraction<FRep2, Ops>& right) noexcept
{
  return left + mixed_number<FRep2, FRep2, Ops>(right);
}

template <typename WRep1, typename FRep1, typename FRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, FRep2>,
                       std::common_type_t<FRep1, FRep2>,
                       Ops>
operator+(const fraction<FRep2, Ops>& left,
          const mixed_number<WRep1, FRep1, Ops>& right) noexcept
{
  return right + left;
}

template <typename WRep1, typename FRep, typename WRep2, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>, FRep, Ops>
operator+(const mixed_number<WRep1, FRep, Ops>& left,
          const WRep2& right) noexcept
{
  using whole_type = std::common_type_t<WRep1, WRep2>;

  return {static_cast<whole_type>(left.whole())
            + static_cast<whole_type>(right),
          left.fractional()};
}

template <typename WRep1, typename WRep2, typename FRep, typename Ops>
constexpr mixed_number<std::common_type_t<WRep1, WRep2>, FRep, Ops>
operator+(const WRep1& left,
          const mixed_number<WRep2, FRep, Ops>& right) noexcept
{
  return right + left;
}


}; // namespace ieme


#endif
