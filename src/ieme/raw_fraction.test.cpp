#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/raw_fraction.hpp>


using namespace ieme;


TEST_CASE("A raw fraction can be serialized", "[raw_fraction]")
{
  const auto rf = raw_fraction<int> {-5, 7};

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
