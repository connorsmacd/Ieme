#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <Ieme/Fraction.hpp>

#include <sstream>


using namespace Ieme;


TEST_CASE("A fraction is default constructable to 0/1", "[Fraction]")
{
    constexpr auto f = Fraction();

    REQUIRE(f.numerator() == 0);
    REQUIRE(f.denominator() == 1);
}

TEST_CASE("A fraction can be constructed from a numerator and denominator", "[Fraction]")
{
    constexpr auto f1 = Fraction(3, 4);

    REQUIRE(f1.numerator() == 3);
    REQUIRE(f1.denominator() == 4);
}

TEST_CASE("A fraction is copy constructable", "[Fraction]")
{
    constexpr auto f = Fraction(-5, 6);
    constexpr auto c = Fraction(f);

    REQUIRE(c.numerator() == -5);
    REQUIRE(c.denominator() == 6);
}

TEST_CASE("A fraction can be constructed from just a numerator", "[Fraction]")
{
    constexpr auto f = Fraction(5);

    REQUIRE(f.numerator() == 5);
    REQUIRE(f.denominator() == 1);
}

TEST_CASE("A fraction can be implicitly converted from a numerator and denominator", "[Fraction]")
{
    constexpr Fraction f1 = {3, 4};

    REQUIRE(f1.numerator() == 3);
    REQUIRE(f1.denominator() == 4);
}

TEST_CASE("A fraction can be implicitly converted from an integer", "[Fraction]")
{
    constexpr Fraction f = 5;

    REQUIRE(f.numerator() == 5);
    REQUIRE(f.denominator() == 1);
}

TEST_CASE("Symbolically identical fractions are equal", "[Fraction]")
{
    REQUIRE(Fraction(4, 5) == Fraction(4, 5));
    REQUIRE_FALSE(Fraction(4, 5) != Fraction(4, 5));
}

TEST_CASE("Symbolically different but equivalent fractions are equal", "[Fraction]")
{
    REQUIRE(Fraction(8, 10) == Fraction(4, 5));
    REQUIRE_FALSE(Fraction(8, 10) != Fraction(4, 5));
}

TEST_CASE("Inequivalent fractions are not equal", "[Fraction]")
{
    REQUIRE_FALSE(Fraction(4, 5) == Fraction(3, 7));
    REQUIRE(Fraction(4, 5) != Fraction(3, 7));
}

TEST_CASE("Undefined fractions are never equal to anything", "[Fraction]")
{
    REQUIRE_FALSE(Fraction(4, 5) == Fraction(4, 0));
    REQUIRE(Fraction(4, 5) != Fraction(4, 0));

    REQUIRE_FALSE(Fraction(4, 0) == Fraction(4, 5));
    REQUIRE(Fraction(4, 0) != Fraction(4, 5));

    REQUIRE_FALSE(Fraction(4, 0) == Fraction(4, 0));
    REQUIRE(Fraction(4, 0) != Fraction(4, 0));
}

TEST_CASE("A lesser fraction is less than a greater fraction", "[Fraction]")
{
    REQUIRE(Fraction(2, 3) < Fraction(4, 5));
    REQUIRE(Fraction(2, 3) <= Fraction(4, 5));
    REQUIRE_FALSE(Fraction(2, 3) >= Fraction(4, 5));
    REQUIRE_FALSE(Fraction(2, 3) > Fraction(4, 5));
}

TEST_CASE("Equivalent fractions are neither less than or greater than eachother", "[Fraction]")
{
    REQUIRE_FALSE(Fraction(4, 5) < Fraction(4, 5));
    REQUIRE(Fraction(4, 5) <= Fraction(4, 5));
    REQUIRE(Fraction(4, 5) >= Fraction(4, 5));
    REQUIRE_FALSE(Fraction(4, 5) > Fraction(4, 5));
}

