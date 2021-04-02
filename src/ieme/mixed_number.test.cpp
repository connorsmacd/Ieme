#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/mixed_number.hpp>

#include <ieme/fraction_literals.hpp>
#include <ieme/fraction_queries.hpp>


using namespace ieme;
using namespace ieme::fraction_literals;


TEST_CASE("A default-constructed mixed number has a zero whole part and 0/1 "
          "fractional part",
          "[mixed_number]")
{
  constexpr auto mn = mixed_number<int>();

  REQUIRE(mn.whole() == 0);
  REQUIRE(are_identical(mn.fractional(), 0 / 1_fr));
}

TEST_CASE("A mixed number can constructed from a whole and fractional part",
          "[mixed_number]")
{
  constexpr auto mn = mixed_number(-5, -4 / 5_fr);

  REQUIRE(mn.whole() == -5);
  REQUIRE(are_identical(mn.fractional(), -4 / 5_fr));
}

TEST_CASE("A mixed number will fix itself if the whole and fractional do not "
          "have the same sign or if the fractional is improper",
          "[mixed_number]")
{
  constexpr auto mn1 = mixed_number(5, -4 / 5_fr);

  REQUIRE(mn1.whole() == 4);
  REQUIRE(are_identical(mn1.fractional(), 1 / 5_fr));

  constexpr auto mn2 = mixed_number(-5, 4 / 5_fr);

  REQUIRE(mn2.whole() == -4);
  REQUIRE(are_identical(mn2.fractional(), -1 / 5_fr));

  constexpr auto mn3 = mixed_number(3, 6 / 5_fr);

  REQUIRE(mn3.whole() == 4);
  REQUIRE(are_identical(mn3.fractional(), 1 / 5_fr));

  constexpr auto mn4 = mixed_number(-3, -6 / 5_fr);

  REQUIRE(mn4.whole() == -4);
  REQUIRE(are_identical(mn4.fractional(), -1 / 5_fr));

  constexpr auto mn5 = mixed_number(7, -14 / 5_fr);

  REQUIRE(mn5.whole() == 4);
  REQUIRE(are_identical(mn5.fractional(), 1 / 5_fr));

  constexpr auto mn6 = mixed_number(-7, 14 / 5_fr);

  REQUIRE(mn6.whole() == -4);
  REQUIRE(are_identical(mn6.fractional(), -1 / 5_fr));
}

TEST_CASE("A mixed number can constructed from just a whole part",
          "[mixed_number]")
{
  constexpr auto mn = mixed_number<int>(2);

  REQUIRE(mn.whole() == 2);
  REQUIRE(are_identical(mn.fractional(), 0 / 1_fr));
}

TEST_CASE("A mixed number can constructed from a fraction", "[mixed_number]")
{
  constexpr auto mn = mixed_number<int>(-11 / 4_fr);

  REQUIRE(mn.whole() == -2);
  REQUIRE(are_identical(mn.fractional(), -3 / 4_fr));
}

TEST_CASE("A mixed number can be converted to a fraction", "[mixed_number]")
{
  constexpr auto f = (fraction<int>) mixed_number(-3, -1 / 9_fr);

  REQUIRE(are_identical(f, -28 / 9_fr));
}

TEST_CASE("A mixed number can be promoted", "[mixed_number]")
{
  constexpr auto mn = +mixed_number(7, 4 / 9_fr);

  REQUIRE(mn.whole() == 7);
  REQUIRE(are_identical(mn.fractional(), 4 / 9_fr));
}

TEST_CASE("A mixed number can be negated", "[mixed_number]")
{
  constexpr auto mn = -mixed_number(7, 4 / 9_fr);

  REQUIRE(mn.whole() == -7);
  REQUIRE(are_identical(mn.fractional(), -4 / 9_fr));
}

TEST_CASE("A whole number can be added to a mixed number", "[mixed_number]")
{
  constexpr auto mn1 = mixed_number(8, 1 / 4_fr) + 2;

  REQUIRE(mn1.whole() == 10);
  REQUIRE(mn1.fractional() == 1 / 4_fr);

  constexpr auto mn2 = 2 + mixed_number(8, 1 / 4_fr);

  REQUIRE(mn2.whole() == 10);
  REQUIRE(mn2.fractional() == 1 / 4_fr);
}

TEST_CASE("A fraction can be added to a mixed number", "[mixed_number]")
{
  constexpr auto mn1 = mixed_number(8, 3 / 4_fr) + 5 / 3_fr;

  REQUIRE(mn1.whole() == 10);
  REQUIRE(mn1.fractional() == 5 / 12_fr);

  constexpr auto mn2 = -3 / 2_fr + mixed_number(0, 1 / 4_fr);

  REQUIRE(mn2.whole() == -1);
  REQUIRE(mn2.fractional() == -1 / 4_fr);
}

TEST_CASE("Two mixed numbers can be added together", "[mixed_number]")
{
  constexpr auto mn1 = mixed_number(3, 4 / 5_fr) + mixed_number(-2, -1 / 2_fr);

  REQUIRE(mn1.whole() == 1);
  REQUIRE(mn1.fractional() == 3 / 10_fr);
}
