#pragma once

#include <ieme/fraction.hpp>


namespace ieme {


class safe_ops {

public:
    template <typename Rep>
    static constexpr fraction<Rep, safe_ops>
    add(const fraction<Rep, safe_ops>& left,
        const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr fraction<Rep, safe_ops>
    subtract(const fraction<Rep, safe_ops>& left,
             const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr fraction<Rep, safe_ops>
    multiply(const fraction<Rep, safe_ops>& left,
             const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr fraction<Rep, safe_ops>
    divide(const fraction<Rep, safe_ops>& left,
           const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr fraction<Rep, safe_ops>
    remainder(const fraction<Rep, safe_ops>& left,
              const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr bool
    equal_to(const fraction<Rep, safe_ops>& left,
             const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr bool
    not_equal_to(const fraction<Rep, safe_ops>& left,
                 const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr bool
    less_than(const fraction<Rep, safe_ops>& left,
              const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr bool
    less_than_or_equal_to(const fraction<Rep, safe_ops>& left,
                          const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr bool
    greater_than(const fraction<Rep, safe_ops>& left,
                 const fraction<Rep, safe_ops>& right) noexcept;

    template <typename Rep>
    static constexpr bool
    greater_than_or_equal_to(const fraction<Rep, safe_ops>& left,
                             const fraction<Rep, safe_ops>& right) noexcept;
};


// =============================================================================


template <typename Rep>
constexpr fraction<Rep, safe_ops>
safe_ops::add(const fraction<Rep, safe_ops>& left,
              const fraction<Rep, safe_ops>& right) noexcept
{
    const auto lcm = std::lcm(left.denominator(), right.denominator());

    return reduce(fraction<Rep, safe_ops>(
        lcm / left.denominator() * left.numerator()
            + lcm / right.denominator() * right.numerator(),
        lcm));
}

template <typename Rep>
constexpr fraction<Rep, safe_ops>
safe_ops::subtract(const fraction<Rep, safe_ops>& left,
                   const fraction<Rep, safe_ops>& right) noexcept
{
    const auto lcm = std::lcm(left.denominator(), right.denominator());

    return reduce(fraction<Rep, safe_ops>(
        lcm / left.denominator() * left.numerator()
            - lcm / right.denominator() * right.numerator(),
        lcm));
}

template <typename Rep>
constexpr fraction<Rep, safe_ops>
safe_ops::multiply(const fraction<Rep, safe_ops>& left,
                   const fraction<Rep, safe_ops>& right) noexcept
{
    return reduce(
        fraction<Rep, safe_ops>(left.numerator() * right.numerator(),
                                left.denominator() * right.denominator()));
}

template <typename Rep>
constexpr fraction<Rep, safe_ops>
safe_ops::divide(const fraction<Rep, safe_ops>& left,
                 const fraction<Rep, safe_ops>& right) noexcept
{
    return multiply(left, reciprocal(right));
}

template <typename Rep>
constexpr fraction<Rep, safe_ops>
safe_ops::remainder(const fraction<Rep, safe_ops>& left,
                    const fraction<Rep, safe_ops>& right) noexcept
{
    const auto lcm = std::lcm(left.denominator(), right.denominator());

    return reduce(fraction<Rep, safe_ops>(
        (lcm / left.denominator() * left.numerator())
            % (lcm / right.denominator() * right.numerator()),
        lcm));
}

template <typename Rep>
constexpr bool safe_ops::equal_to(const fraction<Rep, safe_ops>& left,
                                  const fraction<Rep, safe_ops>& right) noexcept
{
    if (is_undefined(left) || is_undefined(right))
        return false;

    const auto lcm = std::lcm(left.denominator(), right.denominator());

    return lcm / left.denominator() * left.numerator()
           == lcm / right.denominator() * right.numerator();
}

template <typename Rep>
constexpr bool
safe_ops::not_equal_to(const fraction<Rep, safe_ops>& left,
                       const fraction<Rep, safe_ops>& right) noexcept
{
    return !equal_to(left, right);
}

template <typename Rep>
constexpr bool
safe_ops::less_than(const fraction<Rep, safe_ops>& left,
                    const fraction<Rep, safe_ops>& right) noexcept
{
    if (is_undefined(left) || is_undefined(right))
        return false;

    const auto lcm = std::lcm(left.denominator(), right.denominator());

    return lcm / left.denominator() * left.numerator()
           < lcm / right.denominator() * right.numerator();
}

template <typename Rep>
constexpr bool
safe_ops::less_than_or_equal_to(const fraction<Rep, safe_ops>& left,
                                const fraction<Rep, safe_ops>& right) noexcept
{
    if (is_undefined(left) || is_undefined(right))
        return false;

    const auto lcm = std::lcm(left.denominator(), right.denominator());

    return lcm / left.denominator() * left.numerator()
           <= lcm / right.denominator() * right.numerator();
}

template <typename Rep>
constexpr bool
safe_ops::greater_than(const fraction<Rep, safe_ops>& left,
                       const fraction<Rep, safe_ops>& right) noexcept
{
    if (is_undefined(left) || is_undefined(right))
        return false;

    const auto lcm = std::lcm(left.denominator(), right.denominator());

    return lcm / left.denominator() * left.numerator()
           > lcm / right.denominator() * right.numerator();
}

template <typename Rep>
constexpr bool safe_ops::greater_than_or_equal_to(
    const fraction<Rep, safe_ops>& left,
    const fraction<Rep, safe_ops>& right) noexcept
{
    if (is_undefined(left) || is_undefined(right))
        return false;

    const auto lcm = std::lcm(left.denominator(), right.denominator());

    return lcm / left.denominator() * left.numerator()
           >= lcm / right.denominator() * right.numerator();
}


}; // namespace ieme
