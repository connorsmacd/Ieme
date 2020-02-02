#ifndef IEME_MATH_UTILITIES_HPP
#define IEME_MATH_UTILITIES_HPP

#include <type_traits>


namespace ieme {
namespace math_utilities {


template <typename Int>
constexpr Int abs(Int value) noexcept;

template <typename Int>
constexpr Int pow2(Int exponent) noexcept;


// =============================================================================


template <typename Int>
constexpr Int abs(const Int value) noexcept
{
  return (value >= 0) ? value : -value;
}

template <typename Int>
constexpr Int pow2(const Int exponent) noexcept
{
  using unsigned_type = std::make_unsigned_t<Int>;

  return Int(unsigned_type(1) << unsigned_type(exponent));
}


}; // namespace math_utilities
}; // namespace ieme


#endif