TEST_CASE("A greater fraction is greater than a lesser fraction", "[Fraction]")
{
    REQUIRE_FALSE(Fraction(4, 7) < Fraction(2, 5));
    REQUIRE_FALSE(Fraction(4, 7) <= Fraction(2, 5));
    REQUIRE(Fraction(4, 7) >= Fraction(2, 5));
    REQUIRE(Fraction(4, 7) > Fraction(2, 5));
}

TEST_CASE("Undefined fractions have no valid ordinal comparisons", "[Fraction]")
{
    REQUIRE_FALSE(Fraction(4, 5) < Fraction(4, 0));
    REQUIRE_FALSE(Fraction(4, 5) <= Fraction(4, 0));
    REQUIRE_FALSE(Fraction(4, 5) >= Fraction(4, 0));
    REQUIRE_FALSE(Fraction(4, 5) > Fraction(4, 0));

    REQUIRE_FALSE(Fraction(4, 0) < Fraction(4, 5));
    REQUIRE_FALSE(Fraction(4, 0) <= Fraction(4, 5));
    REQUIRE_FALSE(Fraction(4, 0) >= Fraction(4, 5));
    REQUIRE_FALSE(Fraction(4, 0) > Fraction(4, 5));

    REQUIRE_FALSE(Fraction(4, 0) < Fraction(4, 0));
    REQUIRE_FALSE(Fraction(4, 0) <= Fraction(4, 0));
    REQUIRE_FALSE(Fraction(4, 0) >= Fraction(4, 0));
    REQUIRE_FALSE(Fraction(4, 0) > Fraction(4, 0));
}

TEST_CASE("Fractions with identical numerators and denominators are symbolically equal",
          "[Fraction]")
{
    REQUIRE(symbolicallyEqual(Fraction(7, -9), Fraction(7, -9)));
    REQUIRE_FALSE(notSymbolicallyEqual(Fraction(7, -9), Fraction(7, -9)));
}

TEST_CASE(
    "Equivalent fractions with different numerators and denominators are not symbolically equal",
    "[Fraction]")
{
    REQUIRE_FALSE(symbolicallyEqual(Fraction(14, -18), Fraction(7, -9)));
    REQUIRE(notSymbolicallyEqual(Fraction(14, -18), Fraction(7, -9)));
}

TEST_CASE("Equivalent negative fractions with different sign positions are not symbollicaly equal",
          "[Fraction]")
{
    REQUIRE_FALSE(symbolicallyEqual(Fraction(7, -9), Fraction(-7, 9)));
    REQUIRE(notSymbolicallyEqual(Fraction(7, -9), Fraction(-7, 9)));
}

TEST_CASE("Undefined fractions with identical numerators and denominators are symbolically equal",
          "[Fraction]")
{
    REQUIRE(symbolicallyEqual(Fraction(4, 0), Fraction(4, 0)));
    REQUIRE_FALSE(notSymbolicallyEqual(Fraction(4, 0), Fraction(4, 0)));
}

TEST_CASE("A reducible fraction can be reduced", "[Fraction]")
{
    REQUIRE(symbolicallyEqual(reduce(Fraction(12, 32)), Fraction(3, 8)));
}

TEST_CASE("An already irreducible fraction can be reduced", "[Fraction]")
{
    REQUIRE(symbolicallyEqual(reduce(Fraction(7, 9)), Fraction(7, 9)));
}

TEST_CASE("A fraction with the same denominator but different numerator can be created",
          "[Fraction]")
{
    REQUIRE(Fraction(17, 8).withNumerator(9) == Fraction(9, 8));
}

TEST_CASE("A fraction with the same numerator but different denominator can be created",
          "[Fraction]")
{
    REQUIRE(Fraction(17, 8).withDenominator(11) == Fraction(17, 11));
}

