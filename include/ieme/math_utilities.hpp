#ifndef IEME_MATH_UTILITIES_HPP
#define IEME_MATH_UTILITIES_HPP

#include <type_traits>


namespace ieme {
namespace math_utilities {


template <typename Int>
constexpr Int abs(Int value) noexcept;

template <typename Int>
constexpr Int pow2(Int exponent) noexcept;

template <typename Int>
constexpr Int pow(Int base, Int exponent) noexcept;


// =============================================================================


template <typename Int>
constexpr Int abs(Int const value) noexcept
{
  return (value >= Int(0)) ? value : -value;
}

template <typename Int>
constexpr Int pow2(Int const exponent) noexcept
{
  using unsigned_type = std::make_unsigned_t<Int>;

  return Int(unsigned_type(1) << unsigned_type(exponent));
}

template <typename Int>
constexpr Int pow(Int const base, Int const exponent) noexcept
{
  if (exponent == Int(0))
    return Int(1);

  if (exponent % Int(2) == Int(1))
    return base * pow(base, exponent - Int(1));

  auto const squareRoot = pow(base, exponent / Int(2));

  return squareRoot * squareRoot;
}


}; // namespace math_utilities
}; // namespace ieme


#endif
