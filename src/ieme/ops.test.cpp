#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/ops.hpp>


using namespace ieme;
using namespace ieme::ops;


template <typename Rep, typename Ops>
struct template_ops_test_helper {
  using raw_fraction_type = raw_fraction<Rep>;
  using ops_type = Ops;
};

TEMPLATE_PRODUCT_TEST_CASE("Ops functions produce the expected results",
                           "[ops]",
                           template_ops_test_helper,
                           ((int, safe),
                            (int, safe_reduced_i),
                            (int, safe_reduced_o),
                            (int, safe_reduced_io),
                            (int, fast),
                            (int, fast_reduced_i),
                            (int, fast_reduced_o),
                            (int, fast_reduced_io)))
{
  using rf = typename TestType::raw_fraction_type;
  using o = typename TestType::ops_type;

  SECTION("Equivalence")
  {
    REQUIRE(o::equal_to(rf(3, 4), rf(3, 4)));
    REQUIRE_FALSE(o::not_equal_to(rf(3, 4), rf(3, 4)));

    REQUIRE(o::equal_to(rf(-3, 4), rf(-3, 4)));
    REQUIRE_FALSE(o::not_equal_to(rf(-3, 4), rf(-3, 4)));

    REQUIRE(o::equal_to(rf(3, 4), rf(-3, -4)));
    REQUIRE_FALSE(o::not_equal_to(rf(3, 4), rf(-3, -4)));

    REQUIRE(o::equal_to(rf(-3, 4), rf(3, -4)));
    REQUIRE_FALSE(o::not_equal_to(rf(-3, 4), rf(3, -4)));

    REQUIRE(o::equal_to(rf(6, 8), rf(3, 4)));
    REQUIRE_FALSE(o::not_equal_to(rf(6, 8), rf(3, 4)));

    REQUIRE(o::equal_to(rf(-6, 8), rf(-3, 4)));
    REQUIRE_FALSE(o::not_equal_to(rf(-6, 8), rf(-3, 4)));

    REQUIRE(o::equal_to(rf(6, 3), 2));
    REQUIRE_FALSE(o::not_equal_to(rf(6, 3), 2));

    REQUIRE(o::equal_to(rf(-6, 3), -2));
    REQUIRE_FALSE(o::not_equal_to(rf(-6, 3), -2));

    REQUIRE(o::equal_to(2, rf(6, 3)));
    REQUIRE_FALSE(o::not_equal_to(2, rf(6, 3)));

    REQUIRE(o::equal_to(-2, rf(-6, 3)));
    REQUIRE_FALSE(o::not_equal_to(-2, rf(-6, 3)));

    REQUIRE_FALSE(o::equal_to(rf(5, 8), rf(3, 4)));
    REQUIRE(o::not_equal_to(rf(5, 8), rf(3, 4)));

    REQUIRE_FALSE(o::equal_to(rf(-5, 8), rf(-3, 4)));
    REQUIRE(o::not_equal_to(rf(-5, 8), rf(-3, 4)));

    REQUIRE_FALSE(o::equal_to(rf(6, 3), 5));
    REQUIRE(o::not_equal_to(rf(6, 3), 5));

    REQUIRE_FALSE(o::equal_to(rf(-6, 3), -5));
    REQUIRE(o::not_equal_to(rf(-6, 3), -5));

    REQUIRE_FALSE(o::equal_to(5, rf(6, 3)));
    REQUIRE(o::not_equal_to(5, rf(6, 3)));

    REQUIRE_FALSE(o::equal_to(-5, rf(-6, 3)));
    REQUIRE(o::not_equal_to(-5, rf(-6, 3)));

    REQUIRE_FALSE(o::equal_to(rf(-5, 0), rf(0, 1)));
    REQUIRE(o::not_equal_to(rf(-5, 0), rf(0, 1)));

    REQUIRE_FALSE(o::equal_to(rf(0, 1), rf(-5, 0)));
    REQUIRE(o::not_equal_to(rf(0, 1), rf(-5, 0)));

    REQUIRE_FALSE(o::equal_to(rf(-5, 0), 2));
    REQUIRE(o::not_equal_to(rf(-5, 0), 2));

    REQUIRE_FALSE(o::equal_to(2, rf(-5, 0)));
    REQUIRE(o::not_equal_to(2, rf(-5, 0)));

    REQUIRE_FALSE(o::equal_to(rf(-5, 0), rf(-5, 0)));
    REQUIRE(o::not_equal_to(rf(-5, 0), rf(-5, 0)));
  }

  SECTION("Order")
  {
    REQUIRE_FALSE(o::less(rf(3, 4), rf(3, 4)));
    REQUIRE(o::less_equal(rf(3, 4), rf(3, 4)));
    REQUIRE_FALSE(o::greater(rf(3, 4), rf(3, 4)));
    REQUIRE(o::greater_equal(rf(3, 4), rf(3, 4)));

    REQUIRE_FALSE(o::less(rf(-3, 4), rf(-3, 4)));
    REQUIRE(o::less_equal(rf(-3, 4), rf(-3, 4)));
    REQUIRE_FALSE(o::greater(rf(-3, 4), rf(-3, 4)));
    REQUIRE(o::greater_equal(rf(-3, 4), rf(-3, 4)));

    REQUIRE_FALSE(o::less(rf(3, 4), rf(-3, -4)));
    REQUIRE(o::less_equal(rf(3, 4), rf(-3, -4)));
    REQUIRE_FALSE(o::greater(rf(3, 4), rf(-3, -4)));
    REQUIRE(o::greater_equal(rf(3, 4), rf(-3, -4)));

    REQUIRE_FALSE(o::less(rf(-3, 4), rf(3, -4)));
    REQUIRE(o::less_equal(rf(-3, 4), rf(3, -4)));
    REQUIRE_FALSE(o::greater(rf(-3, 4), rf(3, -4)));
    REQUIRE(o::greater_equal(rf(-3, 4), rf(3, -4)));

    REQUIRE_FALSE(o::less(rf(6, 8), rf(3, 4)));
    REQUIRE(o::less_equal(rf(6, 8), rf(3, 4)));
    REQUIRE_FALSE(o::greater(rf(6, 8), rf(3, 4)));
    REQUIRE(o::greater_equal(rf(6, 8), rf(3, 4)));

    REQUIRE_FALSE(o::less(rf(-6, 8), rf(-3, 4)));
    REQUIRE(o::less_equal(rf(-6, 8), rf(-3, 4)));
    REQUIRE_FALSE(o::greater(rf(-6, 8), rf(-3, 4)));
    REQUIRE(o::greater_equal(rf(-6, 8), rf(-3, 4)));

    REQUIRE_FALSE(o::less(rf(6, 3), 2));
    REQUIRE(o::less_equal(rf(6, 3), 2));
    REQUIRE_FALSE(o::greater(rf(6, 3), 2));
    REQUIRE(o::greater_equal(rf(6, 3), 2));

    REQUIRE_FALSE(o::less(rf(-6, 3), -2));
    REQUIRE(o::less_equal(rf(-6, 3), -2));
    REQUIRE_FALSE(o::greater(rf(-6, 3), -2));
    REQUIRE(o::greater_equal(rf(-6, 3), -2));

    REQUIRE_FALSE(o::less(2, rf(6, 3)));
    REQUIRE(o::less_equal(2, rf(6, 3)));
    REQUIRE_FALSE(o::greater(2, rf(6, 3)));
    REQUIRE(o::greater_equal(2, rf(6, 3)));

    REQUIRE_FALSE(o::less(-2, rf(-6, 3)));
    REQUIRE(o::less_equal(-2, rf(-6, 3)));
    REQUIRE_FALSE(o::greater(-2, rf(-6, 3)));
    REQUIRE(o::greater_equal(-2, rf(-6, 3)));

    REQUIRE(o::less(rf(1, 4), rf(3, 4)));
    REQUIRE(o::less_equal(rf(1, 4), rf(3, 4)));
    REQUIRE_FALSE(o::greater(rf(1, 4), rf(3, 4)));
    REQUIRE_FALSE(o::greater_equal(rf(1, 4), rf(3, 4)));

    REQUIRE(o::less(rf(-3, 4), rf(-1, 4)));
    REQUIRE(o::less_equal(rf(-3, 4), rf(-1, 4)));
    REQUIRE_FALSE(o::greater(rf(-3, 4), rf(-1, 4)));
    REQUIRE_FALSE(o::greater_equal(rf(-3, 4), rf(-1, 4)));

    REQUIRE(o::less(rf(1, 2), rf(3, 4)));
    REQUIRE(o::less_equal(rf(1, 2), rf(3, 4)));
    REQUIRE_FALSE(o::greater(rf(1, 2), rf(3, 4)));
    REQUIRE_FALSE(o::greater_equal(rf(1, 2), rf(3, 4)));

    REQUIRE(o::less(rf(-3, 4), rf(-1, 2)));
    REQUIRE(o::less_equal(rf(-3, 4), rf(-1, 2)));
    REQUIRE_FALSE(o::greater(rf(-3, 4), rf(-1, 2)));
    REQUIRE_FALSE(o::greater_equal(rf(-3, 4), rf(-1, 2)));

    REQUIRE(o::less(rf(7, 3), 3));
    REQUIRE(o::less_equal(rf(7, 3), 3));
    REQUIRE_FALSE(o::greater(rf(7, 3), 3));
    REQUIRE_FALSE(o::greater_equal(rf(7, 3), 3));

    REQUIRE(o::less(rf(-7, 3), -2));
    REQUIRE(o::less_equal(rf(-7, 3), -2));
    REQUIRE_FALSE(o::greater(rf(-7, 3), -2));
    REQUIRE_FALSE(o::greater_equal(rf(-7, 3), -2));

    REQUIRE(o::less(2, rf(7, 3)));
    REQUIRE(o::less_equal(2, rf(7, 3)));
    REQUIRE_FALSE(o::greater(2, rf(7, 3)));
    REQUIRE_FALSE(o::greater_equal(2, rf(7, 3)));

    REQUIRE(o::less(-3, rf(-7, 3)));
    REQUIRE(o::less_equal(-3, rf(-7, 3)));
    REQUIRE_FALSE(o::greater(-3, rf(-7, 3)));
    REQUIRE_FALSE(o::greater_equal(-3, rf(-7, 3)));

    REQUIRE_FALSE(o::less(rf(3, 4), rf(1, 4)));
    REQUIRE_FALSE(o::less_equal(rf(3, 4), rf(1, 4)));
    REQUIRE(o::greater(rf(3, 4), rf(1, 4)));
    REQUIRE(o::greater_equal(rf(3, 4), rf(1, 4)));

    REQUIRE_FALSE(o::less(rf(-1, 4), rf(-3, 4)));
    REQUIRE_FALSE(o::less_equal(rf(-1, 4), rf(-3, 4)));
    REQUIRE(o::greater(rf(-1, 4), rf(-3, 4)));
    REQUIRE(o::greater_equal(rf(-1, 4), rf(-3, 4)));

    REQUIRE_FALSE(o::less(rf(3, 4), rf(1, 2)));
    REQUIRE_FALSE(o::less_equal(rf(3, 4), rf(1, 2)));
    REQUIRE(o::greater(rf(3, 4), rf(1, 2)));
    REQUIRE(o::greater_equal(rf(3, 4), rf(1, 2)));

    REQUIRE_FALSE(o::less(rf(-1, 2), rf(-3, 4)));
    REQUIRE_FALSE(o::less_equal(rf(-1, 2), rf(-3, 4)));
    REQUIRE(o::greater(rf(-1, 2), rf(-3, 4)));
    REQUIRE(o::greater_equal(rf(-1, 2), rf(-3, 4)));

    REQUIRE_FALSE(o::less(rf(7, 3), 2));
    REQUIRE_FALSE(o::less_equal(rf(7, 3), 2));
    REQUIRE(o::greater(rf(7, 3), 2));
    REQUIRE(o::greater_equal(rf(7, 3), 2));

    REQUIRE_FALSE(o::less(rf(-7, 3), -3));
    REQUIRE_FALSE(o::less_equal(rf(-7, 3), -3));
    REQUIRE(o::greater(rf(-7, 3), -3));
    REQUIRE(o::greater_equal(rf(-7, 3), -3));

    REQUIRE_FALSE(o::less(3, rf(7, 3)));
    REQUIRE_FALSE(o::less_equal(3, rf(7, 3)));
    REQUIRE(o::greater(3, rf(7, 3)));
    REQUIRE(o::greater_equal(3, rf(7, 3)));

    REQUIRE_FALSE(o::less(-2, rf(-7, 3)));
    REQUIRE_FALSE(o::less_equal(-2, rf(-7, 3)));
    REQUIRE(o::greater(-2, rf(-7, 3)));
    REQUIRE(o::greater_equal(-2, rf(-7, 3)));

    REQUIRE_FALSE(o::less(rf(-5, 0), rf(0, 1)));
    REQUIRE_FALSE(o::less_equal(rf(-5, 0), rf(0, 1)));
    REQUIRE_FALSE(o::greater(rf(-5, 0), rf(0, 1)));
    REQUIRE_FALSE(o::greater_equal(rf(-5, 0), rf(0, 1)));

    REQUIRE_FALSE(o::less(rf(0, 1), rf(-5, 0)));
    REQUIRE_FALSE(o::less_equal(rf(0, 1), rf(-5, 0)));
    REQUIRE_FALSE(o::greater(rf(0, 1), rf(-5, 0)));
    REQUIRE_FALSE(o::greater_equal(rf(0, 1), rf(-5, 0)));

    REQUIRE_FALSE(o::less(rf(-5, 0), 2));
    REQUIRE_FALSE(o::less_equal(rf(-5, 0), 2));
    REQUIRE_FALSE(o::greater(rf(-5, 0), 2));
    REQUIRE_FALSE(o::greater_equal(rf(-5, 0), 2));

    REQUIRE_FALSE(o::less(2, rf(-5, 0)));
    REQUIRE_FALSE(o::less_equal(2, rf(-5, 0)));
    REQUIRE_FALSE(o::greater(2, rf(-5, 0)));
    REQUIRE_FALSE(o::greater_equal(2, rf(-5, 0)));

    REQUIRE_FALSE(o::less(rf(-5, 0), rf(-5, 0)));
    REQUIRE_FALSE(o::less_equal(rf(-5, 0), rf(-5, 0)));
    REQUIRE_FALSE(o::greater(rf(-5, 0), rf(-5, 0)));
    REQUIRE_FALSE(o::greater_equal(rf(-5, 0), rf(-5, 0)));
  }

  SECTION("Negate")
  {
    REQUIRE(o::equal_to(o::negate(rf(2, 5)), rf(-2, 5)));
    REQUIRE(o::equal_to(o::negate(rf(-2, 5)), rf(2, 5)));
  }

  SECTION("Plus")
  {
    REQUIRE(o::equal_to(o::plus(rf(2, 5), rf(1, 5)), rf(3, 5)));
    REQUIRE(o::equal_to(o::plus(rf(2, 5), rf(-1, 5)), rf(1, 5)));
    REQUIRE(o::equal_to(o::plus(rf(-2, 5), rf(1, 5)), rf(-1, 5)));
    REQUIRE(o::equal_to(o::plus(rf(-2, 5), rf(-1, 5)), rf(-3, 5)));

    REQUIRE(o::equal_to(o::plus(rf(3, 4), rf(1, 3)), rf(13, 12)));
    REQUIRE(o::equal_to(o::plus(rf(3, 4), rf(-1, 3)), rf(5, 12)));
    REQUIRE(o::equal_to(o::plus(rf(-3, 4), rf(1, 3)), rf(-5, 12)));
    REQUIRE(o::equal_to(o::plus(rf(-3, 4), rf(-1, 3)), rf(-13, 12)));

    REQUIRE(o::equal_to(o::plus(rf(2, 5), 2), rf(12, 5)));
    REQUIRE(o::equal_to(o::plus(rf(2, 5), -2), rf(-8, 5)));
    REQUIRE(o::equal_to(o::plus(rf(-2, 5), 2), rf(8, 5)));
    REQUIRE(o::equal_to(o::plus(rf(-2, 5), -2), rf(-12, 5)));

    REQUIRE(o::equal_to(o::plus(2, rf(2, 3)), rf(8, 3)));
    REQUIRE(o::equal_to(o::plus(2, rf(-2, 3)), rf(4, 3)));
    REQUIRE(o::equal_to(o::plus(-2, rf(2, 3)), rf(-4, 3)));
    REQUIRE(o::equal_to(o::plus(-2, rf(-2, 3)), rf(-8, 3)));
  }

  SECTION("Minus")
  {
    REQUIRE(o::equal_to(o::minus(rf(2, 5), rf(1, 5)), rf(1, 5)));
    REQUIRE(o::equal_to(o::minus(rf(2, 5), rf(-1, 5)), rf(3, 5)));
    REQUIRE(o::equal_to(o::minus(rf(-2, 5), rf(1, 5)), rf(-3, 5)));
    REQUIRE(o::equal_to(o::minus(rf(-2, 5), rf(-1, 5)), rf(-1, 5)));

    REQUIRE(o::equal_to(o::minus(rf(3, 4), rf(1, 3)), rf(5, 12)));
    REQUIRE(o::equal_to(o::minus(rf(3, 4), rf(-1, 3)), rf(13, 12)));
    REQUIRE(o::equal_to(o::minus(rf(-3, 4), rf(1, 3)), rf(-13, 12)));
    REQUIRE(o::equal_to(o::minus(rf(-3, 4), rf(-1, 3)), rf(-5, 12)));

    REQUIRE(o::equal_to(o::minus(rf(2, 5), 2), rf(-8, 5)));
    REQUIRE(o::equal_to(o::minus(rf(2, 5), -2), rf(12, 5)));
    REQUIRE(o::equal_to(o::minus(rf(-2, 5), 2), rf(-12, 5)));
    REQUIRE(o::equal_to(o::minus(rf(-2, 5), -2), rf(8, 5)));

    REQUIRE(o::equal_to(o::minus(2, rf(2, 3)), rf(4, 3)));
    REQUIRE(o::equal_to(o::minus(2, rf(-2, 3)), rf(8, 3)));
    REQUIRE(o::equal_to(o::minus(-2, rf(2, 3)), rf(-8, 3)));
    REQUIRE(o::equal_to(o::minus(-2, rf(-2, 3)), rf(-4, 3)));
  }

  SECTION("Multiplies")
  {
    REQUIRE(o::equal_to(o::multiplies(rf(3, 4), rf(2, 3)), rf(1, 2)));
    REQUIRE(o::equal_to(o::multiplies(rf(3, 4), rf(-2, 3)), rf(-1, 2)));
    REQUIRE(o::equal_to(o::multiplies(rf(-3, 4), rf(2, 3)), rf(-1, 2)));
    REQUIRE(o::equal_to(o::multiplies(rf(-3, 4), rf(-2, 3)), rf(1, 2)));

    REQUIRE(o::equal_to(o::multiplies(rf(2, 5), 3), rf(6, 5)));
    REQUIRE(o::equal_to(o::multiplies(rf(2, 5), -3), rf(-6, 5)));
    REQUIRE(o::equal_to(o::multiplies(rf(-2, 5), 3), rf(-6, 5)));
    REQUIRE(o::equal_to(o::multiplies(rf(-2, 5), -3), rf(6, 5)));

    REQUIRE(o::equal_to(o::multiplies(3, rf(2, 3)), rf(6, 3)));
    REQUIRE(o::equal_to(o::multiplies(3, rf(-2, 3)), rf(-6, 3)));
    REQUIRE(o::equal_to(o::multiplies(-3, rf(2, 3)), rf(-6, 3)));
    REQUIRE(o::equal_to(o::multiplies(-3, rf(-2, 3)), rf(6, 3)));
  }

  SECTION("Divides")
  {
    REQUIRE(o::equal_to(o::divides(rf(3, 4), rf(3, 2)), rf(1, 2)));
    REQUIRE(o::equal_to(o::divides(rf(3, 4), rf(-3, 2)), rf(-1, 2)));
    REQUIRE(o::equal_to(o::divides(rf(-3, 4), rf(3, 2)), rf(-1, 2)));
    REQUIRE(o::equal_to(o::divides(rf(-3, 4), rf(-3, 2)), rf(1, 2)));

    REQUIRE(o::equal_to(o::divides(rf(2, 5), 3), rf(2, 15)));
    REQUIRE(o::equal_to(o::divides(rf(2, 5), -3), rf(-2, 15)));
    REQUIRE(o::equal_to(o::divides(rf(-2, 5), 3), rf(-2, 15)));
    REQUIRE(o::equal_to(o::divides(rf(-2, 5), -3), rf(2, 15)));

    REQUIRE(o::equal_to(o::divides(3, rf(3, 2)), rf(6, 3)));
    REQUIRE(o::equal_to(o::divides(3, rf(-3, 2)), rf(-6, 3)));
    REQUIRE(o::equal_to(o::divides(-3, rf(3, 2)), rf(-6, 3)));
    REQUIRE(o::equal_to(o::divides(-3, rf(-3, 2)), rf(6, 3)));
  }

  SECTION("Modulus")
  {
    REQUIRE(o::equal_to(o::modulus(rf(9, 11), rf(5, 11)), rf(4, 11)));
    REQUIRE(o::equal_to(o::modulus(rf(9, 11), rf(-5, 11)), rf(4, 11)));
    REQUIRE(o::equal_to(o::modulus(rf(-9, 11), rf(5, 11)), rf(-4, 11)));
    REQUIRE(o::equal_to(o::modulus(rf(-9, 11), rf(-5, 11)), rf(-4, 11)));

    REQUIRE(o::equal_to(o::modulus(rf(4, 7), rf(2, 5)), rf(6, 35)));
    REQUIRE(o::equal_to(o::modulus(rf(4, 7), rf(-2, 5)), rf(6, 35)));
    REQUIRE(o::equal_to(o::modulus(rf(-4, 7), rf(2, 5)), rf(-6, 35)));
    REQUIRE(o::equal_to(o::modulus(rf(-4, 7), rf(-2, 5)), rf(-6, 35)));

    REQUIRE(o::equal_to(o::modulus(rf(12, 5), 2), rf(2, 5)));
    REQUIRE(o::equal_to(o::modulus(rf(12, 5), -2), rf(2, 5)));
    REQUIRE(o::equal_to(o::modulus(rf(-12, 5), 2), rf(-2, 5)));
    REQUIRE(o::equal_to(o::modulus(rf(-12, 5), -2), rf(-2, 5)));

    REQUIRE(o::equal_to(o::modulus(2, rf(3, 7)), rf(2, 7)));
    REQUIRE(o::equal_to(o::modulus(2, rf(-3, 7)), rf(2, 7)));
    REQUIRE(o::equal_to(o::modulus(-2, rf(3, 7)), rf(-2, 7)));
    REQUIRE(o::equal_to(o::modulus(-2, rf(-3, 7)), rf(-2, 7)));
  }
}