TEST_CASE("A fraction's sign position can be switched", "[Fraction]")
{
    REQUIRE(symbolicallyEqual(Fraction(10, 13).withSwitchedSignPosition(), Fraction(10, 13)));
    REQUIRE(symbolicallyEqual(Fraction(-10, 13).withSwitchedSignPosition(), Fraction(10, -13)));
    REQUIRE(symbolicallyEqual(Fraction(10, -13).withSwitchedSignPosition(), Fraction(-10, 13)));
    REQUIRE(symbolicallyEqual(Fraction(-10, -13).withSwitchedSignPosition(), Fraction(-10, -13)));
}

TEST_CASE("An equivalent fraction with minimal negative signs can be created", "[Fraction]")
{
    REQUIRE(symbolicallyEqual(Fraction(10, 13).withMinimalNegativeSigns(), Fraction(10, 13)));
    REQUIRE(symbolicallyEqual(Fraction(-10, 13).withMinimalNegativeSigns(), Fraction(-10, 13)));
    REQUIRE(symbolicallyEqual(Fraction(10, -13).withMinimalNegativeSigns(), Fraction(10, -13)));
    REQUIRE(symbolicallyEqual(Fraction(-10, -13).withMinimalNegativeSigns(), Fraction(10, 13)));
}

TEST_CASE("A fraction's reciprocal can be calculated", "[Fraction]")
{
    REQUIRE(reciprocalOf(Fraction(4, 19)) == Fraction(19, 4));
}

TEST_CASE("A fraction can be converted to a decimal", "[Fraction]")
{
    REQUIRE(toDecimal(Fraction(4, 5)) == 0.8L);
}

TEST_CASE("A fractional power of two can be computed", "[Fraction]")
{
    REQUIRE(fractionPow2(7) == 128);
    REQUIRE(fractionPow2(0) == 1);
    REQUIRE(fractionPow2(-3) == Fraction(1, 8));
}

TEST_CASE("A fraction can be ceilinged")
{
    REQUIRE(ceil(Fraction(7, 3)) == 3);
    REQUIRE(ceil(Fraction(8, 3)) == 3);
    REQUIRE(ceil(Fraction(2)) == 2);
    REQUIRE(ceil(Fraction(-7, 3)) == -2);
    REQUIRE(ceil(Fraction(-8, 3)) == -2);
    REQUIRE(ceil(Fraction(-2)) == -2);
}

TEST_CASE("A fraction can be floored")
{
    REQUIRE(floor(Fraction(7, 3)) == 2);
    REQUIRE(floor(Fraction(8, 3)) == 2);
    REQUIRE(floor(Fraction(2)) == 2);
    REQUIRE(floor(Fraction(-7, 3)) == -3);
    REQUIRE(floor(Fraction(-8, 3)) == -3);
    REQUIRE(floor(Fraction(-2)) == -2);
}

TEST_CASE("A fraction can be truncated")
{
    REQUIRE(trunc(Fraction(7, 3)) == 2);
    REQUIRE(trunc(Fraction(8, 3)) == 2);
    REQUIRE(trunc(Fraction(2)) == 2);
    REQUIRE(trunc(Fraction(-7, 3)) == -2);
    REQUIRE(trunc(Fraction(-8, 3)) == -2);
    REQUIRE(trunc(Fraction(-2)) == -2);
}

TEST_CASE("A fraction can be rounded")
{
    REQUIRE(round(Fraction(7, 3)) == 2);
    REQUIRE(round(Fraction(8, 3)) == 3);
    REQUIRE(round(Fraction(2)) == 2);
    REQUIRE(round(Fraction(-7, 3)) == -2);
    REQUIRE(round(Fraction(-8, 3)) == -3);
    REQUIRE(round(Fraction(-2)) == -2);
}

TEST_CASE("A fraction's absolute value can be calculated")
{
    REQUIRE(abs(Fraction(3, 2)) == Fraction(3, 2));
    REQUIRE(abs(Fraction(-3, 2)) == Fraction(3, 2));
    REQUIRE(abs(Fraction(0)) == 0);
}

