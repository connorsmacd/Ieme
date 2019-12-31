#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <Ieme/MixedFraction.hpp>


using namespace Ieme;


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
