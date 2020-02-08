#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/floating_point.hpp>

#include <ieme/literals.hpp>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("Floats can be converted to fractions", "[floating_point]")
{
  REQUIRE(to_fraction<int>(24.0f) == 24);
  REQUIRE(to_fraction<int>(0.375f) == 3 / 8_Fr);
  REQUIRE(to_fraction<int>(-32.125f) == -32 - 1 / 8_Fr);

  REQUIRE(to_fraction<long long int>(24.0) == 24LL);
  REQUIRE(to_fraction<long long int>(0.375) == 3LL / 8_Fr);
  REQUIRE(to_fraction<long long int>(-32.125) == -32LL - 1LL / 8_Fr);
}

TEST_CASE("Fractions can be converted to floats", "[floating_point]")
{
  REQUIRE(to_float(24 / 1_Fr) == 24.0f);
  REQUIRE(to_float(3 / 8_Fr) == 0.375f);
  REQUIRE(to_float(-32 - 1 / 8_Fr) == -32.125f);

  REQUIRE(to_double(24 / 1_Fr) == 24.0);
  REQUIRE(to_double(3 / 8_Fr) == 0.375);
  REQUIRE(to_double(-32 - 1 / 8_Fr) == -32.125);

  REQUIRE(to_long_double(24 / 1_Fr) == 24.0L);
  REQUIRE(to_long_double(3 / 8_Fr) == 0.375L);
  REQUIRE(to_long_double(-32 - 1 / 8_Fr) == -32.125L);
}