TEST_CASE("A fraction can be promoted", "[Fraction]")
{
    REQUIRE(+Fraction(7, 10) == Fraction(7, 10));
}

TEST_CASE("A fraction can be negated", "[Fraction]")
{
    REQUIRE(-Fraction(7, 10) == Fraction(-7, 10));
    REQUIRE(-Fraction(-7, 10) == Fraction(7, 10));
}

TEST_CASE("A fraction with both a positive numerator and denominator has 0 negative signs",
          "[Fraction]")
{
    REQUIRE(numNegativeSigns(Fraction(1, 6)) == 0);
}

TEST_CASE("A fraction with a negative numerator and positive denominator has 1 negative signs",
          "[Fraction]")
{
    REQUIRE(numNegativeSigns(Fraction(-1, 6)) == 1);
}

TEST_CASE("A fraction with a positive numerator and negative denominator has 1 negative signs",
          "[Fraction]")
{
    REQUIRE(numNegativeSigns(Fraction(1, -6)) == 1);
}

TEST_CASE("A fraction with both a negative numerator and denominator has 2 negative signs",
          "[Fraction]")
{
    REQUIRE(numNegativeSigns(Fraction(-1, -6)) == 2);
}

TEST_CASE("A fraction with both a positive numerator and denominator is positive", "[Fraction]")
{
    REQUIRE(isPositive(Fraction(1, 6)));
    REQUIRE_FALSE(isNegative(Fraction(1, 6)));
    REQUIRE_FALSE(isZero(Fraction(1, 6)));
}

TEST_CASE("A fraction with a negative numerator and positive denominator is negative", "[Fraction]")
{
    REQUIRE_FALSE(isPositive(Fraction(-1, 6)));
    REQUIRE(isNegative(Fraction(-1, 6)));
    REQUIRE_FALSE(isZero(Fraction(-1, 6)));
}

TEST_CASE("A fraction with a positive numerator and negative denominator is negative", "[Fraction]")
{
    REQUIRE_FALSE(isPositive(Fraction(1, -6)));
    REQUIRE(isNegative(Fraction(1, -6)));
    REQUIRE_FALSE(isZero(Fraction(1, -6)));
}

TEST_CASE("A fraction with both a negative numerator and denominator is positive", "[Fraction]")
{
    REQUIRE(isPositive(Fraction(-1, -6)));
    REQUIRE_FALSE(isNegative(Fraction(-1, -6)));
    REQUIRE_FALSE(isZero(Fraction(-1, -6)));
}

TEST_CASE("A zero fraction is neither negative nor positive", "[Fraction]")
{
    REQUIRE_FALSE(isPositive(Fraction(0, 2)));
    REQUIRE_FALSE(isNegative(Fraction(0, 2)));
    REQUIRE(isZero(Fraction(0, 2)));
}

TEST_CASE("An undefined fraction is neither negative nor positive", "[Fraction]")
{
    REQUIRE_FALSE(isPositive(Fraction(2, 0)));
    REQUIRE_FALSE(isNegative(Fraction(2, 0)));
    REQUIRE_FALSE(isZero(Fraction(2, 0)));
}

TEST_CASE("A fraction with a numerator that divides the denominator is an integer", "[Fraction]")
{
    REQUIRE(isInteger(Fraction(4, 2)));
    REQUIRE_FALSE(isInteger(Fraction(4, 3)));
}

TEST_CASE("A fraction that is the reciprocal of an integer is a unit fraction", "[Fraction]")
{
    REQUIRE(isUnitFraction(Fraction(2, 4)));
    REQUIRE_FALSE(isUnitFraction(Fraction(3, 4)));
}

TEST_CASE("A fraction with a numerator that does not divide the denominator is not an integer",
          "[Fraction]")
{
    REQUIRE_FALSE(isInteger(Fraction(2, 5)));
}

