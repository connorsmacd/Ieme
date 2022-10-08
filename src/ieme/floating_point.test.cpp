#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/floating_point.hpp>

#include <ieme/fraction_literals.hpp>


using namespace ieme;
using namespace ieme::fraction_literals;


TEST_CASE("Floats can be converted to fractions", "[floating_point]")
{
  REQUIRE(to_fraction<int>(24.0f) == 24);
  REQUIRE(to_fraction<int>(0.375f) == 3 / 8_fr);
  REQUIRE(to_fraction<int>(-32.125f) == -32 - 1 / 8_fr);
  REQUIRE(is_undefined(to_fraction<int>(0.0f / 0.0f)));

  REQUIRE(to_fraction<long long int>(24.0) == 24);
  REQUIRE(to_fraction<long long int>(0.375) == 3 / 8_fr);
  REQUIRE(to_fraction<long long int>(-32.125) == -32 - 1 / 8_fr);
  REQUIRE(is_undefined(to_fraction<long long int>(0.0f / 0.0f)));
}

TEST_CASE("Fractions can be converted to floats", "[floating_point]")
{
  REQUIRE(to_float(24 / 1_fr) == 24.0f);
  REQUIRE(to_float(3 / 8_fr) == 0.375f);
  REQUIRE(to_float(-32 - 1 / 8_fr) == -32.125f);

  REQUIRE(to_double(24 / 1_fr) == 24.0);
  REQUIRE(to_double(3 / 8_fr) == 0.375);
  REQUIRE(to_double(-32 - 1 / 8_fr) == -32.125);

  REQUIRE(to_long_double(24 / 1_fr) == 24.0L);
  REQUIRE(to_long_double(3 / 8_fr) == 0.375L);
  REQUIRE(to_long_double(-32 - 1 / 8_fr) == -32.125L);
}

TEST_CASE("Floating point strings can be converted to fractions",
          "[floating_point]")
{
  REQUIRE(floating_point_string_to_fraction<int>("0.") == 0);
  REQUIRE(floating_point_string_to_fraction<int>("0.0") == 0);
  REQUIRE(floating_point_string_to_fraction<int>(".0") == 0);
  REQUIRE(floating_point_string_to_fraction<int>("5.") == 5);
  REQUIRE(floating_point_string_to_fraction<int>("5.0") == 5);
  REQUIRE(floating_point_string_to_fraction<int>(".5") == 1 / 2_fr);
  REQUIRE(floating_point_string_to_fraction<int>("5.5") == 5 + 1 / 2_fr);
  REQUIRE(floating_point_string_to_fraction<int>("58.025") == 58 + 1 / 40_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0.07") == 7 / 100_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0.0E1") == 0);
  REQUIRE(floating_point_string_to_fraction<int>("0.0e+1") == 0);
  REQUIRE(floating_point_string_to_fraction<int>("0.0E-1") == 0);
  REQUIRE(floating_point_string_to_fraction<int>("9.0e1") == 90);
  REQUIRE(floating_point_string_to_fraction<int>("9.0E+4") == 90'000);
  REQUIRE(floating_point_string_to_fraction<int>("39.0e-1") == 39 / 10_fr);
  REQUIRE(floating_point_string_to_fraction<int>("4.3E2") == 430);
  REQUIRE(floating_point_string_to_fraction<long>("4'9.3'9e-1'0")
          == 4939L / 1'000'000'000'000_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0X0.p0") == 0);
  REQUIRE(floating_point_string_to_fraction<int>("0x0.0P0") == 0);
  REQUIRE(floating_point_string_to_fraction<int>("0x.0p0") == 0);
  REQUIRE(floating_point_string_to_fraction<int>("0xa.p0") == 0xA);
  REQUIRE(floating_point_string_to_fraction<int>("0XA.0P0") == 0xA);
  REQUIRE(floating_point_string_to_fraction<int>("0X.AP0") == 0x5 / 0x8_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0xB.Dp0")
          == 0xB + 0xD / 0x10_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0Xf5.0dEP0")
          == 0xF5 + 0xDE / 0x1000_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0x0.07p0") == 0x7 / 0x100_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0X0.0P1") == 0x0);
  REQUIRE(floating_point_string_to_fraction<int>("0x0.0p+1") == 0x0);
  REQUIRE(floating_point_string_to_fraction<int>("0X0.0P-1") == 0x0);
  REQUIRE(floating_point_string_to_fraction<int>("0x9.0p1") == 0x12);
  REQUIRE(floating_point_string_to_fraction<int>("0X9.0P+4") == 0x90);
  REQUIRE(floating_point_string_to_fraction<int>("0xD9.0p-1") == 0xD9 / 0x2_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0XC.AP2") == 0x65 / 0x2_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0xC.Ap-2") == 0x65 / 0x20_fr);
  REQUIRE(floating_point_string_to_fraction<int>("0xC'1.A'1P-1'0")
          == 0xC1A1 / 0x40000_fr);

  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>(".")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("ABCDEF.")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("-1.0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0E")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0e+")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0E-")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0eA")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0E+d")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0e-B")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0P4")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0p-4")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0P+4")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("z1.0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0g")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("e1.0e+4")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0E5r")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0ey5")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.0LE5")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("1.i0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("-0x1.0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x0.1")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0p")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0P+")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0p-")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0E-4")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0e+4")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0xz1.0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0g")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0xe1.0e+4")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0E5r")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0ey5")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.0LE5")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0x1.i0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("Ox1.0")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0jx1.0g")));
  REQUIRE(is_undefined(floating_point_string_to_fraction<int>("0xu1.0E5r")));
}
