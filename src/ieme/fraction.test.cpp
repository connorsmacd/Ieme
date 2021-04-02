#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/fraction.hpp>

#include <ieme/fraction_literals.hpp>

#include <sstream>


using namespace ieme;
using namespace ieme::fraction_literals;


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

template <typename LeftRep, typename RightRep, typename Ops>
struct template_fraction_ops_test_helper final {
  using left_rep_type = LeftRep;
  using right_rep_type = RightRep;
  using left_fraction_type = fraction<LeftRep, Ops>;
  using right_fraction_type = fraction<RightRep, Ops>;
};

TEMPLATE_PRODUCT_TEST_CASE(
  "Fractions can be used in arithmetic and comparison operations and inoperate "
  "with different representations",
  "[ops]",
  template_fraction_ops_test_helper,
  ((int, int, ops::safe),
   (int, long int, ops::safe),
   (long int, int, ops::safe),
   (int, unsigned int, ops::safe),
   (unsigned int, int, ops::safe),
   (long long int, unsigned int, ops::safe),
   (unsigned int, long long int, ops::safe),
   (int, int, ops::fast),
   (int, unsigned int, ops::fast),
   (unsigned int, int, ops::fast),
   (long long int, unsigned int, ops::fast),
   (unsigned int, long long int, ops::fast)))
{
  using lr = typename TestType::left_rep_type;
  using rr = typename TestType::right_rep_type;
  using lf = typename TestType::left_fraction_type;
  using rf = typename TestType::right_fraction_type;

  SECTION("Equivalence")
  {
    REQUIRE(lf(3 / 4_fr) == rf(3 / 4_fr));
    REQUIRE_FALSE(lf(3 / 4_fr) != rf(3 / 4_fr));

    REQUIRE(lf(6 / 8_fr) == rf(3 / 4_fr));
    REQUIRE_FALSE(lf(6 / 8_fr) != rf(3 / 4_fr));

    REQUIRE(lf(3 / 1_fr) == rr(3));
    REQUIRE_FALSE(lf(3 / 1_fr) != rr(3));

    REQUIRE(lr(3) == rf(3 / 1_fr));
    REQUIRE_FALSE(lr(3) != rf(3 / 1_fr));

    REQUIRE_FALSE(lf(3 / 4_fr) == rf(4 / 3_fr));
    REQUIRE(lf(3 / 4_fr) != rf(4 / 3_fr));

    REQUIRE_FALSE(lf(4 / 1_fr) == rr(3));
    REQUIRE(lf(4 / 1_fr) != rr(3));

    REQUIRE_FALSE(lr(3) == rf(2 / 1_fr));
    REQUIRE(lr(3) != rf(2 / 1_fr));

    REQUIRE(lf(3 / 1_fr) == rr(3));
    REQUIRE_FALSE(lf(3 / 1_fr) != rr(3));

    REQUIRE_FALSE(lf(3 / 4_fr) == rf(4 / 0_fr));
    REQUIRE(lf(3 / 4_fr) != rf(4 / 0_fr));

    REQUIRE_FALSE(lf(3 / 0_fr) == rf(4 / 3_fr));
    REQUIRE(lf(3 / 0_fr) != rf(4 / 3_fr));

    REQUIRE_FALSE(lf(4 / 0_fr) == rr(3));
    REQUIRE(lf(4 / 0_fr) != rr(3));

    REQUIRE_FALSE(lr(3) == rf(2 / 0_fr));
    REQUIRE(lr(3) != rf(2 / 0_fr));
  }

  SECTION("Order")
  {
    REQUIRE(lf(3 / 5_fr) < rf(4 / 5_fr));
    REQUIRE(lf(3 / 5_fr) <= rf(4 / 5_fr));
    REQUIRE_FALSE(lf(3 / 5_fr) > rf(4 / 5_fr));
    REQUIRE_FALSE(lf(3 / 5_fr) >= rf(4 / 5_fr));

    REQUIRE(lf(3 / 5_fr) < rr(2));
    REQUIRE(lf(3 / 5_fr) <= rr(2));
    REQUIRE_FALSE(lf(3 / 5_fr) > rr(2));
    REQUIRE_FALSE(lf(3 / 5_fr) >= rr(2));

    REQUIRE(lr(0) < rf(4 / 5_fr));
    REQUIRE(lr(0) <= rf(4 / 5_fr));
    REQUIRE_FALSE(lr(0) > rf(4 / 5_fr));
    REQUIRE_FALSE(lr(0) >= rf(4 / 5_fr));

    REQUIRE_FALSE(lf(3 / 5_fr) < rf(3 / 5_fr));
    REQUIRE(lf(3 / 5_fr) <= rf(3 / 5_fr));
    REQUIRE_FALSE(lf(3 / 5_fr) > rf(3 / 5_fr));
    REQUIRE(lf(3 / 5_fr) >= rf(3 / 5_fr));

    REQUIRE_FALSE(lf(5 / 1_fr) < rr(5));
    REQUIRE(lf(5 / 1_fr) <= rr(5));
    REQUIRE_FALSE(lf(1 / 5_fr) > rr(5));
    REQUIRE(lf(5 / 1_fr) >= rr(5));

    REQUIRE_FALSE(lr(5) < rf(5 / 1_fr));
    REQUIRE(lr(5) <= rf(5 / 1_fr));
    REQUIRE_FALSE(lr(5) > rf(5 / 1_fr));
    REQUIRE(lr(5) >= rf(5 / 1_fr));

    REQUIRE_FALSE(lf(3 / 5_fr) < rf(2 / 5_fr));
    REQUIRE_FALSE(lf(3 / 5_fr) <= rf(2 / 5_fr));
    REQUIRE(lf(3 / 5_fr) > rf(2 / 5_fr));
    REQUIRE(lf(3 / 5_fr) >= rf(2 / 5_fr));

    REQUIRE_FALSE(lf(3 / 5_fr) < rr(0));
    REQUIRE_FALSE(lf(3 / 5_fr) <= rr(0));
    REQUIRE(lf(3 / 5_fr) > rr(0));
    REQUIRE(lf(3 / 5_fr) >= rr(0));

    REQUIRE_FALSE(lr(2) < rf(2 / 5_fr));
    REQUIRE_FALSE(lr(2) <= rf(2 / 5_fr));
    REQUIRE(lr(2) > rf(2 / 5_fr));
    REQUIRE(lr(2) >= rf(2 / 5_fr));

    REQUIRE_FALSE(lf(3 / 0_fr) < rf(2 / 7_fr));
    REQUIRE_FALSE(lf(3 / 0_fr) <= rf(2 / 7_fr));
    REQUIRE_FALSE(lf(3 / 0_fr) > rf(2 / 7_fr));
    REQUIRE_FALSE(lf(3 / 0_fr) >= rf(2 / 7_fr));

    REQUIRE_FALSE(lf(3 / 0_fr) < rr(3));
    REQUIRE_FALSE(lf(3 / 0_fr) <= rr(3));
    REQUIRE_FALSE(lf(3 / 0_fr) > rr(3));
    REQUIRE_FALSE(lf(3 / 0_fr) >= rr(3));

    REQUIRE_FALSE(lr(2) < rf(2 / 0_fr));
    REQUIRE_FALSE(lr(2) <= rf(2 / 0_fr));
    REQUIRE_FALSE(lr(2) > rf(2 / 0_fr));
    REQUIRE_FALSE(lr(2) >= rf(2 / 0_fr));
  }

  SECTION("Arithmetic")
  {
    REQUIRE(lf(3 / 4_fr) + rf(1 / 3_fr) == rf(13 / 12_fr));
    REQUIRE(lf(3 / 4_fr) + rr(1) == rf(7 / 4_fr));
    REQUIRE(lr(1) + rf(1 / 3_fr) == rf(4 / 3_fr));

    REQUIRE(lf(3 / 4_fr) - rf(1 / 3_fr) == rf(5 / 12_fr));
    REQUIRE(lf(5 / 4_fr) - rr(1) == rf(1 / 4_fr));
    REQUIRE(lr(1) - rf(1 / 3_fr) == rf(2 / 3_fr));

    REQUIRE(lf(3 / 4_fr) * rf(1 / 2_fr) == rf(3 / 8_fr));
    REQUIRE(lf(3 / 4_fr) * rr(2) == rf(3 / 2_fr));
    REQUIRE(lr(2) * rf(1 / 3_fr) == rf(2 / 3_fr));

    REQUIRE(lf(3 / 4_fr) / rf(3 / 2_fr) == rf(1 / 2_fr));
    REQUIRE(lf(2 / 5_fr) / rr(3) == rf(2 / 15_fr));
    REQUIRE(lr(2) / rf(3 / 5_fr) == rf(10 / 3_fr));

    REQUIRE(lf(4 / 7_fr) % rf(2 / 5_fr) == rf(6 / 35_fr));
    REQUIRE(lf(12 / 5_fr) % rr(2) == rf(2 / 5_fr));
    REQUIRE(lr(2) % rf(3 / 7_fr) == rf(2 / 7_fr));
  }

  SECTION("Compound assignment")
  {
    auto f1 = lf(3 / 4_fr);
    REQUIRE((f1 += rf(1 / 3_fr)) == rf(13 / 12_fr));

    auto f2 = lf(3 / 4_fr);
    REQUIRE((f2 += rr(1)) == rf(7 / 4_fr));

    auto f3 = lf(3 / 4_fr);
    REQUIRE((f3 -= rf(1 / 3_fr)) == rf(5 / 12_fr));

    auto f4 = lf(5 / 4_fr);
    REQUIRE((f4 -= rr(1)) == rf(1 / 4_fr));

    auto f5 = lf(3 / 4_fr);
    REQUIRE((f5 *= rf(1 / 2_fr)) == rf(3 / 8_fr));

    auto f6 = lf(3 / 4_fr);
    REQUIRE((f6 *= rr(2)) == rf(3 / 2_fr));

    auto f7 = lf(3 / 4_fr);
    REQUIRE((f7 /= rf(3 / 2_fr)) == rf(1 / 2_fr));

    auto f8 = lf(2 / 5_fr);
    REQUIRE((f8 /= rr(3)) == rf(2 / 15_fr));

    auto f9 = lf(4 / 7_fr);
    REQUIRE((f9 %= rf(2 / 5_fr)) == rf(6 / 35_fr));

    auto f10 = lf(12 / 5_fr);
    REQUIRE((f10 %= rr(2)) == rf(2 / 5_fr));
  }
}

TEST_CASE("A fraction can be promoted and negated", "[fraction]")
{
  REQUIRE(+(1 / 2_fr) == 1 / 2_fr);
  REQUIRE(+(-1 / 2_fr) == -1 / 2_fr);

  REQUIRE(-(1 / 2_fr) == -1 / 2_fr);
  REQUIRE(-(-1 / 2_fr) == 1 / 2_fr);
}

TEST_CASE("A fraction can be serialized", "[fraction]")
{
  const auto f = -5 / 7_fr;

  std::ostringstream stream;
  stream << f;

  REQUIRE(stream.str() == "-5/7");
}

TEST_CASE("A fraction can be deserialized", "[fraction]")
{
  std::istringstream stream {" -5 / 7 "};

  fraction<int> f;
  stream >> f;

  REQUIRE(f == -5 / 7_fr);
}
