#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/mixed_fraction.hpp>


using namespace ieme;


TEST_CASE("A default-constructed mixed fraction has a zero whole part and 0/1 "
          "fractional part",
          "[mixed_fraction]")
{
    constexpr auto f = mixed_fraction<int>();

    REQUIRE(f.whole_part() == 0);
    REQUIRE(symbolically_equal(f.fractional_part(), fraction<int>(0, 1)));
}

TEST_CASE("A mixed fraction can constructed from a whole and fractional part",
          "[mixed_fraction]")
{
    constexpr auto f = mixed_fraction<int>(-5, {4, 5});

    REQUIRE(f.whole_part() == -5);
    REQUIRE(symbolically_equal(f.fractional_part(), fraction<int>(4, 5)));
}

TEST_CASE("A mixed fraction can constructed from a fraction",
          "[mixed_fraction]")
{
    constexpr auto f = mixed_fraction<int>(fraction<int>(-11, 4));

    REQUIRE(f.whole_part() == -2);
    REQUIRE(symbolically_equal(f.fractional_part(), fraction<int>(3, 4)));
}

TEST_CASE("A mixed fraction can be converted to a fraction", "[mixed_fraction]")
{
    constexpr auto f = (fraction<int>) mixed_fraction<int>(-3, {1, 9});

    REQUIRE(symbolically_equal(f, {-28, 9}));
}
