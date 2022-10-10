#ifndef IEME_LIMITS_HPP
#define IEME_LIMITS_HPP

#include <ieme/fraction.hpp>
#include <ieme/mixed_number.hpp>
#include <ieme/numbers.hpp>

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

template <typename Rep, typename Ops>
class limits<mixed_number<Rep, Ops>> {

public:
  using rep_type = Rep;
  using ops_type = Ops;
  using mixed_number_type = mixed_number<Rep, Ops>;
  using fraction_type = typename mixed_number_type::fraction_type;

  static constexpr mixed_number_type min() noexcept;
  static constexpr mixed_number_type max() noexcept;
  static constexpr mixed_number_type smallest() noexcept;
  static constexpr mixed_number_type undefined() noexcept;
};


}; // namespace ieme


namespace std {


template <typename Rep, typename Ops>
class numeric_limits<ieme::fraction<Rep, Ops>> {

public:
  using fraction_type = ieme::fraction<Rep, Ops>;
  using rep_limits_type = numeric_limits<Rep>;

  static constexpr bool is_specialized = true;
  static constexpr bool is_signed = rep_limits_type::is_signed;
  static constexpr bool is_integer = false;
  static constexpr bool is_exact = true;
  static constexpr bool has_infinity = false;
  static constexpr bool has_quiet_NaN = true;
  static constexpr bool has_signaling_NaN = false;
  static constexpr float_denorm_style has_denorm = denorm_indeterminate;
  static constexpr bool has_denorm_loss = false;
  static constexpr float_round_style round_style = round_indeterminate;
  static constexpr bool is_iec559 = false;
  static constexpr bool is_bounded = rep_limits_type::is_bounded;
  static constexpr bool is_modulo = rep_limits_type::is_modulo;
  static constexpr int digits = rep_limits_type::digits;
  static constexpr int digits10 = rep_limits_type::digits10;
  static constexpr int max_digits10 = rep_limits_type::max_digits10;
  static constexpr int radix = rep_limits_type::radix;
  static constexpr int min_exponent = rep_limits_type::min_exponent;
  static constexpr int min_exponent10 = rep_limits_type::min_exponent10;
  static constexpr int max_exponent = rep_limits_type::max_exponent;
  static constexpr int max_exponent10 = rep_limits_type::max_exponent10;
  static constexpr bool traps = false;
  static constexpr bool tinyness_before = rep_limits_type::tinyness_before;

  static constexpr fraction_type min() noexcept;
  static constexpr fraction_type lowest() noexcept;
  static constexpr fraction_type max() noexcept;
  static constexpr fraction_type epsilon() noexcept;
  static constexpr fraction_type round_error() noexcept;
  static constexpr fraction_type infinity() noexcept;
  static constexpr fraction_type quiet_NaN() noexcept;
  static constexpr fraction_type signaling_NaN() noexcept;
  static constexpr fraction_type denorm_min() noexcept;
};

template <typename Rep, typename Ops>
class numeric_limits<ieme::mixed_number<Rep, Ops>> {

public:
  using mixed_number_type = ieme::mixed_number<Rep, Ops>;
  using fraction_type = typename mixed_number_type::fraction_type;
  using fraction_limits_type = numeric_limits<fraction_type>;

