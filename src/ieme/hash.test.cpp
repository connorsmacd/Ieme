#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/hash.hpp>

#include <ieme/fraction_literals.hpp>


using namespace ieme;
using namespace ieme::fraction_literals;


TEST_CASE("A raw fraction can be hashed", "[hash]")
{
  REQUIRE(hash(raw_fraction(-3, 4)) == hash(raw_fraction(-3, 4)));
  REQUIRE(hash(raw_fraction(23, 222)) == hash(raw_fraction(23, 222)));
  REQUIRE(std::hash<raw_fraction<int>>()(raw_fraction(-3, 4))
          == std::hash<raw_fraction<int>>()(raw_fraction(-3, 4)));
  REQUIRE(std::hash<raw_fraction<int>>()(raw_fraction(23, 222))
          == std::hash<raw_fraction<int>>()(raw_fraction(23, 222)));
}

TEST_CASE("A fraction can be hashed", "[hash]")
{
  REQUIRE(hash(-3 / 4_fr) == hash(-3 / 4_fr));
  REQUIRE(hash(23 / 222_fr) == hash(23 / 222_fr));
  REQUIRE(std::hash<fraction<int>>()(-3 / 4_fr)
          == std::hash<fraction<int>>()(-3 / 4_fr));
  REQUIRE(std::hash<fraction<int>>()(23 / 222_fr)
          == std::hash<fraction<int>>()(23 / 222_fr));
}

TEST_CASE("A mixed number can be hashed", "[hash]")
{
  REQUIRE(hash(mixed_number(-72, 3 / 4_fr))
          == hash(mixed_number(-72, 3 / 4_fr)));
  REQUIRE(hash(mixed_number(889, 23 / 222_fr))
          == hash(mixed_number(889, 23 / 222_fr)));
  REQUIRE(std::hash<mixed_number<int>>()(mixed_number(-72, 3 / 4_fr))
          == std::hash<mixed_number<int>>()(mixed_number(-72, 3 / 4_fr)));
  REQUIRE(std::hash<mixed_number<int>>()(mixed_number(889, 23 / 222_fr))
          == std::hash<mixed_number<int>>()(mixed_number(889, 23 / 222_fr)));
}
