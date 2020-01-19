#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/literals.hpp>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("Literals have the expected symbolic equivalents", "[literals]")
{
    REQUIRE(symbolically_equal(3 / 4_Fr, fraction(3, 4)));
    REQUIRE(symbolically_equal(-3 / 4_Fr, fraction(-3, 4)));
    REQUIRE(symbolically_equal(3 / -4_Fr, fraction(3, -4)));
    REQUIRE(symbolically_equal(-3 / -4_Fr, fraction(-3, -4)));
}

TEST_CASE("Literals can be used within complex arithmetic expressions",
          "[literals]")
{
    REQUIRE(3 + 4 / -3_Fr * 2 / 5_Fr == fraction(37, 15));
}
