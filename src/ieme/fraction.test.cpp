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
    constexpr auto f1 = fraction(3, 4);

    REQUIRE(f1.numerator() == 3);
    REQUIRE(f1.denominator() == 4);
}

TEST_CASE("A fraction is copy constructable", "[fraction]")
{
    constexpr auto f = fraction(-5, 6);
    constexpr auto c = fraction<int>(f);

    REQUIRE(c.numerator() == -5);
    REQUIRE(c.denominator() == 6);
}

TEST_CASE("A fraction can be constructed from just a numerator", "[fraction]")
{
    constexpr auto f = fraction(5);

    REQUIRE(f.numerator() == 5);
    REQUIRE(f.denominator() == 1);
}

TEST_CASE(
    "A fraction can be implicitly converted from a numerator and denominator",
    "[fraction]")
{
    constexpr fraction<int> f1 = {3, 4};

    REQUIRE(f1.numerator() == 3);
    REQUIRE(f1.denominator() == 4);
}

TEST_CASE("A fraction can be constructed from an std::ratio", "[fraction]")
{
    constexpr auto f = fraction<int>(std::ratio<45, 22>());

    REQUIRE(f.numerator() == 45);
    REQUIRE(f.denominator() == 22);
}

TEST_CASE("A fraction can be implicitly converted from an integer",
          "[fraction]")
{
    constexpr fraction<int> f = 5;

    REQUIRE(f.numerator() == 5);
    REQUIRE(f.denominator() == 1);
}

TEST_CASE("Symbolically identical fractions are equal", "[fraction]")
{
    REQUIRE(4 / 5_Fr == 4 / 5_Fr);
    REQUIRE_FALSE(4 / 5_Fr != 4 / 5_Fr);
}

TEST_CASE("Symbolically different but equivalent fractions are equal",
          "[fraction]")
{
    REQUIRE(8 / 10_Fr == 4 / 5_Fr);
    REQUIRE_FALSE(8 / 10_Fr != 4 / 5_Fr);
}

TEST_CASE("Inequivalent fractions are not equal", "[fraction]")
{
    REQUIRE_FALSE(4 / 5_Fr == 3 / 7_Fr);
    REQUIRE(4 / 5_Fr != 3 / 7_Fr);
}

TEST_CASE("Undefined fractions are never equal to anything", "[fraction]")
{
    REQUIRE_FALSE(4 / 5_Fr == 4 / 0_Fr);
    REQUIRE(4 / 5_Fr != 4 / 0_Fr);

    REQUIRE_FALSE(4 / 0_Fr == 4 / 5_Fr);
    REQUIRE(4 / 0_Fr != 4 / 5_Fr);

    REQUIRE_FALSE(4 / 0_Fr == 4 / 0_Fr);
    REQUIRE(4 / 0_Fr != 4 / 0_Fr);
}

TEST_CASE("A lesser fraction is less than a greater fraction", "[fraction]")
{
    REQUIRE(2 / 3_Fr < 4 / 5_Fr);
    REQUIRE(2 / 3_Fr <= 4 / 5_Fr);
    REQUIRE_FALSE(2 / 3_Fr >= 4 / 5_Fr);
    REQUIRE_FALSE(2 / 3_Fr > 4 / 5_Fr);
}

TEST_CASE(
    "Equivalent fractions are neither less than or greater than eachother",
    "[fraction]")
{
    REQUIRE_FALSE(4 / 5_Fr < 4 / 5_Fr);
    REQUIRE(4 / 5_Fr <= 4 / 5_Fr);
    REQUIRE(4 / 5_Fr >= 4 / 5_Fr);
    REQUIRE_FALSE(4 / 5_Fr > 4 / 5_Fr);
}

TEST_CASE("A greater fraction is greater than a lesser fraction", "[fraction]")
{
    REQUIRE_FALSE(4 / 7_Fr < 2 / 5_Fr);
    REQUIRE_FALSE(4 / 7_Fr <= 2 / 5_Fr);
    REQUIRE(4 / 7_Fr >= 2 / 5_Fr);
    REQUIRE(4 / 7_Fr > 2 / 5_Fr);
}

TEST_CASE("Undefined fractions have no valid ordinal comparisons", "[fraction]")
{
    REQUIRE_FALSE(4 / 5_Fr < 4 / 0_Fr);
    REQUIRE_FALSE(4 / 5_Fr <= 4 / 0_Fr);
    REQUIRE_FALSE(4 / 5_Fr >= 4 / 0_Fr);
    REQUIRE_FALSE(4 / 5_Fr > 4 / 0_Fr);

    REQUIRE_FALSE(4 / 0_Fr < 4 / 5_Fr);
    REQUIRE_FALSE(4 / 0_Fr <= 4 / 5_Fr);
    REQUIRE_FALSE(4 / 0_Fr >= 4 / 5_Fr);
    REQUIRE_FALSE(4 / 0_Fr > 4 / 5_Fr);

    REQUIRE_FALSE(4 / 0_Fr < 4 / 0_Fr);
    REQUIRE_FALSE(4 / 0_Fr <= 4 / 0_Fr);
    REQUIRE_FALSE(4 / 0_Fr >= 4 / 0_Fr);
    REQUIRE_FALSE(4 / 0_Fr > 4 / 0_Fr);
}

