#ifndef IEME_CHRONO_HPP
#define IEME_CHRONO_HPP

#include <ieme/fraction.hpp>
#include <ieme/limits.hpp>
#include <ieme/mixed_number.hpp>

#include <chrono>
#include <ratio>


namespace std {
namespace chrono {


template <typename Rep, typename Ops>
struct treat_as_floating_point<ieme::fraction<Rep, Ops>> {
  static constexpr bool value = true;
};


}; // namespace chrono
}; // namespace std


namespace ieme {
namespace chrono {


template <typename Duration, typename Ops = ops::defaults>
using make_duration_fractional
  = std::chrono::duration<fraction<typename Duration::rep, Ops>,
                          typename Duration::period>;

using nanoseconds = make_duration_fractional<std::chrono::nanoseconds>;
using microseconds = make_duration_fractional<std::chrono::microseconds>;
using milliseconds = make_duration_fractional<std::chrono::milliseconds>;
using seconds = make_duration_fractional<std::chrono::seconds>;
using minutes = make_duration_fractional<std::chrono::minutes>;
using hours = make_duration_fractional<std::chrono::hours>;

template <typename Rep, typename Period, typename Ops = ops::defaults>
constexpr make_duration_fractional<std::chrono::duration<Rep, Period>, Ops>
to_fractional(const std::chrono::duration<Rep, Period>& duration) noexcept;


template <typename TimePoint, typename Ops = ops::defaults>
using make_time_point_fractional = std::chrono::time_point<
  typename TimePoint::clock,
  make_duration_fractional<typename TimePoint::duration, Ops>>;

template <typename Clock, typename Duration, typename Ops = ops::defaults>
constexpr make_time_point_fractional<std::chrono::time_point<Clock, Duration>,
                                     Ops>
to_fractional(
  const std::chrono::time_point<Clock, Duration>& time_point) noexcept;


template <typename UnderlyingClock,
          typename Period = typename UnderlyingClock::period,
          typename FractionRep = typename UnderlyingClock::rep,
          typename Ops = ops::defaults>
class fractional_clock {

public:
  using underlying_clock_type = UnderlyingClock;
  using period_type = Period;
  using fraction_rep_type = FractionRep;
  using ops_type = Ops;
  using fraction_type = fraction<fraction_rep_type, ops_type>;

  using rep = fraction_type;
  using period = period_type;
  using duration = std::chrono::duration<rep, period>;
  using time_point = std::chrono::time_point<underlying_clock_type, duration>;

  static constexpr bool is_steady = underlying_clock_type::is_steady;

  static time_point now() noexcept { return underlying_clock_type::now(); }
};


// ============================================================================


template <typename Rep, typename Period, typename Ops>
constexpr make_duration_fractional<std::chrono::duration<Rep, Period>, Ops>
to_fractional(const std::chrono::duration<Rep, Period>& duration) noexcept
{
  return make_duration_fractional<std::chrono::duration<Rep, Period>, Ops>(
    duration);
}

template <typename Clock, typename Duration, typename Ops>
constexpr make_time_point_fractional<std::chrono::time_point<Clock, Duration>,
                                     Ops>
to_fractional(
  const std::chrono::time_point<Clock, Duration>& time_point) noexcept
{
  return make_time_point_fractional<std::chrono::time_point<Clock, Duration>,
                                    Ops>(time_point);
}


}; // namespace chrono
}; // namespace ieme


#endif
