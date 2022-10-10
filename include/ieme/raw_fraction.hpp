#ifndef IEME_RAW_FRACTION_HPP
#define IEME_RAW_FRACTION_HPP

#include <istream>
#include <limits>
#include <ostream>
#include <type_traits>


namespace ieme {


template <typename Rep>
struct raw_fraction {
  using rep_type = Rep;
  Rep numerator = {}, denominator = {};

  constexpr raw_fraction() noexcept = default;

  constexpr raw_fraction(Rep const& init_numerator,
                         Rep const& init_denominator) noexcept;

  template <typename OtherRep,
            typename = std::enable_if_t<std::is_convertible_v<OtherRep, Rep>>>
  constexpr raw_fraction(raw_fraction<OtherRep> const& other) noexcept;
};

template <typename Rep>
std::ostream& operator<<(std::ostream& stream,
                         raw_fraction<Rep> const& value) noexcept;

template <typename Rep>
std::istream& operator>>(std::istream& stream,
                         raw_fraction<Rep>& value) noexcept;


// =============================================================================


template <typename Rep>
constexpr raw_fraction<Rep>::raw_fraction(Rep const& init_numerator,
                                          Rep const& init_denominator) noexcept
  :
  numerator {init_numerator}, denominator {init_denominator}
{
}

template <typename Rep>
template <typename OtherRep, typename>
constexpr raw_fraction<Rep>::raw_fraction(
  raw_fraction<OtherRep> const& other) noexcept :
  raw_fraction {static_cast<Rep>(other.numerator),
                static_cast<Rep>(other.denominator)}
{
}

template <typename Rep>
std::ostream& operator<<(std::ostream& stream,
                         raw_fraction<Rep> const& value) noexcept
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


}; // namespace ieme


#endif
