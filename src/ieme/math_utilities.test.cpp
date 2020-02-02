#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/math_utilities.hpp>


using namespace ieme;
using namespace ieme::math_utilities;


TEST_CASE("An integer's absolute value can be calculated at compile time",
          "[math_utilities]")
{
  REQUIRE(abs(5) == 5);
  REQUIRE(abs(0) == 0);
  REQUIRE(abs(-5) == 5);
}

TEST_CASE("A power of 2 can be calculated at compile time", "[math_utilities]")
{
  REQUIRE(pow2(0) == 1);
  REQUIRE(pow2(10) == 1024);
}
