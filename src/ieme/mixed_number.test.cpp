#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/mixed_number.hpp>

#include <ieme/fraction_queries.hpp>
#include <ieme/literals.hpp>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("A default-constructed mixed number has a zero whole part and 0/1 "
          "fractional part",
          "[mixed_number]")
{
  constexpr auto f = mixed_number<int>();

  REQUIRE(f.whole_part() == 0);
  REQUIRE(are_identical(f.fractional_part(), 0 / 1_Fr));
}

TEST_CASE("A mixed number can constructed from a whole and fractional part",
          "[mixed_number]")
{
  constexpr auto f = mixed_number<int>(-5, 4 / 5_Fr);

  REQUIRE(f.whole_part() == -5);
  REQUIRE(are_identical(f.fractional_part(), 4 / 5_Fr));
}

TEST_CASE("A mixed number can constructed from a fraction", "[mixed_number]")
{
  constexpr auto f = mixed_number<int>(-11 / 4_Fr);

  REQUIRE(f.whole_part() == -2);
  REQUIRE(are_identical(f.fractional_part(), 3 / 4_Fr));
}

TEST_CASE("A mixed number can be converted to a fraction", "[mixed_number]")
{
  constexpr auto f = (fraction<int>) mixed_number(-3, 1 / 9_Fr);

  REQUIRE(are_identical(f, -28 / 9_Fr));
}
