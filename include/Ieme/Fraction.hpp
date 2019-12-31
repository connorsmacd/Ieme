#pragma once

#include <istream>
#include <numeric>
#include <ostream>
#include <utility>


namespace Ieme {


class UnitFraction;


class Fraction final {

public:
    constexpr Fraction() = default;
    constexpr Fraction(long long numerator, long long denominator = 1) noexcept;

    constexpr long long numerator() const noexcept { return numerator_; }
    constexpr long long denominator() const noexcept { return denominator_; }

    constexpr Fraction withNumerator(long long numerator) const noexcept;
    constexpr Fraction withDenominator(long long denominator) const noexcept;
    constexpr Fraction withSwitchedSignPosition() const noexcept;
    constexpr Fraction withMinimalNegativeSigns() const noexcept;

    friend std::ostream& operator<<(std::ostream& stream, const Fraction& fraction) noexcept;
    friend std::istream& operator>>(std::istream& stream, Fraction& fraction) noexcept;

private:
    long long numerator_ = 0, denominator_ = 1;
};

constexpr Fraction operator+(const Fraction& fraction) noexcept;
constexpr Fraction operator-(const Fraction& fraction) noexcept;

constexpr Fraction operator+(const Fraction& augend, const Fraction& addend) noexcept;
constexpr Fraction operator-(const Fraction& minuend, const Fraction& subtrahend) noexcept;
constexpr Fraction operator*(const Fraction& multiplicand, const Fraction& multiplier) noexcept;
constexpr Fraction operator/(const Fraction& dividend, const Fraction& divisor) noexcept;
constexpr Fraction operator%(const Fraction& dividend, const Fraction& divisor) noexcept;

constexpr Fraction& operator+=(Fraction& augend, const Fraction& addend) noexcept;
constexpr Fraction& operator-=(Fraction& minuend, const Fraction& subtrahend) noexcept;
constexpr Fraction& operator*=(Fraction& multiplicand, const Fraction& multiplier) noexcept;
constexpr Fraction& operator/=(Fraction& dividend, const Fraction& divisor) noexcept;
constexpr Fraction& operator%=(Fraction& dividend, const Fraction& divisor) noexcept;

constexpr bool operator==(const Fraction& left, const Fraction& right) noexcept;
constexpr bool operator!=(const Fraction& left, const Fraction& right) noexcept;
constexpr bool operator<(const Fraction& left, const Fraction& right) noexcept;
constexpr bool operator<=(const Fraction& left, const Fraction& right) noexcept;
constexpr bool operator>(const Fraction& left, const Fraction& right) noexcept;
constexpr bool operator>=(const Fraction& left, const Fraction& right) noexcept;

constexpr bool symbolicallyEqual(const Fraction& left, const Fraction& right) noexcept;
constexpr bool notSymbolicallyEqual(const Fraction& left, const Fraction& right) noexcept;

constexpr long long numerator(const Fraction& fraction) noexcept;
constexpr long long denominator(const Fraction& fraction) noexcept;

constexpr Fraction reduce(const Fraction& fraction) noexcept;

constexpr Fraction reciprocalOf(const Fraction& fraction) noexcept;

constexpr UnitFraction unitOf(const Fraction& fraction) noexcept;

constexpr long double toDecimal(const Fraction& fraction) noexcept;

constexpr Fraction fractionPow2(int exponent) noexcept;

constexpr long long ceil(const Fraction& fraction) noexcept;
constexpr long long floor(const Fraction& fraction) noexcept;
constexpr long long trunc(const Fraction& fraction) noexcept;
constexpr long long round(const Fraction& fraction) noexcept;

constexpr Fraction abs(const Fraction& fraction) noexcept;

constexpr std::size_t numNegativeSigns(const Fraction& fraction) noexcept;

constexpr bool isPositive(const Fraction& fraction) noexcept;
constexpr bool isNegative(const Fraction& fraction) noexcept;
constexpr bool isZero(const Fraction& fraction) noexcept;
constexpr bool isInteger(const Fraction& fraction) noexcept;
constexpr bool isUnitFraction(const Fraction& fraction) noexcept;
constexpr bool isDefined(const Fraction& fraction) noexcept;
constexpr bool isUndefined(const Fraction& fraction) noexcept;


class UnitFraction final {

public:
    constexpr UnitFraction() noexcept = default;
    constexpr UnitFraction(long long denominator) noexcept;

