#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/raw_fraction_math.hpp>

#include <ieme/raw_fraction_queries.hpp>


using namespace ieme;


TEST_CASE("A raw fraction's reciprocal can be computed", "[raw_fraction]")
{
  REQUIRE(
    are_identical(reciprocal(raw_fraction(-12, 32)), raw_fraction(32, -12)));
}

TEST_CASE("Raw fractions can be normalized to cancel double negative signs or "
          "move a negative sign to the numerator",
          "[raw_fraction]")
{
  REQUIRE(
    are_identical(normalize_signs(raw_fraction(3, 5)), raw_fraction(3, 5)));
  REQUIRE(
    are_identical(normalize_signs(raw_fraction(-3, 5)), raw_fraction(-3, 5)));
  REQUIRE(
    are_identical(normalize_signs(raw_fraction(3, -5)), raw_fraction(-3, 5)));
  REQUIRE(
    are_identical(normalize_signs(raw_fraction(-3, -5)), raw_fraction(3, 5)));
}

TEST_CASE("A raw fraction can be reduced", "[raw_fraction]")
{
  REQUIRE(are_identical(reduce(raw_fraction(12, 32), reduce_mode::ignore_signs),
                        raw_fraction(3, 8)));
  REQUIRE(
    are_identical(reduce(raw_fraction(12, 32), reduce_mode::normalize_signs),
                  raw_fraction(3, 8)));

  REQUIRE(
    are_identical(reduce(raw_fraction(-12, 32), reduce_mode::ignore_signs),
                  raw_fraction(-3, 8)));
  REQUIRE(
    are_identical(reduce(raw_fraction(-12, 32), reduce_mode::normalize_signs),
                  raw_fraction(-3, 8)));

  REQUIRE(
    are_identical(reduce(raw_fraction(12, -32), reduce_mode::ignore_signs),
                  raw_fraction(3, -8)));
  REQUIRE(
    are_identical(reduce(raw_fraction(12, -32), reduce_mode::normalize_signs),
                  raw_fraction(-3, 8)));

  REQUIRE(
    are_identical(reduce(raw_fraction(-12, -32), reduce_mode::ignore_signs),
                  raw_fraction(-3, -8)));
  REQUIRE(
    are_identical(reduce(raw_fraction(-12, -32), reduce_mode::normalize_signs),
                  raw_fraction(3, 8)));

  REQUIRE(are_identical(reduce(raw_fraction(-3, -8), reduce_mode::ignore_signs),
                        raw_fraction(-3, -8)));
  REQUIRE(
    are_identical(reduce(raw_fraction(-3, -8), reduce_mode::normalize_signs),
                  raw_fraction(3, 8)));

  REQUIRE(
    are_identical(reduce(raw_fraction<int>(-12, 0), reduce_mode::ignore_signs),
                  raw_fraction<int>(0, 0)));
  REQUIRE(are_identical(
    reduce(raw_fraction<int>(-12, 0), reduce_mode::normalize_signs),
    raw_fraction<int>(0, 0)));
}
