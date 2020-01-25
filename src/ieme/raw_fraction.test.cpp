#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/fraction.hpp>


using namespace ieme;


TEST_CASE("A raw fraction can be reduced", "[raw_fraction]")
{
  const auto rf1 = reduce(raw_fraction<int> {12, 32});

  REQUIRE(rf1.numerator == 3);
  REQUIRE(rf1.denominator == 8);

  const auto rf2 = reduce(raw_fraction<int> {7, 9});

  REQUIRE(rf2.numerator == 7);
  REQUIRE(rf2.denominator == 9);

  const auto rf3 = reduce(raw_fraction<int> {-45, -80});

  REQUIRE(rf3.numerator == 9);
  REQUIRE(rf3.denominator == 16);
}

TEST_CASE("A raw fraction's reciprocal can be computed", "[raw_fraction]")
{
  const auto rf1 = reciprocal(raw_fraction<int> {-12, 32});

  REQUIRE(rf1.numerator == 32);
  REQUIRE(rf1.denominator == -12);
}

TEST_CASE("A raw fraction's sign can be queried", "[raw_fraction]")
{
  const auto rf1 = raw_fraction<int> {12, 32};

  REQUIRE(is_positive(rf1));
  REQUIRE_FALSE(is_negative(rf1));
  REQUIRE_FALSE(is_zero(rf1));

  const auto rf2 = raw_fraction<int> {-5, 2};

  REQUIRE_FALSE(is_positive(rf2));
  REQUIRE(is_negative(rf2));
  REQUIRE_FALSE(is_zero(rf2));

  const auto rf3 = raw_fraction<int> {0, 1};

  REQUIRE_FALSE(is_positive(rf3));
  REQUIRE_FALSE(is_negative(rf3));
  REQUIRE(is_zero(rf3));

  const auto rf4 = raw_fraction<int> {1, 0};

  REQUIRE_FALSE(is_positive(rf4));
  REQUIRE_FALSE(is_negative(rf4));
  REQUIRE_FALSE(is_zero(rf4));
}

TEST_CASE("A raw fraction can be queried on whether or not it's an integer",
          "[raw_fraction]")
{
  const auto rf1 = raw_fraction<int> {10, 5};

  REQUIRE(is_integer(rf1));

  const auto rf2 = raw_fraction<int> {-5, 2};

  REQUIRE_FALSE(is_integer(rf2));

  const auto rf3 = raw_fraction<int> {0, 1};

  REQUIRE(is_integer(rf3));

  const auto rf4 = raw_fraction<int> {1, 0};

  REQUIRE_FALSE(is_integer(rf4));
}

TEST_CASE(
  "A raw fraction can be queried on whether or not it's a defined value",
  "[raw_fraction]")
{
  const auto rf1 = raw_fraction<int> {10, 5};

  REQUIRE(is_defined(rf1));
  REQUIRE_FALSE(is_undefined(rf1));

  const auto rf2 = raw_fraction<int> {-5, 2};

  REQUIRE(is_defined(rf2));
  REQUIRE_FALSE(is_undefined(rf2));

  const auto rf3 = raw_fraction<int> {0, 1};

  REQUIRE(is_defined(rf3));
  REQUIRE_FALSE(is_undefined(rf3));

  const auto rf4 = raw_fraction<int> {1, 0};

  REQUIRE_FALSE(is_defined(rf4));
  REQUIRE(is_undefined(rf4));
}