    constexpr Fraction asFraction() const noexcept { return {1, denominator_}; }
    constexpr operator Fraction() const noexcept { return asFraction(); }

private:
    long long denominator_ = 1;
};


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


constexpr Fraction::Fraction(const long long numerator, const long long denominator) noexcept :
    numerator_ {numerator},
    denominator_ {denominator}
{
}

constexpr Fraction Fraction::withNumerator(const long long numerator) const noexcept
{
    return {numerator, denominator_};
}

constexpr Fraction Fraction::withDenominator(const long long denominator) const noexcept
{
    return {numerator_, denominator};
}

constexpr Fraction Fraction::withSwitchedSignPosition() const noexcept
{
    if (isPositive(*this))
        return *this;

    return {-numerator_, -denominator_};
}

constexpr Fraction Fraction::withMinimalNegativeSigns() const noexcept
{
    if (numNegativeSigns(*this) < 2)
        return *this;

    return {-numerator_, -denominator_};
}

constexpr Fraction operator+(const Fraction& fraction) noexcept
{
    return fraction;
}

constexpr Fraction operator-(const Fraction& fraction) noexcept
{
    return {-fraction.numerator(), fraction.denominator()};
}

constexpr Fraction operator+(const Fraction& augend, const Fraction& addend) noexcept
{
    if (augend.denominator() == addend.denominator())
        return {augend.numerator() + addend.numerator(), augend.denominator()};

    return {augend.numerator() * addend.denominator() + addend.numerator() * augend.denominator(),
            augend.denominator() * addend.denominator()};
}

constexpr Fraction operator-(const Fraction& minuend, const Fraction& subtrahend) noexcept
{
    return minuend + -subtrahend;
}

constexpr Fraction operator*(const Fraction& multiplicand, const Fraction& multiplier) noexcept
{
    return {multiplicand.numerator() * multiplier.numerator(),
            multiplicand.denominator() * multiplier.denominator()};
}

constexpr Fraction operator/(const Fraction& dividend, const Fraction& divisor) noexcept
{
    return dividend * reciprocalOf(divisor);
}

constexpr Fraction operator%(const Fraction& dividend, const Fraction& divisor) noexcept
{
    if (dividend.denominator() == divisor.denominator())
        return {dividend.numerator() % divisor.numerator(), dividend.denominator()};

    return {(dividend.numerator() * divisor.denominator())
                % (divisor.numerator() * dividend.denominator()),
            dividend.denominator() * divisor.denominator()};
}

constexpr Fraction& operator+=(Fraction& augend, const Fraction& addend) noexcept
{
    return augend = augend + addend;
}

constexpr Fraction& operator-=(Fraction& minuend, const Fraction& subtrahend) noexcept
{
    return minuend = minuend - subtrahend;
}

constexpr Fraction& operator*=(Fraction& multiplicand, const Fraction& multiplier) noexcept
{
    return multiplicand = multiplicand * multiplier;
}

constexpr Fraction& operator/=(Fraction& dividend, const Fraction& divisor) noexcept
{
    return dividend = dividend / divisor;
}

constexpr Fraction& operator%=(Fraction& dividend, const Fraction& divisor) noexcept
{
    return dividend = dividend % divisor;
}

constexpr bool operator==(const Fraction& left, const Fraction& right) noexcept
{
    if (isUndefined(left) || isUndefined(right))
        return false;

    return left.numerator() * right.denominator() == right.numerator() * left.denominator();
}

constexpr bool operator!=(const Fraction& left, const Fraction& right) noexcept
{
    return !(left == right);
}

constexpr bool operator<(const Fraction& left, const Fraction& right) noexcept
{
    if (isUndefined(left) || isUndefined(right))
        return false;

    return left.numerator() * right.denominator() < right.numerator() * left.denominator();
}

constexpr bool operator<=(const Fraction& left, const Fraction& right) noexcept
{
    if (isUndefined(left) || isUndefined(right))
        return false;

    return left.numerator() * right.denominator() <= right.numerator() * left.denominator();
}

constexpr bool operator>(const Fraction& left, const Fraction& right) noexcept
{
    if (isUndefined(left) || isUndefined(right))
        return false;

    return left.numerator() * right.denominator() > right.numerator() * left.denominator();
}

constexpr bool operator>=(const Fraction& left, const Fraction& right) noexcept
{
    if (isUndefined(left) || isUndefined(right))
        return false;

    return left.numerator() * right.denominator() >= right.numerator() * left.denominator();
}

constexpr bool symbolicallyEqual(const Fraction& left, const Fraction& right) noexcept
{
    return left.numerator() == right.numerator() && left.denominator() == right.denominator();
}

constexpr bool notSymbolicallyEqual(const Fraction& left, const Fraction& right) noexcept
{
    return !symbolicallyEqual(left, right);
}

constexpr long long numerator(const Fraction& fraction) noexcept
{
    return fraction.numerator();
}

constexpr long long denominator(const Fraction& fraction) noexcept
{
    return fraction.denominator();
}

constexpr Fraction reduce(const Fraction& fraction) noexcept
{
    const auto gcd = std::gcd(fraction.numerator(), fraction.denominator());

    return Fraction(fraction.numerator() / gcd, fraction.denominator() / gcd)
        .withMinimalNegativeSigns();
}

constexpr Fraction reciprocalOf(const Fraction& fraction) noexcept
{
    return {fraction.denominator(), fraction.numerator()};
}

constexpr UnitFraction unitOf(const Fraction& fraction) noexcept
{
    return isPositive(fraction) ? std::abs(fraction.denominator())
                                : -std::abs(fraction.denominator());
}

constexpr long double toDecimal(const Fraction& fraction) noexcept
{
    return static_cast<long double>(fraction.numerator())
           / static_cast<long double>(fraction.denominator());
}

constexpr Fraction fractionPow2(const int exponent) noexcept
{
    return (exponent >= 0) ? Fraction(static_cast<long long>(1ULL << exponent))
                           : Fraction(1, static_cast<long long>(1ULL << -exponent));
}

constexpr long long ceil(const Fraction& fraction) noexcept
{
    const auto truncated = trunc(fraction);

    if (isInteger(fraction))
        return truncated;

    return (truncated >= 0) ? truncated + 1 : truncated;
}

constexpr long long floor(const Fraction& fraction) noexcept
{
    const auto truncated = trunc(fraction);

    if (isInteger(fraction))
        return truncated;

    return (truncated >= 0) ? truncated : truncated - 1;
}

constexpr long long trunc(const Fraction& fraction) noexcept
{
    return fraction.numerator() / fraction.denominator();
}

constexpr long long round(const Fraction& fraction) noexcept
{
    const auto floored = floor(fraction);

    return (fraction - floored < Fraction(1, 2)) ? floored : floored + 1;
}

constexpr Fraction abs(const Fraction& fraction) noexcept
{
    return isPositive(fraction) ? fraction : -fraction;
}

constexpr std::size_t numNegativeSigns(const Fraction& fraction) noexcept
{
    return ((fraction.numerator() < 0) ? 1 : 0) + ((fraction.denominator() < 0) ? 1 : 0);
}

constexpr bool isPositive(const Fraction& fraction) noexcept
{
    return (fraction.numerator() > 0 && fraction.denominator() > 0)
           || (fraction.numerator() < 0 && fraction.denominator() < 0);
}

constexpr bool isNegative(const Fraction& fraction) noexcept
{
    return (fraction.numerator() > 0 && fraction.denominator() < 0)
           || (fraction.numerator() < 0 && fraction.denominator() > 0);
}

constexpr bool isZero(const Fraction& fraction) noexcept
{
    return isDefined(fraction) && fraction.numerator() == 0;
}

constexpr bool isInteger(const Fraction& fraction) noexcept
{
    return isDefined(fraction) && fraction.numerator() % fraction.denominator() == 0;
}

constexpr bool isUnitFraction(const Fraction& fraction) noexcept
{
    return isInteger(reciprocalOf(fraction));
}

constexpr bool isDefined(const Fraction& fraction) noexcept
{
    return fraction.denominator() != 0;
}

constexpr bool isUndefined(const Fraction& fraction) noexcept
{
    return !isDefined(fraction);
}

constexpr UnitFraction::UnitFraction(const long long denominator) noexcept :
    denominator_ {denominator}
{
}

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