TEST_CASE("Fractions with identical numerators and denominators are "
          "symbolically equal",
          "[fraction]")
{
    REQUIRE(symbolically_equal(7 / -9_Fr, 7 / -9_Fr));
    REQUIRE_FALSE(not_symbolically_equal(7 / -9_Fr, 7 / -9_Fr));
}

TEST_CASE("Equivalent fractions with different numerators and denominators are "
          "not symbolically equal",
          "[fraction]")
{
    REQUIRE_FALSE(symbolically_equal(14 / -18_Fr, 7 / -9_Fr));
    REQUIRE(not_symbolically_equal(14 / -18_Fr, 7 / -9_Fr));
}

TEST_CASE("Equivalent negative fractions with different sign positions are not "
          "symbolically equal",
          "[fraction]")
{
    REQUIRE_FALSE(symbolically_equal(7 / -9_Fr, -7 / 9_Fr));
    REQUIRE(not_symbolically_equal(7 / -9_Fr, -7 / 9_Fr));
}

TEST_CASE("Undefined fractions with identical numerators and denominators are "
          "symbolically equal",
          "[fraction]")
{
    REQUIRE(symbolically_equal(4 / 0_Fr, 4 / 0_Fr));
    REQUIRE_FALSE(not_symbolically_equal(4 / 0_Fr, 4 / 0_Fr));
}

TEST_CASE("A reducible fraction can be reduced", "[fraction]")
{
    REQUIRE(symbolically_equal(reduce(12 / 32_Fr), 3 / 8_Fr));
}

TEST_CASE("An already irreducible fraction can be reduced", "[fraction]")
{
    REQUIRE(symbolically_equal(reduce(7 / 9_Fr), 7 / 9_Fr));
}

TEST_CASE("Reducing a fraction will cancel out negatives", "[fraction]")
{
    REQUIRE(symbolically_equal(reduce(-45 / -80_Fr), 9 / 16_Fr));
}

TEST_CASE("A fraction's reciprocal can be calculated", "[fraction]")
{
    REQUIRE(reciprocal(4 / 19_Fr) == 19 / 4_Fr);
}

TEST_CASE("A fraction can be converted to a decimal", "[fraction]")
{
    REQUIRE(to_decimal(4 / 5_Fr) == 0.8L);
}

TEST_CASE("A fractional power of two can be computed", "[fraction]")
{
    REQUIRE(pow2(7) == 128);
    REQUIRE(pow2(0) == 1);
    REQUIRE(pow2(-3) == 1 / 8_Fr);
}

