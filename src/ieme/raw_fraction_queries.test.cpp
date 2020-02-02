#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/raw_fraction.hpp>


using namespace ieme;


TEST_CASE(
  "A raw fraction can be queried about whether or not it's a defined value",
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

TEST_CASE("A raw fraction can be queried about whether or not it's an integer",
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
  "A raw fraction can be queried about whether or not it's a unit fraction",
  "[raw_fraction]")
{
  const auto rf1 = raw_fraction<int> {5, 10};

  REQUIRE(is_unit_fraction(rf1));

  const auto rf2 = raw_fraction<int> {-5, 2};

  REQUIRE_FALSE(is_unit_fraction(rf2));

  const auto rf3 = raw_fraction<int> {0, 1};

  REQUIRE(is_unit_fraction(rf3));

  const auto rf4 = raw_fraction<int> {1, 0};

  REQUIRE_FALSE(is_unit_fraction(rf4));
}

TEST_CASE("A raw fraction can be queried about whether or not it's reduced",
          "[raw_fraction]")
{
  const auto rf1 = raw_fraction<int> {3, 4};

  REQUIRE(is_reduced_ignore_signs(rf1));
  REQUIRE(is_reduced(rf1));

  const auto rf2 = raw_fraction<int> {-5, 2};

  REQUIRE(is_reduced_ignore_signs(rf2));
  REQUIRE(is_reduced(rf2));

  const auto rf3 = raw_fraction<int> {-3, -4};

  REQUIRE(is_reduced_ignore_signs(rf3));
  REQUIRE_FALSE(is_reduced(rf3));

  const auto rf4 = raw_fraction<int> {6, 8};

  REQUIRE_FALSE(is_reduced_ignore_signs(rf4));
  REQUIRE_FALSE(is_reduced(rf4));

  const auto rf5 = raw_fraction<int> {-6, -8};

  REQUIRE_FALSE(is_reduced_ignore_signs(rf5));
  REQUIRE_FALSE(is_reduced(rf5));
}

TEST_CASE("A raw fraction can be queried about whether or not it's proper",
          "[raw_fraction]")
{
  const auto rf1 = raw_fraction<int> {3, 4};

  REQUIRE(is_proper(rf1));
  REQUIRE_FALSE(is_improper(rf1));

  const auto rf2 = raw_fraction<int> {-3, 4};

  REQUIRE(is_proper(rf2));
  REQUIRE_FALSE(is_improper(rf2));

  const auto rf3 = raw_fraction<int> {3, -4};

  REQUIRE(is_proper(rf3));
  REQUIRE_FALSE(is_improper(rf3));

  const auto rf4 = raw_fraction<int> {-3, -4};

  REQUIRE(is_proper(rf4));
  REQUIRE_FALSE(is_improper(rf4));

  const auto rf5 = raw_fraction<int> {5, 4};

  REQUIRE_FALSE(is_proper(rf5));
  REQUIRE(is_improper(rf5));

  const auto rf6 = raw_fraction<int> {-5, 4};

  REQUIRE_FALSE(is_proper(rf6));
  REQUIRE(is_improper(rf6));

  const auto rf7 = raw_fraction<int> {5, -4};

  REQUIRE_FALSE(is_proper(rf7));
  REQUIRE(is_improper(rf7));

  const auto rf8 = raw_fraction<int> {-5, -4};

  REQUIRE_FALSE(is_proper(rf8));
  REQUIRE(is_improper(rf8));
}
