
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <Ieme/UnitFraction.hpp>


using namespace Ieme;


TEST_CASE("A default-constructed unit fraction is 1", "[Fraction]")
{
    constexpr auto f = UnitFraction();

    REQUIRE(symbolicallyEqual(f, Fraction(1)));
}

TEST_CASE("A unit fraction can be constructed from a denomintor", "[Fraction]")
{
    constexpr auto f = UnitFraction(3);

    REQUIRE(f == Fraction(1, 3));
}
