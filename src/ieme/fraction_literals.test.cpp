#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/fraction_literals.hpp>

#include <ieme/fraction_queries.hpp>

#include <type_traits>


using namespace ieme;
using namespace ieme::fraction_literals;


TEST_CASE("Fraction literals have the expected symbolic equivalents",
          "[literals]")
{
  REQUIRE(are_identical(3 / 4_fr, fraction(3, 4)));
  REQUIRE(are_identical(-3 / 4_fr, fraction(-3, 4)));
  REQUIRE(are_identical(3 / -4_fr, fraction(3, -4)));
  REQUIRE(are_identical(-3 / -4_fr, fraction(-3, -4)));
}

TEST_CASE("The type of numerator in a fraction literal drives the "
          "representation type of the resulting fraction",
          "[literals]")
{
  REQUIRE(std::is_same_v<decltype(3 / 4_fr), fraction<int>>);
  REQUIRE(std::is_same_v<decltype(3U / 4_fr), fraction<unsigned int>>);
  REQUIRE(std::is_same_v<decltype(3L / 4_fr), fraction<long int>>);
  REQUIRE(std::is_same_v<decltype(3UL / 4_fr), fraction<unsigned long int>>);
}

TEST_CASE("Fraction literals can be used within complex arithmetic expressions",
          "[literals]")
{
  REQUIRE(3 + 4 / -3_fr * 2 / 5_fr == fraction(37, 15));
}

TEST_CASE("Decimal fraction literals have the expected fractional equivalents",
          "[literals]")
{
  REQUIRE(2.3_Dec == 2 + 3 / 10_fr);
  REQUIRE(94.332_Dec == 94L + 332 / 1'000_fr);
  REQUIRE(9.22E+3_Dec == 9'220);
  REQUIRE(7.543E-10_Dec == 7'543L / 10'000'000'000'000_fr);
  REQUIRE(0xC.Ap2_Dec == 0x65 / 0x2_fr);
  REQUIRE(0xC1.A1p-10_Dec == 0xC1A1 / 0x40000_fr);
}
