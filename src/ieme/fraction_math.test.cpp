#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/fraction_math.hpp>

#include <ieme/fraction_queries.hpp>
#include <ieme/fraction_literals.hpp>


using namespace ieme;
using namespace ieme::fraction_literals;


TEST_CASE("A fraction's reciprocal can be calculated", "[fraction]")
{
  REQUIRE(are_identical(reciprocal(4 / -19_Fr), -19 / 4_Fr));
}

TEST_CASE("Fractions can have double negative signs cancelled", "[fraction]")
{
  REQUIRE(are_identical(cancel_signs(3 / 5_Fr), 3 / 5_Fr));
  REQUIRE(are_identical(cancel_signs(-3 / 5_Fr), -3 / 5_Fr));
  REQUIRE(are_identical(cancel_signs(3 / -5_Fr), 3 / -5_Fr));
  REQUIRE(are_identical(cancel_signs(-3 / -5_Fr), 3 / 5_Fr));
}

TEST_CASE("Fractions can be normalized to cancel double negative signs or "
          "move a negative sign to the numerator",
          "[fraction]")
{
  REQUIRE(are_identical(normalize_signs(3 / 5_Fr), 3 / 5_Fr));
  REQUIRE(are_identical(normalize_signs(-3 / 5_Fr), -3 / 5_Fr));
  REQUIRE(are_identical(normalize_signs(3 / -5_Fr), -3 / 5_Fr));
  REQUIRE(are_identical(normalize_signs(-3 / -5_Fr), 3 / 5_Fr));
}

TEST_CASE("A fraction can be reduced", "[fraction]")
{
  REQUIRE(
    are_identical(reduce(12 / 32_Fr, reduce_mode::ignore_signs), 3 / 8_Fr));
  REQUIRE(
    are_identical(reduce(12 / 32_Fr, reduce_mode::cancel_signs), 3 / 8_Fr));
  REQUIRE(
    are_identical(reduce(12 / 32_Fr, reduce_mode::normalize_signs), 3 / 8_Fr));

  REQUIRE(
    are_identical(reduce(-12 / 32_Fr, reduce_mode::ignore_signs), -3 / 8_Fr));
  REQUIRE(
    are_identical(reduce(-12 / 32_Fr, reduce_mode::cancel_signs), -3 / 8_Fr));
  REQUIRE(are_identical(reduce(-12 / 32_Fr, reduce_mode::normalize_signs),
                        -3 / 8_Fr));

  REQUIRE(
    are_identical(reduce(12 / -32_Fr, reduce_mode::ignore_signs), 3 / -8_Fr));
  REQUIRE(
    are_identical(reduce(12 / -32_Fr, reduce_mode::cancel_signs), 3 / -8_Fr));
  REQUIRE(are_identical(reduce(12 / -32_Fr, reduce_mode::normalize_signs),
                        -3 / 8_Fr));

  REQUIRE(
    are_identical(reduce(-12 / -32_Fr, reduce_mode::ignore_signs), -3 / -8_Fr));
  REQUIRE(
    are_identical(reduce(-12 / -32_Fr, reduce_mode::cancel_signs), 3 / 8_Fr));
  REQUIRE(are_identical(reduce(-12 / -32_Fr, reduce_mode::normalize_signs),
                        3 / 8_Fr));

  REQUIRE(
    are_identical(reduce(-3 / -8_Fr, reduce_mode::ignore_signs), -3 / -8_Fr));
  REQUIRE(
    are_identical(reduce(-3 / -8_Fr, reduce_mode::cancel_signs), 3 / 8_Fr));
  REQUIRE(
    are_identical(reduce(-3 / -8_Fr, reduce_mode::normalize_signs), 3 / 8_Fr));

  REQUIRE(
    are_identical(reduce(-12 / 0_Fr, reduce_mode::ignore_signs), 0 / 0_Fr));
  REQUIRE(
    are_identical(reduce(-12 / 0_Fr, reduce_mode::cancel_signs), 0 / 0_Fr));
  REQUIRE(
    are_identical(reduce(-12 / 0_Fr, reduce_mode::normalize_signs), 0 / 0_Fr));
}

TEST_CASE("A fraction's absolute value can be calculated", "[fraction]")
{
  REQUIRE(abs(3 / 2_Fr) == 3 / 2_Fr);
  REQUIRE(abs(-3 / 2_Fr) == 3 / 2_Fr);
  REQUIRE(abs(0 / 1_Fr) == 0);
}

