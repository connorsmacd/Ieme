#ifndef IEME_LIMITS_HPP
#define IEME_LIMITS_HPP

#include <ieme/fraction.hpp>

#include <limits>


namespace ieme {


template <typename T>
class limits;


template <typename Rep, typename Ops>
class limits<fraction<Rep, Ops>> {

public:
  using rep_type = Rep;
  using ops_type = Ops;
  using fraction_type = fraction<Rep, Ops>;

  static constexpr fraction_type min() noexcept;
  static constexpr fraction_type max() noexcept;
  static constexpr fraction_type smallest() noexcept;
  static constexpr fraction_type undefined() noexcept;
};


}; // namespace ieme


namespace std {


template <typename Rep, typename Ops>
class numeric_limits<ieme::fraction<Rep, Ops>> {

public:
  static constexpr bool is_specialized = true;
  static constexpr bool is_signed = numeric_limits<Rep>::is_signed;
  static constexpr bool is_integer = false;
  static constexpr bool is_exact = true;
  static constexpr bool has_infinity = false;
  static constexpr bool has_quiet_NaN = true;
  static constexpr bool has_signaling_NaN = false;
  static constexpr float_denorm_style has_denorm = denorm_indeterminate;
  static constexpr bool has_denorm_loss = false;
  static constexpr float_round_style round_style = round_indeterminate;
  static constexpr bool is_iec559 = false;
  static constexpr bool is_bounded = numeric_limits<Rep>::is_bounded;
  static constexpr bool is_modulo = numeric_limits<Rep>::is_modulo;
  static constexpr int digits = numeric_limits<Rep>::digits;
  static constexpr int digits10 = numeric_limits<Rep>::digits10;
  static constexpr int max_digits10 = numeric_limits<Rep>::max_digits10;
  static constexpr int radix = numeric_limits<Rep>::radix;
  static constexpr int min_exponent = numeric_limits<Rep>::min_exponent;
  static constexpr int min_exponent10 = numeric_limits<Rep>::min_exponent10;
  static constexpr int max_exponent = numeric_limits<Rep>::max_exponent;
  static constexpr int max_exponent10 = numeric_limits<Rep>::max_exponent10;
  static constexpr bool traps = false;
  static constexpr bool tinyness_before = numeric_limits<Rep>::tinyness_before;

  static constexpr ieme::fraction<Rep, Ops> min() noexcept;
  static constexpr ieme::fraction<Rep, Ops> lowest() noexcept;
  static constexpr ieme::fraction<Rep, Ops> max() noexcept;
  static constexpr ieme::fraction<Rep, Ops> epsilon() noexcept;
  static constexpr ieme::fraction<Rep, Ops> round_error() noexcept;
  static constexpr ieme::fraction<Rep, Ops> infinity() noexcept;
  static constexpr ieme::fraction<Rep, Ops> quiet_NaN() noexcept;
  static constexpr ieme::fraction<Rep, Ops> signaling_NaN() noexcept;
  static constexpr ieme::fraction<Rep, Ops> denorm_min() noexcept;
};


}; // namespace std


// =============================================================================


namespace ieme {


template <typename Rep, typename Ops>
constexpr auto limits<fraction<Rep, Ops>>::max() noexcept -> fraction_type
{
  return std::numeric_limits<Rep>::max();
}

template <typename Rep, typename Ops>
constexpr auto limits<fraction<Rep, Ops>>::min() noexcept -> fraction_type
{
  return std::numeric_limits<Rep>::min();
}

template <typename Rep, typename Ops>
constexpr auto limits<fraction<Rep, Ops>>::smallest() noexcept -> fraction_type
{
  return {Rep(1), std::numeric_limits<Rep>::max()};
}

template <typename Rep, typename Ops>
constexpr auto limits<fraction<Rep, Ops>>::undefined() noexcept -> fraction_type
{
  return {Rep(0), Rep(0)};
}


}; // namespace ieme


namespace std {


template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::min() noexcept
{
  return ieme::limits<ieme::fraction<Rep, Ops>>::min();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::lowest() noexcept
{
  return ieme::limits<ieme::fraction<Rep, Ops>>::min();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::max() noexcept
{
  return ieme::limits<ieme::fraction<Rep, Ops>>::max();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::epsilon() noexcept
{
  return ieme::limits<ieme::fraction<Rep, Ops>>::smallest();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::round_error() noexcept
{
  return numeric_limits<Rep>::round_error();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::infinity() noexcept
{
  return numeric_limits<Rep>::infinity();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::quiet_NaN() noexcept
{
  return ieme::limits<ieme::fraction<Rep, Ops>>::undefined();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::signaling_NaN() noexcept
{
  return numeric_limits<Rep>::signaling_NaN();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::denorm_min() noexcept
{
  return numeric_limits<Rep>::denorm_min();
}


}; // namespace std


#endif
