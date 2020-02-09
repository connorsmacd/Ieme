#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/fraction.hpp>

#include <ieme/literals.hpp>

#include <sstream>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("A fraction is default constructable to 0/1", "[fraction]")
{
  constexpr auto f = fraction<int>();

  REQUIRE(f.numerator() == 0);
  REQUIRE(f.denominator() == 1);
}

TEST_CASE("A fraction can be constructed from a numerator and denominator",
          "[fraction]")
{
  constexpr auto f = fraction(3, 4);

  REQUIRE(f.numerator() == 3);
  REQUIRE(f.denominator() == 4);
}

TEST_CASE("A fraction is copy constructable", "[fraction]")
{
  constexpr auto f = fraction(fraction(-5, 6));

  REQUIRE(f.numerator() == -5);
  REQUIRE(f.denominator() == 6);
}

TEST_CASE("A fraction can be constructed from just a numerator", "[fraction]")
{
  constexpr auto f = fraction(5);

  REQUIRE(f.numerator() == 5);
  REQUIRE(f.denominator() == 1);
}

TEST_CASE("A fraction can be constructed from an std::ratio", "[fraction]")
{
  constexpr auto f = fraction<int>(std::ratio<45, 22>());

  REQUIRE(f.numerator() == 45);
  REQUIRE(f.denominator() == 22);
}

TEST_CASE("A fraction can be serialized", "[fraction]")
{
  const auto f = -5 / 7_Fr;

  std::ostringstream stream;
  stream << f;

  REQUIRE(stream.str() == "-5/7");
}

TEST_CASE("A fraction can be deserialized", "[fraction]")
{
  std::istringstream stream {" -5 / 7 "};

  fraction<int> f;
  stream >> f;

  REQUIRE(f == -5 / 7_Fr);
}
