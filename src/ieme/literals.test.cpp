#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/literals.hpp>

#include <ieme/fraction_queries.hpp>

#include <type_traits>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("Literals have the expected symbolic equivalents", "[literals]")
{
  REQUIRE(are_identical(3 / 4_Fr, fraction(3, 4)));
  REQUIRE(are_identical(-3 / 4_Fr, fraction(-3, 4)));
  REQUIRE(are_identical(3 / -4_Fr, fraction(3, -4)));
  REQUIRE(are_identical(-3 / -4_Fr, fraction(-3, -4)));
}

TEST_CASE("The type of numerator drives the representation type for the "
          "resulting fraction",
          "[literals]")
{
  REQUIRE(std::is_same_v<decltype(3 / 4_Fr), fraction<int>>);
  REQUIRE(std::is_same_v<decltype(3U / 4_Fr), fraction<unsigned int>>);
  REQUIRE(std::is_same_v<decltype(3L / 4_Fr), fraction<long int>>);
  REQUIRE(std::is_same_v<decltype(3UL / 4_Fr), fraction<unsigned long int>>);
}

TEST_CASE("Literals can be used within complex arithmetic expressions",
          "[literals]")
{
  REQUIRE(3 + 4 / -3_Fr * 2 / 5_Fr == fraction(37, 15));
}