TEST_CASE("A fraction can be ceilinged")
{
    REQUIRE(ceil(7 / 3_Fr) == 3);
    REQUIRE(ceil(8 / 3_Fr) == 3);
    REQUIRE(ceil(2 / 1_Fr) == 2);
    REQUIRE(ceil(-7 / 3_Fr) == -2);
    REQUIRE(ceil(-8 / 3_Fr) == -2);
    REQUIRE(ceil(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be floored")
{
    REQUIRE(floor(7 / 3_Fr) == 2);
    REQUIRE(floor(8 / 3_Fr) == 2);
    REQUIRE(floor(2 / 1_Fr) == 2);
    REQUIRE(floor(-7 / 3_Fr) == -3);
    REQUIRE(floor(-8 / 3_Fr) == -3);
    REQUIRE(floor(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be truncated")
{
    REQUIRE(trunc(7 / 3_Fr) == 2);
    REQUIRE(trunc(8 / 3_Fr) == 2);
    REQUIRE(trunc(2 / 1_Fr) == 2);
    REQUIRE(trunc(-7 / 3_Fr) == -2);
    REQUIRE(trunc(-8 / 3_Fr) == -2);
    REQUIRE(trunc(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction can be rounded")
{
    REQUIRE(round(7 / 3_Fr) == 2);
    REQUIRE(round(8 / 3_Fr) == 3);
    REQUIRE(round(2 / 1_Fr) == 2);
    REQUIRE(round(-7 / 3_Fr) == -2);
    REQUIRE(round(-8 / 3_Fr) == -3);
    REQUIRE(round(-2 / 1_Fr) == -2);
}

TEST_CASE("A fraction's absolute value can be calculated")
{
    REQUIRE(abs(3 / 2_Fr) == 3 / 2_Fr);
    REQUIRE(abs(-3 / 2_Fr) == 3 / 2_Fr);
    REQUIRE(abs(0 / 1_Fr) == 0);
}

TEST_CASE("A fraction can be promoted", "[fraction]")
{
    REQUIRE(+(7 / 10_Fr) == 7 / 10_Fr);
}

TEST_CASE("A fraction can be negated", "[fraction]")
{
    REQUIRE(-(7 / 10_Fr) == -7 / 10_Fr);
    REQUIRE(-(-7 / 10_Fr) == 7 / 10_Fr);
}

TEST_CASE(
    "A fraction with both a positive numerator and denominator is positive",
    "[fraction]")
{
    REQUIRE(is_positive(1 / 6_Fr));
    REQUIRE_FALSE(is_negative(1 / 6_Fr));
    REQUIRE_FALSE(is_zero(1 / 6_Fr));
}

TEST_CASE(
    "A fraction with a negative numerator and positive denominator is negative",
    "[fraction]")
{
    REQUIRE_FALSE(is_positive(-1 / 6_Fr));
    REQUIRE(is_negative(-1 / 6_Fr));
    REQUIRE_FALSE(is_zero(-1 / 6_Fr));
}

TEST_CASE(
    "A fraction with a positive numerator and negative denominator is negative",
    "[fraction]")
{
    REQUIRE_FALSE(is_positive(1 / -6_Fr));
    REQUIRE(is_negative(1 / -6_Fr));
    REQUIRE_FALSE(is_zero(1 / -6_Fr));
}

TEST_CASE(
    "A fraction with both a negative numerator and denominator is positive",
    "[fraction]")
{
    REQUIRE(is_positive(-1 / -6_Fr));
    REQUIRE_FALSE(is_negative(-1 / -6_Fr));
    REQUIRE_FALSE(is_zero(-1 / -6_Fr));
}

TEST_CASE("A zero fraction is neither negative nor positive", "[fraction]")
{
    REQUIRE_FALSE(is_positive(0 / 2_Fr));
    REQUIRE_FALSE(is_negative(0 / 2_Fr));
    REQUIRE(is_zero(0 / 2_Fr));
}

TEST_CASE("An undefined fraction is neither negative nor positive",
          "[fraction]")
{
    REQUIRE_FALSE(is_positive(2 / 0_Fr));
    REQUIRE_FALSE(is_negative(2 / 0_Fr));
    REQUIRE_FALSE(is_zero(2 / 0_Fr));
}

TEST_CASE(
    "A fraction with a numerator that divides the denominator is an integer",
    "[fraction]")
{
    REQUIRE(is_integer(4 / 2_Fr));
    REQUIRE_FALSE(is_integer(4 / 3_Fr));
}

TEST_CASE("A fraction that is the reciprocal of an integer is a unit fraction",
          "[fraction]")
{
    REQUIRE(is_unit_fraction(2 / 4_Fr));
    REQUIRE_FALSE(is_unit_fraction(3 / 4_Fr));
}

TEST_CASE("A fraction with a numerator that does not divide the denominator is "
          "not an integer",
          "[fraction]")
{
    REQUIRE_FALSE(is_integer(2 / 5_Fr));
}

TEST_CASE("An undefined fraction is not an integer", "[fraction]")
{
    REQUIRE_FALSE(is_integer(9 / 0_Fr));
}

TEST_CASE("A fraction with a non-zero denominator is defined", "[fraction]")
{
    REQUIRE(is_defined(-50 / 3_Fr));
    REQUIRE_FALSE(is_undefined(-50 / 3_Fr));
}

TEST_CASE("A fraction with a zero denominator is undefined", "[fraction]")
{
    REQUIRE_FALSE(is_defined(4 / 0_Fr));
    REQUIRE(is_undefined(4 / 0_Fr));
}

TEST_CASE("Fractions with a common denominator can be added", "[fraction]")
{
    REQUIRE(1 / 5_Fr + 3 / 5_Fr == 4 / 5_Fr);
}

TEST_CASE("Fractions without a common denominator can be added", "[fraction]")
{
    REQUIRE(2 / 3_Fr + 1 / 4_Fr == 11 / 12_Fr);
}

TEST_CASE("Fractions with a common denominator can be subtracted", "[fraction]")
{
    REQUIRE(1 / 5_Fr - 3 / 5_Fr == -2 / 5_Fr);
}

TEST_CASE("Fractions without a common denominator can be subtracted",
          "[fraction]")
{
    REQUIRE(2 / 3_Fr - 1 / 4_Fr == 5 / 12_Fr);
}

TEST_CASE("Fractions can be multiplied", "[fraction]")
{
    REQUIRE(2 / 3_Fr * 3 / 7_Fr == 6 / 21_Fr);
}

TEST_CASE("Fractions can be divided", "[fraction]")
{
    REQUIRE((2 / 3_Fr) / (3 / 11_Fr) == 22 / 9_Fr);
}

TEST_CASE("The remainder of two fractions can be calculated", "[fraction]")
{
    REQUIRE((19 / 21_Fr) % (4 / 21_Fr) == 3 / 21_Fr);
    REQUIRE((4 / 7_Fr) % (2 / 5_Fr) == 6 / 35_Fr);
    REQUIRE((-2 / 5_Fr) % (2 / 3_Fr) == -6 / 15_Fr);
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