  static constexpr bool is_specialized = fraction_limits_type::is_specialized;
  static constexpr bool is_signed = fraction_limits_type::is_signed;
  static constexpr bool is_integer = fraction_limits_type::is_integer;
  static constexpr bool is_exact = fraction_limits_type::is_exact;
  static constexpr bool has_infinity = fraction_limits_type::has_infinity;
  static constexpr bool has_quiet_ = fraction_limits_type::has_quiet_;
  static constexpr bool has_signaling_ = fraction_limits_type::has_signaling_;
  static constexpr float_denorm_style has_denorm
    = fraction_limits_type::has_denorm;
  static constexpr bool has_denorm_loss = fraction_limits_type::has_denorm_loss;
  static constexpr float_round_style round_style
    = fraction_limits_type::round_style;
  static constexpr bool is_iec559 = fraction_limits_type::is_iec559;
  static constexpr bool is_bounded = fraction_limits_type::is_bounded;
  static constexpr bool is_modulo = fraction_limits_type::is_modulo;
  static constexpr int digits = fraction_limits_type::digits;
  static constexpr int digits10 = fraction_limits_type::digits10;
  static constexpr int max_digits10 = fraction_limits_type::max_digits10;
  static constexpr int radix = fraction_limits_type::radix;
  static constexpr int min_exponent = fraction_limits_type::min_exponent;
  static constexpr int min_exponent10 = fraction_limits_type::min_exponent10;
  static constexpr int max_exponent = fraction_limits_type::max_exponent;
  static constexpr int max_exponent10 = fraction_limits_type::max_exponent10;
  static constexpr bool traps = fraction_limits_type::traps;
  static constexpr bool tinyness_before = fraction_limits_type::tinyness_before;

  static constexpr mixed_number_type min() noexcept;
  static constexpr mixed_number_type lowest() noexcept;
  static constexpr mixed_number_type max() noexcept;
  static constexpr mixed_number_type epsilon() noexcept;
  static constexpr mixed_number_type round_error() noexcept;
  static constexpr mixed_number_type infinity() noexcept;
  static constexpr mixed_number_type quiet_NaN() noexcept;
  static constexpr mixed_number_type signaling_NaN() noexcept;
  static constexpr mixed_number_type denorm_min() noexcept;
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
  return {_1<Rep>, std::numeric_limits<Rep>::max()};
}

template <typename Rep, typename Ops>
constexpr auto limits<fraction<Rep, Ops>>::undefined() noexcept -> fraction_type
{
  return {_0<Rep>, _0<Rep>};
}

template <typename Rep, typename Ops>
constexpr auto limits<mixed_number<Rep, Ops>>::max() noexcept
  -> mixed_number_type
{
  return limits<fraction_type>::max();
}

template <typename Rep, typename Ops>
constexpr auto limits<mixed_number<Rep, Ops>>::min() noexcept
  -> mixed_number_type
{
  return limits<fraction_type>::min();
}

template <typename Rep, typename Ops>
constexpr auto limits<mixed_number<Rep, Ops>>::smallest() noexcept
  -> mixed_number_type
{
  return limits<fraction_type>::smallest();
}

template <typename Rep, typename Ops>
constexpr auto limits<mixed_number<Rep, Ops>>::undefined() noexcept
  -> mixed_number_type
{
  return limits<fraction_type>::undefined();
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
  return rep_limits_type::round_error();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::infinity() noexcept
{
  return rep_limits_type::infinity();
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
  return rep_limits_type::signaling_NaN();
}

template <typename Rep, typename Ops>
constexpr ieme::fraction<Rep, Ops>
numeric_limits<ieme::fraction<Rep, Ops>>::denorm_min() noexcept
{
  return rep_limits_type::denorm_min();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::min() noexcept
{
  return ieme::limits<ieme::mixed_number<Rep, Ops>>::min();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::lowest() noexcept
{
  return ieme::limits<ieme::mixed_number<Rep, Ops>>::min();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::max() noexcept
{
  return ieme::limits<ieme::mixed_number<Rep, Ops>>::max();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::epsilon() noexcept
{
  return ieme::limits<ieme::mixed_number<Rep, Ops>>::smallest();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::round_error() noexcept
{
  return fraction_limits_type::round_error();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::infinity() noexcept
{
  return fraction_limits_type::infinity();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::quiet_NaN() noexcept
{
  return ieme::limits<ieme::mixed_number<Rep, Ops>>::undefined();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::signaling_NaN() noexcept
{
  return fraction_limits_type::signaling_NaN();
}

template <typename Rep, typename Ops>
constexpr ieme::mixed_number<Rep, Ops>
numeric_limits<ieme::mixed_number<Rep, Ops>>::denorm_min() noexcept
{
  return fraction_limits_type::denorm_min();
}


}; // namespace std


#endif
