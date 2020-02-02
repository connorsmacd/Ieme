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


}; // namespace ieme


#endif
