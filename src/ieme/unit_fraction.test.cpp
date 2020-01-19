
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/unit_fraction.hpp>

#include <ieme/literals.hpp>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("A default-constructed unit fraction is 1", "[unit_fraction]")
{
    constexpr auto f = unit_fraction<int>();

    REQUIRE(symbolically_equal(f.as_fraction(), 1 / 1_Fr));
}

TEST_CASE("A unit fraction can be constructed from a denomintor",
          "[unit_fraction]")
{
    constexpr auto f = unit_fraction<int>(3);

    REQUIRE(f.as_fraction() == 1 / 3_Fr);
}
