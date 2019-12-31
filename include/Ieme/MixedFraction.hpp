#pragma once

#include <Ieme/Fraction.hpp>


namespace Ieme {


class MixedFraction final {

public:
    constexpr MixedFraction() noexcept = default;
    constexpr MixedFraction(long long wholePart, const Fraction& fractionalPart) noexcept;
    constexpr MixedFraction(const Fraction& fraction) noexcept;

    constexpr Fraction asFraction() const noexcept;
    constexpr operator Fraction() const noexcept { return asFraction(); }

    long long wholePart() const noexcept { return wholePart_; }
    Fraction fractionalPart() const noexcept { return fractionalPart_; }

private:
    static constexpr Fraction combine(long long wholePart, const Fraction& fractionalPart) noexcept;

    long long wholePart_ = 0;
    Fraction fractionalPart_;
};


// =================================================================================================


constexpr MixedFraction::MixedFraction(const long long wholePart,
                                       const Fraction& fractionalPart) noexcept :
    MixedFraction {combine(wholePart, fractionalPart)}
{
}

constexpr MixedFraction::MixedFraction(const Fraction& fraction) noexcept :
    wholePart_ {trunc(fraction)},
    fractionalPart_ {abs(fraction - wholePart_)}
{
}

constexpr Fraction MixedFraction::asFraction() const noexcept
{
    return combine(wholePart_, fractionalPart_);
}

constexpr Fraction MixedFraction::combine(const long long wholePart,
                                          const Fraction& fractionalPart) noexcept
{
    return (wholePart > 0) ? wholePart + fractionalPart : wholePart - fractionalPart;
}


}; // namespace Ieme
