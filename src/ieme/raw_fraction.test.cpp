#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/raw_fraction.hpp>


using namespace ieme;


TEST_CASE("A raw fraction can be constructed from a numerator and denominator",
          "[raw_fraction]")
{
  auto const rf = raw_fraction(34, -21);

  REQUIRE(rf.numerator == 34);
  REQUIRE(rf.denominator == -21);
}

TEST_CASE("A raw fraction can be constructed from a different raw fraction "
          "with a different representation type",
          "[raw_fraction]")
{
  auto const rf = raw_fraction<long long>(raw_fraction(-54, 47));

  REQUIRE(rf.numerator == -54);
  REQUIRE(rf.denominator == 47);
}

TEST_CASE("A raw fraction can be serialized", "[raw_fraction]")
{
  auto const rf = raw_fraction(-5, 7);

  std::ostringstream stream;
  stream << rf;

  REQUIRE(stream.str() == "-5/7");
}

TEST_CASE("A raw fraction can be deserialized", "[raw_fraction]")
{
  std::istringstream stream {" -5 / 7 "};

  raw_fraction<int> rf;
  stream >> rf;

  REQUIRE(rf.numerator == -5);
  REQUIRE(rf.denominator == 7);
}
