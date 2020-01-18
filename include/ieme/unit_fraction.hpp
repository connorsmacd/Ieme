#pragma once

#include <ieme/fraction.hpp>


namespace ieme {


template <typename Rep, typename Ops = safe_ops>
class unit_fraction final {

public:
    using fraction_type = fraction<Rep, Ops>;
    using rep_type = typename fraction<Rep, Ops>::rep_type;
    using ops_type = typename fraction<Rep, Ops>::ops_type;

    constexpr unit_fraction() noexcept = default;
    constexpr unit_fraction(const Rep& denominator) noexcept;

    constexpr fraction<Rep, Ops> as_fraction() const noexcept;
    constexpr operator fraction<Rep, Ops>() const noexcept;

    constexpr const Rep& denominator() const noexcept { return denominator_; }

private:
    Rep denominator_ = 1;
};

template <typename Rep, typename Ops>
constexpr unit_fraction<Rep, Ops>
unit_of(const fraction<Rep, Ops>& value) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr unit_fraction<Rep, Ops>::unit_fraction(
    const Rep& denominator) noexcept :
    denominator_ {denominator}
{
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> unit_fraction<Rep, Ops>::as_fraction() const
    noexcept
{
    return {1, denominator_};
}

template <typename Rep, typename Ops>
constexpr unit_fraction<Rep, Ops>::operator fraction<Rep, Ops>() const noexcept
{
    return as_fraction();
}

template <typename Rep, typename Ops>
constexpr unit_fraction<Rep, Ops>
unit_of(const fraction<Rep, Ops>& value) noexcept
{
    return is_positive(value)
               ? ((value.denominator() > 0) ? value.denominator()
                                            : -value.denominator())
               : ((value.denominator() > 0) ? -value.denominator()
                                            : value.denominator());
}


}; // namespace ieme
