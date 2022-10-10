#ifndef IEME_MATH_UTILITIES_HPP
#define IEME_MATH_UTILITIES_HPP

#include <ieme/numbers.hpp>

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
  return (value >= _0<Int>) ? value : -value;
}

template <typename Int>
constexpr Int pow2(Int const exponent) noexcept
{
  using unsigned_type = std::make_unsigned_t<Int>;

  return Int(_1<unsigned_type> << unsigned_type(exponent));
}

template <typename Int>
constexpr Int pow(Int const base, Int const exponent) noexcept
{
  if (exponent == _0<Int>)
    return _1<Int>;

  if (exponent % _2<Int> == _1<Int>)
    return base * pow(base, exponent - _1<Int>);

  auto const squareRoot = pow(base, exponent / _2<Int>);

  return squareRoot * squareRoot;
}


}; // namespace math_utilities
}; // namespace ieme


#endif