TEST_CASE("An undefined fraction is not an integer", "[Fraction]")
{
    REQUIRE_FALSE(isInteger(Fraction(9, 0)));
}

TEST_CASE("A fraction with a non-zero denominator is defined", "[Fraction]")
{
    REQUIRE(isDefined(Fraction(-50, 3)));
    REQUIRE_FALSE(isUndefined(Fraction(-50, 3)));
}

TEST_CASE("A fraction with a zero denominator is undefined", "[Fraction]")
{
    REQUIRE_FALSE(isDefined(Fraction(4, 0)));
    REQUIRE(isUndefined(Fraction(4, 0)));
}

TEST_CASE("Fractions with a common denominator can be added", "[Fraction]")
{
    REQUIRE(Fraction(1, 5) + Fraction(3, 5) == Fraction(4, 5));
}

TEST_CASE("Fractions without a common denominator can be added", "[Fraction]")
{
    REQUIRE(Fraction(2, 3) + Fraction(1, 4) == Fraction(11, 12));
}

TEST_CASE("Fractions with a common denominator can be subtracted", "[Fraction]")
{
    REQUIRE(Fraction(1, 5) - Fraction(3, 5) == Fraction(-2, 5));
}

TEST_CASE("Fractions without a common denominator can be subtracted", "[Fraction]")
{
    REQUIRE(Fraction(2, 3) - Fraction(1, 4) == Fraction(5, 12));
}

TEST_CASE("Fractions can be multiplied", "[Fraction]")
{
    REQUIRE(Fraction(2, 3) * Fraction(3, 7) == Fraction(6, 21));
}

TEST_CASE("Fractions can be divided", "[Fraction]")
{
    REQUIRE(Fraction(2, 3) / Fraction(3, 11) == Fraction(22, 9));
}

TEST_CASE("The remainder of two fractions can be calculated", "[Fraction]")
{
    REQUIRE(Fraction(19, 21) % Fraction(4, 21) == Fraction(3, 21));
    REQUIRE(Fraction(4, 7) % Fraction(2, 5) == Fraction(6, 35));
    REQUIRE(Fraction(-2, 5) % Fraction(2, 3) == Fraction(-6, 15));
}

TEST_CASE("A fraction can be serialized", "[Fraction]")
{
    const auto f = Fraction(-5, 7);

    std::ostringstream stream;
    stream << f;

    REQUIRE(stream.str() == "-5/7");
}

TEST_CASE("A fraction can be deserialized", "[Fraction]")
{
    std::istringstream stream {" -5 / 7 "};

    Fraction f;
    stream >> f;

    REQUIRE(f == Fraction(-5, 7));
}

TEST_CASE("A default-constructed mixed fraction has a zero whole part and 0/1 fractional part",
          "[Fraction]")
{
    constexpr auto f = MixedFraction();

    REQUIRE(f.wholePart() == 0);
    REQUIRE(symbolicallyEqual(f.fractionalPart(), Fraction(0, 1)));
}

TEST_CASE("A mixed fraction can constructed from a whole and fractional part", "[Fraction]")
{
    constexpr auto f = MixedFraction(-5, {4, 5});

    REQUIRE(f.wholePart() == -5);
    REQUIRE(symbolicallyEqual(f.fractionalPart(), Fraction(4, 5)));
}

TEST_CASE("A mixed fraction can constructed from a fraction", "[Fraction]")
{
    constexpr auto f = MixedFraction(Fraction(-11, 4));

    REQUIRE(f.wholePart() == -2);
    REQUIRE(symbolicallyEqual(f.fractionalPart(), Fraction(3, 4)));
}

TEST_CASE("A mixed fraction can be converted to a fraction", "[Fraction]")
{
    constexpr auto f = (Fraction) MixedFraction(-3, {1, 9});

    REQUIRE(symbolicallyEqual(f, {-28, 9}));
}
