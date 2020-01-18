
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/unit_fraction.hpp>


using namespace ieme;


TEST_CASE("A default-constructed unit fraction is 1", "[Fraction]")
{
    constexpr auto f = unit_fraction<int>();

    REQUIRE(symbolically_equal(f.as_fraction(), fraction<int>(1)));
}

TEST_CASE("A unit fraction can be constructed from a denomintor", "[Fraction]")
{
    constexpr auto f = unit_fraction<int>(3);

    REQUIRE(f.as_fraction() == fraction<int>(1, 3));
}
