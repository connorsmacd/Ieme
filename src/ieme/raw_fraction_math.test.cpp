#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/raw_fraction_math.hpp>


using namespace ieme;


TEST_CASE("A raw fraction can be reduced", "[raw_fraction]")
{
  const auto rf1 = reduce(raw_fraction<int> {12, 32});

  REQUIRE(rf1.numerator == 3);
  REQUIRE(rf1.denominator == 8);

  const auto rf2 = reduce(raw_fraction<int> {-12, 32});

  REQUIRE(rf2.numerator == -3);
  REQUIRE(rf2.denominator == 8);

  const auto rf3 = reduce(raw_fraction<int> {7, 9});

  REQUIRE(rf3.numerator == 7);
  REQUIRE(rf3.denominator == 9);

  const auto rf4 = reduce_ignore_signs(raw_fraction<int> {-45, -80});

  REQUIRE(rf4.numerator == -9);
  REQUIRE(rf4.denominator == -16);

  const auto rf5 = reduce(raw_fraction<int> {-45, -80});

  REQUIRE(rf5.numerator == 9);
  REQUIRE(rf5.denominator == 16);
}

TEST_CASE("A raw fraction's reciprocal can be computed", "[raw_fraction]")
{
  const auto rf1 = reciprocal(raw_fraction<int> {-12, 32});

  REQUIRE(rf1.numerator == 32);
  REQUIRE(rf1.denominator == -12);
}
