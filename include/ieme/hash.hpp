#ifndef IEME_HASH_HPP
#define IEME_HASH_HPP

#include <ieme/fraction.hpp>
#include <ieme/mixed_number.hpp>
#include <ieme/raw_fraction.hpp>

#include <functional>


namespace ieme {


template <typename Rep>
std::size_t hash(raw_fraction<Rep> const& value) noexcept;

template <typename Rep, typename Ops>
std::size_t hash(fraction<Rep, Ops> const& value) noexcept;

template <typename Rep, typename Ops>
std::size_t hash(mixed_number<Rep, Ops> const& value) noexcept;


constexpr std::size_t hash_combine(std::size_t left,
                                   std::size_t right) noexcept;


}; // namespace ieme


namespace std {


template <typename Rep>
struct hash<ieme::raw_fraction<Rep>> {
  size_t operator()(ieme::raw_fraction<Rep> const& value) const noexcept;
};

template <typename Rep, typename Ops>
struct hash<ieme::fraction<Rep, Ops>> {
  size_t operator()(ieme::fraction<Rep, Ops> const& value) const noexcept;
};

template <typename Rep, typename Ops>
struct hash<ieme::mixed_number<Rep, Ops>> {
  size_t operator()(ieme::mixed_number<Rep, Ops> const& value) const noexcept;
};


}; // namespace std


// =============================================================================


namespace ieme {


template <typename Rep>
std::size_t hash(raw_fraction<Rep> const& value) noexcept
{
  return hash_combine(std::hash<Rep>()(value.numerator),
                      std::hash<Rep>()(value.denominator));
}

template <typename Rep, typename Ops>
std::size_t hash(fraction<Rep, Ops> const& value) noexcept
{
  return hash(value.raw());
}

template <typename Rep, typename Ops>
std::size_t hash(mixed_number<Rep, Ops> const& value) noexcept
{
  return hash_combine(std::hash<Rep>()(value.whole()),
                      hash(value.fractional()));
}

constexpr std::size_t hash_combine(std::size_t const left,
                                   std::size_t const right) noexcept
{
  return left ^ (right << 1);
}


}; // namespace ieme


namespace std {


template <typename Rep>
size_t hash<ieme::raw_fraction<Rep>>::
operator()(ieme::raw_fraction<Rep> const& value) const noexcept
{
  return ieme::hash(value);
}

template <typename Rep, typename Ops>
size_t hash<ieme::fraction<Rep, Ops>>::
operator()(ieme::fraction<Rep, Ops> const& value) const noexcept
{
  return ieme::hash(value);
}

template <typename Rep, typename Ops>
size_t hash<ieme::mixed_number<Rep, Ops>>::
operator()(ieme::mixed_number<Rep, Ops> const& value) const noexcept
{
  return ieme::hash(value);
}


}; // namespace std


#endif
