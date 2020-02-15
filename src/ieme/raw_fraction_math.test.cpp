#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/raw_fraction_math.hpp>

#include <ieme/raw_fraction_queries.hpp>


using namespace ieme;


TEST_CASE("A raw fraction's reciprocal can be computed", "[raw_fraction]")
{
  REQUIRE(are_identical(reciprocal(raw_fraction<int> {-12, 32}),
                        raw_fraction<int> {32, -12}));
}

TEST_CASE("A raw fraction can be reduced", "[raw_fraction]")
{
  REQUIRE(are_identical(reduce(raw_fraction<int> {12, 32}),
                        raw_fraction<int> {3, 8}));
  REQUIRE(are_identical(reduce(raw_fraction<int> {-12, 32}),
                        raw_fraction<int> {-3, 8}));
  REQUIRE(are_identical(reduce(raw_fraction<int> {7, 99}),
                        raw_fraction<int> {7, 99}));
  REQUIRE(are_identical(reduce(raw_fraction<int> {-45, -80}),
                        raw_fraction<int> {9, 16}));
  REQUIRE(are_identical(reduce_ignore_signs(raw_fraction<int> {-45, -80}),
                        raw_fraction<int> {-9, -16}));
  REQUIRE(are_identical(reduce(raw_fraction<int> {-234123, 0}),
                        raw_fraction<int> {0, 0}));
}
