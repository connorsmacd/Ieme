#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/fraction_math.hpp>

#include <ieme/literals.hpp>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("A fraction's reciprocal can be calculated", "[fraction]")
{
  REQUIRE(symbolically_equal(reciprocal(4 / -19_Fr), -19 / 4_Fr));
}

TEST_CASE("A fraction can be reduced", "[fraction]")
{
  REQUIRE(symbolically_equal(reduce_ignore_signs(12 / 32_Fr), 3 / 8_Fr));
  REQUIRE(symbolically_equal(reduce(12 / 32_Fr), 3 / 8_Fr));
  REQUIRE(symbolically_equal(reduce_ignore_signs(-12 / -32_Fr), -3 / -8_Fr));
  REQUIRE(symbolically_equal(reduce(-12 / -32_Fr), 3 / 8_Fr));
}

TEST_CASE("A fraction's absolute value can be calculated", "[fraction]")
{
  REQUIRE(abs(3 / 2_Fr) == 3 / 2_Fr);
  REQUIRE(abs(-3 / 2_Fr) == 3 / 2_Fr);
  REQUIRE(abs(0 / 1_Fr) == 0);
}

TEST_CASE("A fraction can be truncated", "[fraction]")
{
  REQUIRE(trunc(7 / 3_Fr) == 2);
  REQUIRE(trunc(8 / 3_Fr) == 2);
  REQUIRE(trunc(2 / 1_Fr) == 2);
  REQUIRE(trunc(-7 / 3_Fr) == -2);
  REQUIRE(trunc(-8 / 3_Fr) == -2);
  REQUIRE(trunc(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be ceilinged", "[fraction]")
{
  REQUIRE(ceil(7 / 3_Fr) == 3);
  REQUIRE(ceil(8 / 3_Fr) == 3);
  REQUIRE(ceil(2 / 1_Fr) == 2);
  REQUIRE(ceil(-7 / 3_Fr) == -2);
  REQUIRE(ceil(-8 / 3_Fr) == -2);
  REQUIRE(ceil(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be floored", "[fraction]")
{
  REQUIRE(floor(7 / 3_Fr) == 2);
  REQUIRE(floor(8 / 3_Fr) == 2);
  REQUIRE(floor(2 / 1_Fr) == 2);
  REQUIRE(floor(-7 / 3_Fr) == -3);
  REQUIRE(floor(-8 / 3_Fr) == -3);
  REQUIRE(floor(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be rounded", "[fraction]")
{
  REQUIRE(round(7 / 3_Fr) == 2);
  REQUIRE(round(8 / 3_Fr) == 3);
  REQUIRE(round(2 / 1_Fr) == 2);
  REQUIRE(round(-7 / 3_Fr) == -2);
  REQUIRE(round(-8 / 3_Fr) == -3);
  REQUIRE(round(-2 / 1_Fr) == -2);
}

TEST_CASE("A fractional power of two can be calculated", "[fraction]")
{
  REQUIRE(pow2(7) == 128);
  REQUIRE(pow2(0) == 1);
  REQUIRE(pow2(-3) == 1 / 8_Fr);
}
