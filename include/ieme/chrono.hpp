#ifndef IEME_CHRONO_HPP
#define IEME_CHRONO_HPP

#include <ieme/fraction.hpp>
#include <ieme/limits.hpp>
#include <ieme/mixed_number.hpp>

#include <chrono>
#include <ratio>
#include <type_traits>


namespace std {
namespace chrono {


template <typename Rep, typename Ops>
struct treat_as_floating_point<ieme::fraction<Rep, Ops>> : std::true_type {
};


}; // namespace chrono
}; // namespace std


namespace ieme {
namespace chrono {


template <typename Rep, typename Period, typename Ops = ops::defaults>
using duration = std::chrono::duration<fraction<Rep, Ops>, Period>;

template <typename Duration, typename Ops = ops::defaults>
using duration_like
  = duration<typename Duration::rep, typename Duration::period, Ops>;

using nanoseconds = duration_like<std::chrono::nanoseconds>;
using microseconds = duration_like<std::chrono::microseconds>;
using milliseconds = duration_like<std::chrono::milliseconds>;
using seconds = duration_like<std::chrono::seconds>;
using minutes = duration_like<std::chrono::minutes>;
using hours = duration_like<std::chrono::hours>;

template <typename Rep, typename Period, typename Ops = ops::defaults>
constexpr duration_like<std::chrono::duration<Rep, Period>, Ops>
to_fractional(std::chrono::duration<Rep, Period> const& duration) noexcept;


template <typename Clock,
          typename Rep,
          typename Period,
          typename Ops = ops::defaults>
using time_point = std::chrono::time_point<Clock, duration<Rep, Period, Ops>>;

template <typename TimePoint, typename Ops = ops::defaults>
using time_point_like = time_point<typename TimePoint::clock,
                                   typename TimePoint::rep,
                                   typename TimePoint::period,
                                   Ops>;

template <typename Clock, typename Duration, typename Ops = ops::defaults>
constexpr time_point_like<std::chrono::time_point<Clock, Duration>, Ops>
to_fractional(
  std::chrono::time_point<Clock, Duration> const& time_point) noexcept;


template <typename Clock,
          typename Period = typename Clock::period,
          typename Ops = ops::defaults>
class clock_wrapper {

public:
  using clock_type = Clock;
  using ops_type = Ops;

  using rep = fraction<typename clock_type::rep, ops_type>;
  using period = typename Period::type;
  using duration
    = ::ieme::chrono::duration<typename clock_type::rep, period, ops_type>;
  using time_point = ::ieme::chrono::
    time_point<clock_type, typename clock_type::rep, period, ops_type>;

  static constexpr bool is_steady = clock_type::is_steady;

  static time_point now() noexcept { return clock_type::now(); }
};


// =============================================================================


template <typename Rep, typename Period, typename Ops>
constexpr duration_like<std::chrono::duration<Rep, Period>, Ops>
to_fractional(std::chrono::duration<Rep, Period> const& duration) noexcept
{
  return duration_like<std::chrono::duration<Rep, Period>, Ops>(duration);
}

template <typename Clock, typename Duration, typename Ops>
constexpr time_point_like<std::chrono::time_point<Clock, Duration>, Ops>
to_fractional(
  std::chrono::time_point<Clock, Duration> const& time_point) noexcept
{
  return time_point_like<std::chrono::time_point<Clock, Duration>, Ops>(
    time_point);
}


}; // namespace chrono
}; // namespace ieme


#endif
