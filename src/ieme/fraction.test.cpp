#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/fraction.hpp>

#include <sstream>


using namespace ieme;


TEST_CASE("A fraction is default constructable to 0/1", "[fraction]")
{
    constexpr auto f = fraction<int>();

    REQUIRE(f.numerator() == 0);
    REQUIRE(f.denominator() == 1);
}

TEST_CASE("A fraction can be constructed from a numerator and denominator",
          "[fraction]")
{
    constexpr auto f1 = fraction<int>(3, 4);

    REQUIRE(f1.numerator() == 3);
    REQUIRE(f1.denominator() == 4);
}

TEST_CASE("A fraction is copy constructable", "[fraction]")
{
    constexpr auto f = fraction<int>(-5, 6);
    constexpr auto c = fraction<int>(f);

    REQUIRE(c.numerator() == -5);
    REQUIRE(c.denominator() == 6);
}

TEST_CASE("A fraction can be constructed from just a numerator", "[fraction]")
{
    constexpr auto f = fraction<int>(5);

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

TEST_CASE("A fraction can be implicitly converted from an integer",
          "[fraction]")
{
    constexpr fraction<int> f = 5;

    REQUIRE(f.numerator() == 5);
    REQUIRE(f.denominator() == 1);
}

TEST_CASE("Symbolically identical fractions are equal", "[fraction]")
{
    REQUIRE(fraction<int>(4, 5) == fraction<int>(4, 5));
    REQUIRE_FALSE(fraction<int>(4, 5) != fraction<int>(4, 5));
}

TEST_CASE("Symbolically different but equivalent fractions are equal",
          "[fraction]")
{
    REQUIRE(fraction<int>(8, 10) == fraction<int>(4, 5));
    REQUIRE_FALSE(fraction<int>(8, 10) != fraction<int>(4, 5));
}

TEST_CASE("Inequivalent fractions are not equal", "[fraction]")
{
    REQUIRE_FALSE(fraction<int>(4, 5) == fraction<int>(3, 7));
    REQUIRE(fraction<int>(4, 5) != fraction<int>(3, 7));
}

TEST_CASE("Undefined fractions are never equal to anything", "[fraction]")
{
    REQUIRE_FALSE(fraction<int>(4, 5) == fraction<int>(4, 0));
    REQUIRE(fraction<int>(4, 5) != fraction<int>(4, 0));

    REQUIRE_FALSE(fraction<int>(4, 0) == fraction<int>(4, 5));
    REQUIRE(fraction<int>(4, 0) != fraction<int>(4, 5));

    REQUIRE_FALSE(fraction<int>(4, 0) == fraction<int>(4, 0));
    REQUIRE(fraction<int>(4, 0) != fraction<int>(4, 0));
}

TEST_CASE("A lesser fraction is less than a greater fraction", "[fraction]")
{
    REQUIRE(fraction<int>(2, 3) < fraction<int>(4, 5));
    REQUIRE(fraction<int>(2, 3) <= fraction<int>(4, 5));
    REQUIRE_FALSE(fraction<int>(2, 3) >= fraction<int>(4, 5));
    REQUIRE_FALSE(fraction<int>(2, 3) > fraction<int>(4, 5));
}

TEST_CASE(
    "Equivalent fractions are neither less than or greater than eachother",
    "[fraction]")
{
    REQUIRE_FALSE(fraction<int>(4, 5) < fraction<int>(4, 5));
    REQUIRE(fraction<int>(4, 5) <= fraction<int>(4, 5));
    REQUIRE(fraction<int>(4, 5) >= fraction<int>(4, 5));
    REQUIRE_FALSE(fraction<int>(4, 5) > fraction<int>(4, 5));
}

TEST_CASE("A greater fraction is greater than a lesser fraction", "[fraction]")
{
    REQUIRE_FALSE(fraction<int>(4, 7) < fraction<int>(2, 5));
    REQUIRE_FALSE(fraction<int>(4, 7) <= fraction<int>(2, 5));
    REQUIRE(fraction<int>(4, 7) >= fraction<int>(2, 5));
    REQUIRE(fraction<int>(4, 7) > fraction<int>(2, 5));
}

TEST_CASE("Undefined fractions have no valid ordinal comparisons", "[fraction]")
{
    REQUIRE_FALSE(fraction<int>(4, 5) < fraction<int>(4, 0));
    REQUIRE_FALSE(fraction<int>(4, 5) <= fraction<int>(4, 0));
    REQUIRE_FALSE(fraction<int>(4, 5) >= fraction<int>(4, 0));
    REQUIRE_FALSE(fraction<int>(4, 5) > fraction<int>(4, 0));

    REQUIRE_FALSE(fraction<int>(4, 0) < fraction<int>(4, 5));
    REQUIRE_FALSE(fraction<int>(4, 0) <= fraction<int>(4, 5));
    REQUIRE_FALSE(fraction<int>(4, 0) >= fraction<int>(4, 5));
    REQUIRE_FALSE(fraction<int>(4, 0) > fraction<int>(4, 5));

    REQUIRE_FALSE(fraction<int>(4, 0) < fraction<int>(4, 0));
    REQUIRE_FALSE(fraction<int>(4, 0) <= fraction<int>(4, 0));
    REQUIRE_FALSE(fraction<int>(4, 0) >= fraction<int>(4, 0));
    REQUIRE_FALSE(fraction<int>(4, 0) > fraction<int>(4, 0));
}

TEST_CASE("Fractions with identical numerators and denominators are "
          "symbolically equal",
          "[fraction]")
{
    REQUIRE(symbolically_equal(fraction<int>(7, -9), fraction<int>(7, -9)));
    REQUIRE_FALSE(
        not_symbolically_equal(fraction<int>(7, -9), fraction<int>(7, -9)));
}

TEST_CASE("Equivalent fractions with different numerators and denominators are "
          "not symbolically equal",
          "[fraction]")
{
    REQUIRE_FALSE(
        symbolically_equal(fraction<int>(14, -18), fraction<int>(7, -9)));
    REQUIRE(
        not_symbolically_equal(fraction<int>(14, -18), fraction<int>(7, -9)));
}

TEST_CASE("Equivalent negative fractions with different sign positions are not "
          "symbolically equal",
          "[fraction]")
{
    REQUIRE_FALSE(
        symbolically_equal(fraction<int>(7, -9), fraction<int>(-7, 9)));
    REQUIRE(not_symbolically_equal(fraction<int>(7, -9), fraction<int>(-7, 9)));
}

TEST_CASE("Undefined fractions with identical numerators and denominators are "
          "symbolically equal",
          "[fraction]")
{
    REQUIRE(symbolically_equal(fraction<int>(4, 0), fraction<int>(4, 0)));
    REQUIRE_FALSE(
        not_symbolically_equal(fraction<int>(4, 0), fraction<int>(4, 0)));
}

TEST_CASE("A reducible fraction can be reduced", "[fraction]")
{
    REQUIRE(
        symbolically_equal(reduce(fraction<int>(12, 32)), fraction<int>(3, 8)));
}

TEST_CASE("An already irreducible fraction can be reduced", "[fraction]")
{
    REQUIRE(
        symbolically_equal(reduce(fraction<int>(7, 9)), fraction<int>(7, 9)));
}

TEST_CASE("A fraction's sign position can be switched", "[fraction]")
{
    REQUIRE(
        symbolically_equal(fraction<int>(10, 13).with_switched_sign_position(),
                           fraction<int>(10, 13)));
    REQUIRE(
        symbolically_equal(fraction<int>(-10, 13).with_switched_sign_position(),
                           fraction<int>(10, -13)));
    REQUIRE(
        symbolically_equal(fraction<int>(10, -13).with_switched_sign_position(),
                           fraction<int>(-10, 13)));
    REQUIRE(symbolically_equal(
        fraction<int>(-10, -13).with_switched_sign_position(),
        fraction<int>(-10, -13)));
}

TEST_CASE("An equivalent fraction with minimal negative signs can be created",
          "[fraction]")
{
    REQUIRE(
        symbolically_equal(fraction<int>(10, 13).with_minimal_negative_signs(),
                           fraction<int>(10, 13)));
    REQUIRE(
        symbolically_equal(fraction<int>(-10, 13).with_minimal_negative_signs(),
                           fraction<int>(-10, 13)));
    REQUIRE(
        symbolically_equal(fraction<int>(10, -13).with_minimal_negative_signs(),
                           fraction<int>(10, -13)));
    REQUIRE(symbolically_equal(
        fraction<int>(-10, -13).with_minimal_negative_signs(),
        fraction<int>(10, 13)));
}

TEST_CASE("A fraction's reciprocal can be calculated", "[fraction]")
{
    REQUIRE(reciprocal(fraction<int>(4, 19)) == fraction<int>(19, 4));
}

TEST_CASE("A fraction can be converted to a decimal", "[fraction]")
{
    REQUIRE(to_decimal(fraction<int>(4, 5)) == 0.8L);
}

TEST_CASE("A fractional power of two can be computed", "[fraction]")
{
    REQUIRE(pow2(7) == 128);
    REQUIRE(pow2(0) == 1);
    REQUIRE(pow2(-3) == fraction<int>(1, 8));
}

TEST_CASE("A fraction can be ceilinged")
{
    REQUIRE(ceil(fraction<int>(7, 3)) == 3);
    REQUIRE(ceil(fraction<int>(8, 3)) == 3);
    REQUIRE(ceil(fraction<int>(2)) == 2);
    REQUIRE(ceil(fraction<int>(-7, 3)) == -2);
    REQUIRE(ceil(fraction<int>(-8, 3)) == -2);
    REQUIRE(ceil(fraction<int>(-2)) == -2);
}

TEST_CASE("A fraction can be floored")
{
    REQUIRE(floor(fraction<int>(7, 3)) == 2);
    REQUIRE(floor(fraction<int>(8, 3)) == 2);
    REQUIRE(floor(fraction<int>(2)) == 2);
    REQUIRE(floor(fraction<int>(-7, 3)) == -3);
    REQUIRE(floor(fraction<int>(-8, 3)) == -3);
    REQUIRE(floor(fraction<int>(-2)) == -2);
}

TEST_CASE("A fraction can be truncated")
{
    REQUIRE(trunc(fraction<int>(7, 3)) == 2);
    REQUIRE(trunc(fraction<int>(8, 3)) == 2);
    REQUIRE(trunc(fraction<int>(2)) == 2);
    REQUIRE(trunc(fraction<int>(-7, 3)) == -2);
    REQUIRE(trunc(fraction<int>(-8, 3)) == -2);
    REQUIRE(trunc(fraction<int>(-2)) == -2);
}

TEST_CASE("A fraction can be rounded")
{
    REQUIRE(round(fraction<int>(7, 3)) == 2);
    REQUIRE(round(fraction<int>(8, 3)) == 3);
    REQUIRE(round(fraction<int>(2)) == 2);
    REQUIRE(round(fraction<int>(-7, 3)) == -2);
    REQUIRE(round(fraction<int>(-8, 3)) == -3);
    REQUIRE(round(fraction<int>(-2)) == -2);
}

TEST_CASE("A fraction's absolute value can be calculated")
{
    REQUIRE(abs(fraction<int>(3, 2)) == fraction<int>(3, 2));
    REQUIRE(abs(fraction<int>(-3, 2)) == fraction<int>(3, 2));
    REQUIRE(abs(fraction<int>(0)) == 0);
}

TEST_CASE("A fraction can be promoted", "[fraction]")
{
    REQUIRE(+fraction<int>(7, 10) == fraction<int>(7, 10));
}

TEST_CASE("A fraction can be negated", "[fraction]")
{
    REQUIRE(-fraction<int>(7, 10) == fraction<int>(-7, 10));
    REQUIRE(-fraction<int>(-7, 10) == fraction<int>(7, 10));
}

TEST_CASE("A fraction with both a positive numerator and denominator has 0 "
          "negative signs",
          "[fraction]")
{
    REQUIRE(num_negative_signs(fraction<int>(1, 6)) == 0);
}

TEST_CASE("A fraction with a negative numerator and positive denominator has 1 "
          "negative signs",
          "[fraction]")
{
    REQUIRE(num_negative_signs(fraction<int>(-1, 6)) == 1);
}

TEST_CASE("A fraction with a positive numerator and negative denominator has 1 "
          "negative signs",
          "[fraction]")
{
    REQUIRE(num_negative_signs(fraction<int>(1, -6)) == 1);
}

TEST_CASE("A fraction with both a negative numerator and denominator has 2 "
          "negative signs",
          "[fraction]")
{
    REQUIRE(num_negative_signs(fraction<int>(-1, -6)) == 2);
}

TEST_CASE(
    "A fraction with both a positive numerator and denominator is positive",
    "[fraction]")
{
    REQUIRE(is_positive(fraction<int>(1, 6)));
    REQUIRE_FALSE(is_negative(fraction<int>(1, 6)));
    REQUIRE_FALSE(is_zero(fraction<int>(1, 6)));
}

TEST_CASE(
    "A fraction with a negative numerator and positive denominator is negative",
    "[fraction]")
{
    REQUIRE_FALSE(is_positive(fraction<int>(-1, 6)));
    REQUIRE(is_negative(fraction<int>(-1, 6)));
    REQUIRE_FALSE(is_zero(fraction<int>(-1, 6)));
}

TEST_CASE(
    "A fraction with a positive numerator and negative denominator is negative",
    "[fraction]")
{
    REQUIRE_FALSE(is_positive(fraction<int>(1, -6)));
    REQUIRE(is_negative(fraction<int>(1, -6)));
    REQUIRE_FALSE(is_zero(fraction<int>(1, -6)));
}

TEST_CASE(
    "A fraction with both a negative numerator and denominator is positive",
    "[fraction]")
{
    REQUIRE(is_positive(fraction<int>(-1, -6)));
    REQUIRE_FALSE(is_negative(fraction<int>(-1, -6)));
    REQUIRE_FALSE(is_zero(fraction<int>(-1, -6)));
}

TEST_CASE("A zero fraction is neither negative nor positive", "[fraction]")
{
    REQUIRE_FALSE(is_positive(fraction<int>(0, 2)));
    REQUIRE_FALSE(is_negative(fraction<int>(0, 2)));
    REQUIRE(is_zero(fraction<int>(0, 2)));
}

TEST_CASE("An undefined fraction is neither negative nor positive",
          "[fraction]")
{
    REQUIRE_FALSE(is_positive(fraction<int>(2, 0)));
    REQUIRE_FALSE(is_negative(fraction<int>(2, 0)));
    REQUIRE_FALSE(is_zero(fraction<int>(2, 0)));
}

TEST_CASE(
    "A fraction with a numerator that divides the denominator is an integer",
    "[fraction]")
{
    REQUIRE(is_integer(fraction<int>(4, 2)));
    REQUIRE_FALSE(is_integer(fraction<int>(4, 3)));
}

TEST_CASE("A fraction that is the reciprocal of an integer is a unit fraction",
          "[fraction]")
{
    REQUIRE(is_unit_fraction(fraction<int>(2, 4)));
    REQUIRE_FALSE(is_unit_fraction(fraction<int>(3, 4)));
}

TEST_CASE("A fraction with a numerator that does not divide the denominator is "
          "not an integer",
          "[fraction]")
{
    REQUIRE_FALSE(is_integer(fraction<int>(2, 5)));
}

TEST_CASE("An undefined fraction is not an integer", "[fraction]")
{
    REQUIRE_FALSE(is_integer(fraction<int>(9, 0)));
}

TEST_CASE("A fraction with a non-zero denominator is defined", "[fraction]")
{
    REQUIRE(is_defined(fraction<int>(-50, 3)));
    REQUIRE_FALSE(is_undefined(fraction<int>(-50, 3)));
}

TEST_CASE("A fraction with a zero denominator is undefined", "[fraction]")
{
    REQUIRE_FALSE(is_defined(fraction<int>(4, 0)));
    REQUIRE(is_undefined(fraction<int>(4, 0)));
}

TEST_CASE("Fractions with a common denominator can be added", "[fraction]")
{
    REQUIRE(fraction<int>(1, 5) + fraction<int>(3, 5) == fraction<int>(4, 5));
}

TEST_CASE("Fractions without a common denominator can be added", "[fraction]")
{
    REQUIRE(fraction<int>(2, 3) + fraction<int>(1, 4) == fraction<int>(11, 12));
}

TEST_CASE("Fractions with a common denominator can be subtracted", "[fraction]")
{
    REQUIRE(fraction<int>(1, 5) - fraction<int>(3, 5) == fraction<int>(-2, 5));
}

TEST_CASE("Fractions without a common denominator can be subtracted",
          "[fraction]")
{
    REQUIRE(fraction<int>(2, 3) - fraction<int>(1, 4) == fraction<int>(5, 12));
}

TEST_CASE("Fractions can be multiplied", "[fraction]")
{
    REQUIRE(fraction<int>(2, 3) * fraction<int>(3, 7) == fraction<int>(6, 21));
}

TEST_CASE("Fractions can be divided", "[fraction]")
{
    REQUIRE(fraction<int>(2, 3) / fraction<int>(3, 11) == fraction<int>(22, 9));
}

TEST_CASE("The remainder of two fractions can be calculated", "[fraction]")
{
    REQUIRE(fraction<int>(19, 21) % fraction<int>(4, 21)
            == fraction<int>(3, 21));
    REQUIRE(fraction<int>(4, 7) % fraction<int>(2, 5) == fraction<int>(6, 35));
    REQUIRE(fraction<int>(-2, 5) % fraction<int>(2, 3)
            == fraction<int>(-6, 15));
}

TEST_CASE("A fraction can be serialized", "[fraction]")
{
    const auto f = fraction<int>(-5, 7);

    std::ostringstream stream;
    stream << f;

    REQUIRE(stream.str() == "-5/7");
}

TEST_CASE("A fraction can be deserialized", "[fraction]")
{
    std::istringstream stream {" -5 / 7 "};

    fraction<int> f;
    stream >> f;

    REQUIRE(f == fraction<int>(-5, 7));
}
