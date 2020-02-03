#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/mixed_number.hpp>

#include <ieme/literals.hpp>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("A default-constructed mixed fraction has a zero whole part and 0/1 "
          "fractional part",
          "[mixed_number]")
{
  constexpr auto f = mixed_number<int>();

  REQUIRE(f.whole_part() == 0);
  REQUIRE(symbolically_equal(f.fractional_part(), 0 / 1_Fr));
}

TEST_CASE("A mixed fraction can constructed from a whole and fractional part",
          "[mixed_number]")
{
  constexpr auto f = mixed_number<int>(-5, {4, 5});

  REQUIRE(f.whole_part() == -5);
  REQUIRE(symbolically_equal(f.fractional_part(), 4 / 5_Fr));
}

TEST_CASE("A mixed fraction can constructed from a fraction", "[mixed_number]")
{
  constexpr auto f = mixed_number<int>(-11 / 4_Fr);

  REQUIRE(f.whole_part() == -2);
  REQUIRE(symbolically_equal(f.fractional_part(), 3 / 4_Fr));
}

TEST_CASE("A mixed fraction can be converted to a fraction", "[mixed_number]")
{
  constexpr auto f = (fraction<int>) mixed_number<int>(-3, {1, 9});

  REQUIRE(symbolically_equal(f, -28 / 9_Fr));
}
