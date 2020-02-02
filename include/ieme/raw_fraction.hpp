#ifndef IEME_RAW_FRACTION_HPP
#define IEME_RAW_FRACTION_HPP

#include <istream>
#include <limits>
#include <numeric>
#include <ostream>


namespace ieme {


template <typename Rep>
struct raw_fraction {
  using rep_type = Rep;
  Rep numerator = {}, denominator = {};
};

template <typename Rep>
std::ostream& operator<<(std::ostream& stream,
                         const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
std::istream& operator>>(std::istream& stream,
                         raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep> reduce(const raw_fraction<Rep>& value) noexcept;

template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(const raw_fraction<Rep>& value) noexcept;


// =============================================================================


template <typename Rep>
std::ostream& operator<<(std::ostream& stream,
                         const raw_fraction<Rep>& value) noexcept
{
  return stream << value.numerator << '/' << value.denominator;
}

template <typename Rep>
std::istream& operator>>(std::istream& stream,
                         raw_fraction<Rep>& value) noexcept
{
  stream >> value.numerator;
  stream.ignore(std::numeric_limits<std::streamsize>::max(), '/');
  return stream >> value.denominator;
}

template <typename Rep>
constexpr raw_fraction<Rep> reduce(const raw_fraction<Rep>& value) noexcept
{
  const auto gcd = std::gcd(value.numerator, value.denominator);

  const auto gcd_with_sign
    = (value.numerator < 0 && value.denominator < 0) ? -gcd : gcd;

  return {value.numerator / gcd_with_sign, value.denominator / gcd_with_sign};
}

template <typename Rep>
constexpr raw_fraction<Rep> reciprocal(const raw_fraction<Rep>& value) noexcept
{
  return {value.denominator, value.numerator};
}


}; // namespace ieme


#endif
