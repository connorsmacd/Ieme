#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/fraction_queries.hpp>
#include <ieme/limits.hpp>

#include <ieme/fraction_literals.hpp>


using namespace ieme;
using namespace ieme::fraction_literals;


TEST_CASE("The native limits interface produces the expected values",
          "[limits]")
{
  REQUIRE(limits<fraction<int>>::max() == std::numeric_limits<int>::max());
  REQUIRE(limits<fraction<int>>::min() == std::numeric_limits<int>::min());
  REQUIRE(limits<fraction<int>>::smallest()
          == fraction(1, std::numeric_limits<int>::max()));
  REQUIRE(is_undefined(limits<fraction<int>>::undefined()));
}

TEST_CASE("The standard limits interface produces the expected values",
          "[limits]")
{
  REQUIRE(std::numeric_limits<fraction<int>>::is_specialized);
  REQUIRE(std::numeric_limits<fraction<int>>::is_signed);
  REQUIRE_FALSE(std::numeric_limits<fraction<unsigned int>>::is_signed);
  REQUIRE_FALSE(std::numeric_limits<fraction<int>>::has_infinity);
  REQUIRE(std::numeric_limits<fraction<int>>::has_quiet_NaN);
  REQUIRE_FALSE(std::numeric_limits<fraction<int>>::has_signaling_NaN);
  REQUIRE(std::numeric_limits<fraction<int>>::has_denorm
          == std::denorm_indeterminate);
  REQUIRE_FALSE(std::numeric_limits<fraction<int>>::has_denorm_loss);
  REQUIRE(std::numeric_limits<fraction<int>>::round_style
          == std::round_indeterminate);
  REQUIRE_FALSE(std::numeric_limits<fraction<int>>::is_iec559);
  REQUIRE(std::numeric_limits<fraction<int>>::is_bounded);
  REQUIRE(std::numeric_limits<fraction<unsigned int>>::is_modulo);
  REQUIRE(std::numeric_limits<fraction<int>>::digits
          == std::numeric_limits<int>::digits);
  REQUIRE(std::numeric_limits<fraction<int>>::digits10
          == std::numeric_limits<int>::digits10);
  REQUIRE(std::numeric_limits<fraction<int>>::max_digits10
          == std::numeric_limits<int>::max_digits10);
  REQUIRE(std::numeric_limits<fraction<int>>::radix
          == std::numeric_limits<int>::radix);
  REQUIRE(std::numeric_limits<fraction<int>>::min_exponent
          == std::numeric_limits<int>::min_exponent);
  REQUIRE(std::numeric_limits<fraction<int>>::min_exponent10
          == std::numeric_limits<int>::min_exponent10);
  REQUIRE(std::numeric_limits<fraction<int>>::max_exponent
          == std::numeric_limits<int>::max_exponent);
  REQUIRE(std::numeric_limits<fraction<int>>::max_exponent10
          == std::numeric_limits<int>::max_exponent10);
  REQUIRE_FALSE(std::numeric_limits<fraction<int>>::traps);
  REQUIRE(std::numeric_limits<fraction<int>>::tinyness_before
          == std::numeric_limits<int>::tinyness_before);

  REQUIRE(std::numeric_limits<fraction<int>>::min()
          == limits<fraction<int>>::min());
  REQUIRE(std::numeric_limits<fraction<int>>::lowest()
          == std::numeric_limits<int>::lowest());
  REQUIRE(std::numeric_limits<fraction<int>>::max()
          == limits<fraction<int>>::max());
  REQUIRE(std::numeric_limits<fraction<int>>::epsilon()
          == limits<fraction<int>>::smallest());
  REQUIRE(std::numeric_limits<fraction<int>>::round_error()
          == std::numeric_limits<int>::round_error());
  REQUIRE(std::numeric_limits<fraction<int>>::infinity()
          == std::numeric_limits<int>::infinity());
  REQUIRE(are_identical(std::numeric_limits<fraction<int>>::quiet_NaN(),
                        limits<fraction<int>>::undefined()));
  REQUIRE(std::numeric_limits<fraction<int>>::signaling_NaN()
          == std::numeric_limits<int>::signaling_NaN());
  REQUIRE(std::numeric_limits<fraction<int>>::denorm_min()
          == std::numeric_limits<int>::denorm_min());
}
