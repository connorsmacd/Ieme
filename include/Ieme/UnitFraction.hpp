#pragma once

#include <Ieme/Fraction.hpp>


namespace Ieme {


class UnitFraction final {

public:
    constexpr UnitFraction() noexcept = default;
    constexpr UnitFraction(long long denominator) noexcept;

    constexpr Fraction asFraction() const noexcept { return {1, denominator_}; }
    constexpr operator Fraction() const noexcept { return asFraction(); }

private:
    long long denominator_ = 1;
};

constexpr UnitFraction unitOf(const Fraction& fraction) noexcept;


// =================================================================================================


constexpr UnitFraction::UnitFraction(const long long denominator) noexcept :
    denominator_ {denominator}
{
}

constexpr UnitFraction unitOf(const Fraction& fraction) noexcept
{
    return isPositive(fraction)
               ? ((fraction.denominator() > 0) ? fraction.denominator() : -fraction.denominator())
               : ((fraction.denominator() > 0) ? -fraction.denominator() : fraction.denominator());
}


}; // namespace Ieme