TEST_CASE("A fraction can be truncated", "[fraction]")
{
  REQUIRE(trunc(7 / 3_Fr) == 2);
  REQUIRE(trunc(8 / 3_Fr) == 2);
  REQUIRE(trunc(2 / 1_Fr) == 2);
  REQUIRE(trunc(-7 / 3_Fr) == -2);
  REQUIRE(trunc(-8 / 3_Fr) == -2);
  REQUIRE(trunc(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be ceilinged", "[fraction]")
{
  REQUIRE(ceil(7 / 3_Fr) == 3);
  REQUIRE(ceil(8 / 3_Fr) == 3);
  REQUIRE(ceil(2 / 1_Fr) == 2);
  REQUIRE(ceil(-7 / 3_Fr) == -2);
  REQUIRE(ceil(-8 / 3_Fr) == -2);
  REQUIRE(ceil(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be floored", "[fraction]")
{
  REQUIRE(floor(7 / 3_Fr) == 2);
  REQUIRE(floor(8 / 3_Fr) == 2);
  REQUIRE(floor(2 / 1_Fr) == 2);
  REQUIRE(floor(-7 / 3_Fr) == -3);
  REQUIRE(floor(-8 / 3_Fr) == -3);
  REQUIRE(floor(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be rounded", "[fraction]")
{
  REQUIRE(round(7 / 3_Fr) == 2);
  REQUIRE(round(8 / 3_Fr) == 3);
  REQUIRE(round(2 / 1_Fr) == 2);
  REQUIRE(round(-7 / 3_Fr) == -2);
  REQUIRE(round(-8 / 3_Fr) == -3);
  REQUIRE(round(-2 / 1_Fr) == -2);
}

TEST_CASE(
  "A fraction can be converted to a whole number using various rounding modes",
  "[fraction]")
{
  REQUIRE(to_whole(7 / 3_Fr, round_mode::trunc) == 2);
  REQUIRE(to_whole(8 / 3_Fr, round_mode::trunc) == 2);
  REQUIRE(to_whole(-7 / 3_Fr, round_mode::trunc) == -2);
  REQUIRE(to_whole(-8 / 3_Fr, round_mode::trunc) == -2);

  REQUIRE(to_whole(7 / 3_Fr, round_mode::ceil) == 3);
  REQUIRE(to_whole(8 / 3_Fr, round_mode::ceil) == 3);
  REQUIRE(to_whole(-7 / 3_Fr, round_mode::ceil) == -2);
  REQUIRE(to_whole(-8 / 3_Fr, round_mode::ceil) == -2);

  REQUIRE(to_whole(7 / 3_Fr, round_mode::floor) == 2);
  REQUIRE(to_whole(8 / 3_Fr, round_mode::floor) == 2);
  REQUIRE(to_whole(-7 / 3_Fr, round_mode::floor) == -3);
  REQUIRE(to_whole(-8 / 3_Fr, round_mode::floor) == -3);

  REQUIRE(to_whole(7 / 3_Fr, round_mode::round) == 2);
  REQUIRE(to_whole(8 / 3_Fr, round_mode::round) == 3);
  REQUIRE(to_whole(-7 / 3_Fr, round_mode::round) == -2);
  REQUIRE(to_whole(-8 / 3_Fr, round_mode::round) == -3);
}

TEST_CASE("A fraction can be redenominated using trunc", "[fraction]")
{
  REQUIRE(are_identical(trunc_redenominate(4 / 3_Fr, 5), 6 / 5_Fr));
  REQUIRE(are_identical(trunc_redenominate(5 / 3_Fr, 5), 8 / 5_Fr));
  REQUIRE(are_identical(trunc_redenominate(2 / 5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(trunc_redenominate(3 / 5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(trunc_redenominate(1 / 4_Fr, 8), 2 / 8_Fr));
  REQUIRE(are_identical(trunc_redenominate(2 / 8_Fr, 4), 1 / 4_Fr));

  REQUIRE(are_identical(trunc_redenominate(-4 / 3_Fr, 5), -6 / 5_Fr));
  REQUIRE(are_identical(trunc_redenominate(-5 / 3_Fr, 5), -8 / 5_Fr));
  REQUIRE(are_identical(trunc_redenominate(-2 / 5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(trunc_redenominate(-3 / 5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(trunc_redenominate(-1 / 4_Fr, 8), -2 / 8_Fr));
  REQUIRE(are_identical(trunc_redenominate(-2 / 8_Fr, 4), -1 / 4_Fr));

  REQUIRE(are_identical(trunc_redenominate(4 / -3_Fr, 5), -6 / 5_Fr));
  REQUIRE(are_identical(trunc_redenominate(5 / -3_Fr, 5), -8 / 5_Fr));
  REQUIRE(are_identical(trunc_redenominate(2 / -5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(trunc_redenominate(3 / -5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(trunc_redenominate(1 / -4_Fr, 8), -2 / 8_Fr));
  REQUIRE(are_identical(trunc_redenominate(2 / -8_Fr, 4), -1 / 4_Fr));

  REQUIRE(are_identical(trunc_redenominate(-4 / -3_Fr, 5), 6 / 5_Fr));
  REQUIRE(are_identical(trunc_redenominate(-5 / -3_Fr, 5), 8 / 5_Fr));
  REQUIRE(are_identical(trunc_redenominate(-2 / -5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(trunc_redenominate(-3 / -5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(trunc_redenominate(-1 / -4_Fr, 8), 2 / 8_Fr));
  REQUIRE(are_identical(trunc_redenominate(-2 / -8_Fr, 4), 1 / 4_Fr));

  REQUIRE(are_identical(trunc_redenominate(4 / 3_Fr, -5), -6 / -5_Fr));
  REQUIRE(are_identical(trunc_redenominate(5 / 3_Fr, -5), -8 / -5_Fr));
  REQUIRE(are_identical(trunc_redenominate(2 / 5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(trunc_redenominate(3 / 5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(trunc_redenominate(1 / 4_Fr, -8), -2 / -8_Fr));
  REQUIRE(are_identical(trunc_redenominate(2 / 8_Fr, -4), -1 / -4_Fr));

  REQUIRE(are_identical(trunc_redenominate(-4 / 3_Fr, -5), 6 / -5_Fr));
  REQUIRE(are_identical(trunc_redenominate(-5 / 3_Fr, -5), 8 / -5_Fr));
  REQUIRE(are_identical(trunc_redenominate(-2 / 5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(trunc_redenominate(-3 / 5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(trunc_redenominate(-1 / 4_Fr, -8), 2 / -8_Fr));
  REQUIRE(are_identical(trunc_redenominate(-2 / 8_Fr, -4), 1 / -4_Fr));

  REQUIRE(are_identical(trunc_redenominate(4 / -3_Fr, -5), 6 / -5_Fr));
  REQUIRE(are_identical(trunc_redenominate(5 / -3_Fr, -5), 8 / -5_Fr));
  REQUIRE(are_identical(trunc_redenominate(2 / -5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(trunc_redenominate(3 / -5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(trunc_redenominate(1 / -4_Fr, -8), 2 / -8_Fr));
  REQUIRE(are_identical(trunc_redenominate(2 / -8_Fr, -4), 1 / -4_Fr));

  REQUIRE(are_identical(trunc_redenominate(-4 / -3_Fr, -5), -6 / -5_Fr));
  REQUIRE(are_identical(trunc_redenominate(-5 / -3_Fr, -5), -8 / -5_Fr));
  REQUIRE(are_identical(trunc_redenominate(-2 / -5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(trunc_redenominate(-3 / -5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(trunc_redenominate(-1 / -4_Fr, -8), -2 / -8_Fr));
  REQUIRE(are_identical(trunc_redenominate(-2 / -8_Fr, -4), -1 / -4_Fr));
}

TEST_CASE("A fraction can be redenominated using ceiling", "[fraction]")
{
  REQUIRE(are_identical(ceil_redenominate(4 / 3_Fr, 5), 7 / 5_Fr));
  REQUIRE(are_identical(ceil_redenominate(5 / 3_Fr, 5), 9 / 5_Fr));
  REQUIRE(are_identical(ceil_redenominate(2 / 5_Fr, 3), 2 / 3_Fr));
  REQUIRE(are_identical(ceil_redenominate(3 / 5_Fr, 3), 2 / 3_Fr));
  REQUIRE(are_identical(ceil_redenominate(1 / 4_Fr, 8), 2 / 8_Fr));
  REQUIRE(are_identical(ceil_redenominate(2 / 8_Fr, 4), 1 / 4_Fr));

  REQUIRE(are_identical(ceil_redenominate(-4 / 3_Fr, 5), -6 / 5_Fr));
  REQUIRE(are_identical(ceil_redenominate(-5 / 3_Fr, 5), -8 / 5_Fr));
  REQUIRE(are_identical(ceil_redenominate(-2 / 5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(ceil_redenominate(-3 / 5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(ceil_redenominate(-1 / 4_Fr, 8), -2 / 8_Fr));
  REQUIRE(are_identical(ceil_redenominate(-2 / 8_Fr, 4), -1 / 4_Fr));

  REQUIRE(are_identical(ceil_redenominate(4 / -3_Fr, 5), -6 / 5_Fr));
  REQUIRE(are_identical(ceil_redenominate(5 / -3_Fr, 5), -8 / 5_Fr));
  REQUIRE(are_identical(ceil_redenominate(2 / -5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(ceil_redenominate(3 / -5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(ceil_redenominate(1 / -4_Fr, 8), -2 / 8_Fr));
  REQUIRE(are_identical(ceil_redenominate(2 / -8_Fr, 4), -1 / 4_Fr));

  REQUIRE(are_identical(ceil_redenominate(-4 / -3_Fr, 5), 7 / 5_Fr));
  REQUIRE(are_identical(ceil_redenominate(-5 / -3_Fr, 5), 9 / 5_Fr));
  REQUIRE(are_identical(ceil_redenominate(-2 / -5_Fr, 3), 2 / 3_Fr));
  REQUIRE(are_identical(ceil_redenominate(-3 / -5_Fr, 3), 2 / 3_Fr));
  REQUIRE(are_identical(ceil_redenominate(-1 / -4_Fr, 8), 2 / 8_Fr));
  REQUIRE(are_identical(ceil_redenominate(-2 / -8_Fr, 4), 1 / 4_Fr));

  REQUIRE(are_identical(ceil_redenominate(4 / 3_Fr, -5), -7 / -5_Fr));
  REQUIRE(are_identical(ceil_redenominate(5 / 3_Fr, -5), -9 / -5_Fr));
  REQUIRE(are_identical(ceil_redenominate(2 / 5_Fr, -3), -2 / -3_Fr));
  REQUIRE(are_identical(ceil_redenominate(3 / 5_Fr, -3), -2 / -3_Fr));
  REQUIRE(are_identical(ceil_redenominate(1 / 4_Fr, -8), -2 / -8_Fr));
  REQUIRE(are_identical(ceil_redenominate(2 / 8_Fr, -4), -1 / -4_Fr));

  REQUIRE(are_identical(ceil_redenominate(-4 / 3_Fr, -5), 6 / -5_Fr));
  REQUIRE(are_identical(ceil_redenominate(-5 / 3_Fr, -5), 8 / -5_Fr));
  REQUIRE(are_identical(ceil_redenominate(-2 / 5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(ceil_redenominate(-3 / 5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(ceil_redenominate(-1 / 4_Fr, -8), 2 / -8_Fr));
  REQUIRE(are_identical(ceil_redenominate(-2 / 8_Fr, -4), 1 / -4_Fr));

  REQUIRE(are_identical(ceil_redenominate(4 / -3_Fr, -5), 6 / -5_Fr));
  REQUIRE(are_identical(ceil_redenominate(5 / -3_Fr, -5), 8 / -5_Fr));
  REQUIRE(are_identical(ceil_redenominate(2 / -5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(ceil_redenominate(3 / -5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(ceil_redenominate(1 / -4_Fr, -8), 2 / -8_Fr));
  REQUIRE(are_identical(ceil_redenominate(2 / -8_Fr, -4), 1 / -4_Fr));

  REQUIRE(are_identical(ceil_redenominate(-4 / -3_Fr, -5), -7 / -5_Fr));
  REQUIRE(are_identical(ceil_redenominate(-5 / -3_Fr, -5), -9 / -5_Fr));
  REQUIRE(are_identical(ceil_redenominate(-2 / -5_Fr, -3), -2 / -3_Fr));
  REQUIRE(are_identical(ceil_redenominate(-3 / -5_Fr, -3), -2 / -3_Fr));
  REQUIRE(are_identical(ceil_redenominate(-1 / -4_Fr, -8), -2 / -8_Fr));
  REQUIRE(are_identical(ceil_redenominate(-2 / -8_Fr, -4), -1 / -4_Fr));
}

TEST_CASE("A fraction can be redenominated using floor", "[fraction]")
{
  REQUIRE(are_identical(floor_redenominate(4 / 3_Fr, 5), 6 / 5_Fr));
  REQUIRE(are_identical(floor_redenominate(5 / 3_Fr, 5), 8 / 5_Fr));
  REQUIRE(are_identical(floor_redenominate(2 / 5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(floor_redenominate(3 / 5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(floor_redenominate(1 / 4_Fr, 8), 2 / 8_Fr));
  REQUIRE(are_identical(floor_redenominate(2 / 8_Fr, 4), 1 / 4_Fr));

  REQUIRE(are_identical(floor_redenominate(-4 / 3_Fr, 5), -7 / 5_Fr));
  REQUIRE(are_identical(floor_redenominate(-5 / 3_Fr, 5), -9 / 5_Fr));
  REQUIRE(are_identical(floor_redenominate(-2 / 5_Fr, 3), -2 / 3_Fr));
  REQUIRE(are_identical(floor_redenominate(-3 / 5_Fr, 3), -2 / 3_Fr));
  REQUIRE(are_identical(floor_redenominate(-1 / 4_Fr, 8), -2 / 8_Fr));
  REQUIRE(are_identical(floor_redenominate(-2 / 8_Fr, 4), -1 / 4_Fr));

  REQUIRE(are_identical(floor_redenominate(4 / -3_Fr, 5), -7 / 5_Fr));
  REQUIRE(are_identical(floor_redenominate(5 / -3_Fr, 5), -9 / 5_Fr));
  REQUIRE(are_identical(floor_redenominate(2 / -5_Fr, 3), -2 / 3_Fr));
  REQUIRE(are_identical(floor_redenominate(3 / -5_Fr, 3), -2 / 3_Fr));
  REQUIRE(are_identical(floor_redenominate(1 / -4_Fr, 8), -2 / 8_Fr));
  REQUIRE(are_identical(floor_redenominate(2 / -8_Fr, 4), -1 / 4_Fr));

  REQUIRE(are_identical(floor_redenominate(-4 / -3_Fr, 5), 6 / 5_Fr));
  REQUIRE(are_identical(floor_redenominate(-5 / -3_Fr, 5), 8 / 5_Fr));
  REQUIRE(are_identical(floor_redenominate(-2 / -5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(floor_redenominate(-3 / -5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(floor_redenominate(-1 / -4_Fr, 8), 2 / 8_Fr));
  REQUIRE(are_identical(floor_redenominate(-2 / -8_Fr, 4), 1 / 4_Fr));

  REQUIRE(are_identical(floor_redenominate(4 / 3_Fr, -5), -6 / -5_Fr));
  REQUIRE(are_identical(floor_redenominate(5 / 3_Fr, -5), -8 / -5_Fr));
  REQUIRE(are_identical(floor_redenominate(2 / 5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(floor_redenominate(3 / 5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(floor_redenominate(1 / 4_Fr, -8), -2 / -8_Fr));
  REQUIRE(are_identical(floor_redenominate(2 / 8_Fr, -4), -1 / -4_Fr));

  REQUIRE(are_identical(floor_redenominate(-4 / 3_Fr, -5), 7 / -5_Fr));
  REQUIRE(are_identical(floor_redenominate(-5 / 3_Fr, -5), 9 / -5_Fr));
  REQUIRE(are_identical(floor_redenominate(-2 / 5_Fr, -3), 2 / -3_Fr));
  REQUIRE(are_identical(floor_redenominate(-3 / 5_Fr, -3), 2 / -3_Fr));
  REQUIRE(are_identical(floor_redenominate(-1 / 4_Fr, -8), 2 / -8_Fr));
  REQUIRE(are_identical(floor_redenominate(-2 / 8_Fr, -4), 1 / -4_Fr));

  REQUIRE(are_identical(floor_redenominate(4 / -3_Fr, -5), 7 / -5_Fr));
  REQUIRE(are_identical(floor_redenominate(5 / -3_Fr, -5), 9 / -5_Fr));
  REQUIRE(are_identical(floor_redenominate(2 / -5_Fr, -3), 2 / -3_Fr));
  REQUIRE(are_identical(floor_redenominate(3 / -5_Fr, -3), 2 / -3_Fr));
  REQUIRE(are_identical(floor_redenominate(1 / -4_Fr, -8), 2 / -8_Fr));
  REQUIRE(are_identical(floor_redenominate(2 / -8_Fr, -4), 1 / -4_Fr));

  REQUIRE(are_identical(floor_redenominate(-4 / -3_Fr, -5), -6 / -5_Fr));
  REQUIRE(are_identical(floor_redenominate(-5 / -3_Fr, -5), -8 / -5_Fr));
  REQUIRE(are_identical(floor_redenominate(-2 / -5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(floor_redenominate(-3 / -5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(floor_redenominate(-1 / -4_Fr, -8), -2 / -8_Fr));
  REQUIRE(are_identical(floor_redenominate(-2 / -8_Fr, -4), -1 / -4_Fr));
}

TEST_CASE("A fraction can be redenominated using round", "[fraction]")
{
  REQUIRE(are_identical(round_redenominate(4 / 3_Fr, 5), 7 / 5_Fr));
  REQUIRE(are_identical(round_redenominate(5 / 3_Fr, 5), 8 / 5_Fr));
  REQUIRE(are_identical(round_redenominate(2 / 5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(round_redenominate(3 / 5_Fr, 3), 2 / 3_Fr));
  REQUIRE(are_identical(round_redenominate(1 / 4_Fr, 8), 2 / 8_Fr));
  REQUIRE(are_identical(round_redenominate(2 / 8_Fr, 4), 1 / 4_Fr));

  REQUIRE(are_identical(round_redenominate(-4 / 3_Fr, 5), -7 / 5_Fr));
  REQUIRE(are_identical(round_redenominate(-5 / 3_Fr, 5), -8 / 5_Fr));
  REQUIRE(are_identical(round_redenominate(-2 / 5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(round_redenominate(-3 / 5_Fr, 3), -2 / 3_Fr));
  REQUIRE(are_identical(round_redenominate(-1 / 4_Fr, 8), -2 / 8_Fr));
  REQUIRE(are_identical(round_redenominate(-2 / 8_Fr, 4), -1 / 4_Fr));

  REQUIRE(are_identical(round_redenominate(4 / -3_Fr, 5), -7 / 5_Fr));
  REQUIRE(are_identical(round_redenominate(5 / -3_Fr, 5), -8 / 5_Fr));
  REQUIRE(are_identical(round_redenominate(2 / -5_Fr, 3), -1 / 3_Fr));
  REQUIRE(are_identical(round_redenominate(3 / -5_Fr, 3), -2 / 3_Fr));
  REQUIRE(are_identical(round_redenominate(1 / -4_Fr, 8), -2 / 8_Fr));
  REQUIRE(are_identical(round_redenominate(2 / -8_Fr, 4), -1 / 4_Fr));

  REQUIRE(are_identical(round_redenominate(-4 / -3_Fr, 5), 7 / 5_Fr));
  REQUIRE(are_identical(round_redenominate(-5 / -3_Fr, 5), 8 / 5_Fr));
  REQUIRE(are_identical(round_redenominate(-2 / -5_Fr, 3), 1 / 3_Fr));
  REQUIRE(are_identical(round_redenominate(-3 / -5_Fr, 3), 2 / 3_Fr));
  REQUIRE(are_identical(round_redenominate(-1 / -4_Fr, 8), 2 / 8_Fr));
  REQUIRE(are_identical(round_redenominate(-2 / -8_Fr, 4), 1 / 4_Fr));

  REQUIRE(are_identical(round_redenominate(4 / 3_Fr, -5), -7 / -5_Fr));
  REQUIRE(are_identical(round_redenominate(5 / 3_Fr, -5), -8 / -5_Fr));
  REQUIRE(are_identical(round_redenominate(2 / 5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(round_redenominate(3 / 5_Fr, -3), -2 / -3_Fr));
  REQUIRE(are_identical(round_redenominate(1 / 4_Fr, -8), -2 / -8_Fr));
  REQUIRE(are_identical(round_redenominate(2 / 8_Fr, -4), -1 / -4_Fr));

  REQUIRE(are_identical(round_redenominate(-4 / 3_Fr, -5), 7 / -5_Fr));
  REQUIRE(are_identical(round_redenominate(-5 / 3_Fr, -5), 8 / -5_Fr));
  REQUIRE(are_identical(round_redenominate(-2 / 5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(round_redenominate(-3 / 5_Fr, -3), 2 / -3_Fr));
  REQUIRE(are_identical(round_redenominate(-1 / 4_Fr, -8), 2 / -8_Fr));
  REQUIRE(are_identical(round_redenominate(-2 / 8_Fr, -4), 1 / -4_Fr));

  REQUIRE(are_identical(round_redenominate(4 / -3_Fr, -5), 7 / -5_Fr));
  REQUIRE(are_identical(round_redenominate(5 / -3_Fr, -5), 8 / -5_Fr));
  REQUIRE(are_identical(round_redenominate(2 / -5_Fr, -3), 1 / -3_Fr));
  REQUIRE(are_identical(round_redenominate(3 / -5_Fr, -3), 2 / -3_Fr));
  REQUIRE(are_identical(round_redenominate(1 / -4_Fr, -8), 2 / -8_Fr));
  REQUIRE(are_identical(round_redenominate(2 / -8_Fr, -4), 1 / -4_Fr));

  REQUIRE(are_identical(round_redenominate(-4 / -3_Fr, -5), -7 / -5_Fr));
  REQUIRE(are_identical(round_redenominate(-5 / -3_Fr, -5), -8 / -5_Fr));
  REQUIRE(are_identical(round_redenominate(-2 / -5_Fr, -3), -1 / -3_Fr));
  REQUIRE(are_identical(round_redenominate(-3 / -5_Fr, -3), -2 / -3_Fr));
  REQUIRE(are_identical(round_redenominate(-1 / -4_Fr, -8), -2 / -8_Fr));
  REQUIRE(are_identical(round_redenominate(-2 / -8_Fr, -4), -1 / -4_Fr));
}

TEST_CASE("A fraction can be redenominated using various rounding modes",
          "[fraction]")
{
  REQUIRE(
    are_identical(redenominate(4 / 3_Fr, 5, round_mode::trunc), 6 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(5 / 3_Fr, 5, round_mode::trunc), 8 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(-4 / 3_Fr, 5, round_mode::trunc), -6 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(-5 / 3_Fr, 5, round_mode::trunc), -8 / 5_Fr));

  REQUIRE(are_identical(redenominate(4 / 3_Fr, 5, round_mode::ceil), 7 / 5_Fr));
  REQUIRE(are_identical(redenominate(5 / 3_Fr, 5, round_mode::ceil), 9 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(-4 / 3_Fr, 5, round_mode::ceil), -6 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(-5 / 3_Fr, 5, round_mode::ceil), -8 / 5_Fr));

  REQUIRE(
    are_identical(redenominate(4 / 3_Fr, 5, round_mode::floor), 6 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(5 / 3_Fr, 5, round_mode::floor), 8 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(-4 / 3_Fr, 5, round_mode::floor), -7 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(-5 / 3_Fr, 5, round_mode::floor), -9 / 5_Fr));

  REQUIRE(
    are_identical(redenominate(4 / 3_Fr, 5, round_mode::round), 7 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(5 / 3_Fr, 5, round_mode::round), 8 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(-4 / 3_Fr, 5, round_mode::round), -7 / 5_Fr));
  REQUIRE(
    are_identical(redenominate(-5 / 3_Fr, 5, round_mode::round), -8 / 5_Fr));
}

TEST_CASE("A fractional power of two can be calculated", "[fraction]")
{
  REQUIRE(pow2(7) == 128);
  REQUIRE(pow2(0) == 1);
  REQUIRE(pow2(-3) == 1 / 8_Fr);
}

TEST_CASE("A fractional power of an integer can be calculated", "[fraction]")
{
  REQUIRE(pow(3, 0) == 1);
  REQUIRE(pow(3, 1) == 3);
  REQUIRE(pow(3, 2) == 9);
  REQUIRE(pow(3, 3) == 27);
  REQUIRE(pow(-5, 8) == 390625);
  REQUIRE(pow(-5, 9) == -1953125);
  REQUIRE(pow(3, -1) == 1 / 3_Fr);
  REQUIRE(pow(3, -2) == 1 / 9_Fr);
  REQUIRE(pow(3, -3) == 1 / 27_Fr);
  REQUIRE(pow(-5, -8) == 1 / 390625_Fr);
  REQUIRE(pow(-5, -9) == -1 / 1953125_Fr);
}
