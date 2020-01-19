#pragma once

#include <ieme/fraction.hpp>


namespace ieme {
namespace literals {


template <typename Rep, typename Ops = safe_ops>
class fraction_literal final {

public:
    using fraction_type = fraction<Rep, Ops>;
    using rep_type = typename fraction<Rep, Ops>::rep_type;
    using ops_type = typename fraction<Rep, Ops>::ops_type;

    constexpr fraction_literal(const Rep& numerator) noexcept;

    constexpr fraction<Rep, Ops> as_fraction() const noexcept;
    constexpr operator fraction<Rep, Ops>() const noexcept;

    constexpr const Rep& numerator() const noexcept { return numerator_; }

private:
    Rep numerator_;
};

template <typename Rep, typename Ops>
constexpr fraction_literal<Rep, Ops>
operator+(const fraction_literal<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction_literal<Rep, Ops>
operator-(const fraction_literal<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const Rep& left, const fraction_literal<Rep, Ops>& right) noexcept;

constexpr fraction_literal<int>
operator""_Fr(unsigned long long int value) noexcept;

constexpr fraction_literal<unsigned int>
operator""_uFr(unsigned long long int value) noexcept;

constexpr fraction_literal<long int>
operator""_lFr(unsigned long long int value) noexcept;

constexpr fraction_literal<unsigned long int>
operator""_ulFr(unsigned long long int value) noexcept;

constexpr fraction_literal<long long int>
operator""_llFr(unsigned long long int value) noexcept;

constexpr fraction_literal<unsigned long long int>
operator""_ullFr(unsigned long long int value) noexcept;


// =============================================================================


template <typename Rep, typename Ops>
constexpr fraction_literal<Rep, Ops>::fraction_literal(
    const Rep& numerator) noexcept :
    numerator_ {numerator}
{
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> fraction_literal<Rep, Ops>::as_fraction() const
    noexcept
{
    return {numerator_, 1};
}

template <typename Rep, typename Ops>
constexpr fraction_literal<Rep, Ops>::operator fraction<Rep, Ops>() const
    noexcept
{
    return as_fraction();
}

template <typename Rep, typename Ops>
constexpr fraction_literal<Rep, Ops>
operator+(const fraction_literal<Rep, Ops>& value) noexcept
{
    return value;
}

template <typename Rep, typename Ops>
constexpr fraction_literal<Rep, Ops>
operator-(const fraction_literal<Rep, Ops>& value) noexcept
{
    return -value.numerator();
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const Rep& left, const fraction_literal<Rep, Ops>& right) noexcept
{
    return {left, right.numerator()};
}

constexpr fraction_literal<int>
operator""_Fr(const unsigned long long int value) noexcept
{
    return value;
}

constexpr fraction_literal<unsigned int>
operator""_uFr(const unsigned long long int value) noexcept
{
    return value;
}

constexpr fraction_literal<long int>
operator""_lFr(const unsigned long long int value) noexcept
{
    return value;
}

constexpr fraction_literal<unsigned long int>
operator""_ulFr(const unsigned long long int value) noexcept
{
    return value;
}

constexpr fraction_literal<long long int>
operator""_llFr(const unsigned long long int value) noexcept
{
    return value;
}

constexpr fraction_literal<unsigned long long int>
operator""_ullFr(const unsigned long long int value) noexcept
{
    return value;
}


}; // namespace literals
}; // namespace ieme
