#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/chrono.hpp>

#include <ieme/fraction_literals.hpp>


using namespace ieme;
using namespace ieme::chrono;
using namespace ieme::fraction_literals;

using namespace std::chrono_literals;


TEST_CASE("Integer durations can be implicitly converted to fraction durations",
          "[chrono]")
{
  REQUIRE(microseconds(1s).count() == 1'000'000);
  REQUIRE(hours(30min).count() == 1 / 2_fr);
}

TEST_CASE("Fraction durations can be constructed using integer durations",
          "[chrono]")
{
  auto const d = to_fractional(62h);

  REQUIRE(std::ratio_equal_v<decltype(d)::period, std::chrono::hours::period>);
  REQUIRE(d.count() == 62);
}

TEST_CASE("Fraction time points can be constructed using integer time points",
          "[chrono]")
{
  auto const t = to_fractional(std::chrono::system_clock::time_point(57s));
  REQUIRE(t.time_since_epoch() == seconds(57));
}

TEST_CASE("Any clock can be wrapped into a fractional clock", "[clock]")
{
  using clock_type = clock_wrapper<std::chrono::system_clock, std::ratio<1>>;

  REQUIRE(clock_type::is_steady == std::chrono::system_clock::is_steady);

  auto const now = clock_type::now();

  REQUIRE(std::ratio_equal_v<decltype(now)::period, std::ratio<1>>);
  REQUIRE(std::is_same_v<typename decltype(now)::rep::rep_type,
                         std::chrono::system_clock::rep>);
}
