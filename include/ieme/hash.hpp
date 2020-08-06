#ifndef IEME_HASH_HPP
#define IEME_HASH_HPP

#include <ieme/fraction.hpp>
#include <ieme/mixed_number.hpp>
#include <ieme/raw_fraction.hpp>

#include <functional>


namespace ieme {


template <typename Rep>
std::size_t hash(const raw_fraction<Rep>& value) noexcept;

template <typename Rep, typename Ops>
std::size_t hash(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
std::size_t hash(const mixed_number<Rep, Ops>& value) noexcept;


constexpr std::size_t hash_combine(std::size_t left,
                                   std::size_t right) noexcept;


}; // namespace ieme


namespace std {


template <typename Rep>
struct hash<ieme::raw_fraction<Rep>> {
  size_t operator()(const ieme::raw_fraction<Rep>& value) const noexcept;
};

template <typename Rep, typename Ops>
struct hash<ieme::fraction<Rep, Ops>> {
  size_t operator()(const ieme::fraction<Rep, Ops>& value) const noexcept;
};

template <typename Rep, typename Ops>
struct hash<ieme::mixed_number<Rep, Ops>> {
  size_t operator()(const ieme::mixed_number<Rep, Ops>& value) const noexcept;
};


}; // namespace std


// =============================================================================


namespace ieme {


template <typename Rep>
std::size_t hash(const raw_fraction<Rep>& value) noexcept
{
  return hash_combine(std::hash<Rep>()(value.numerator),
                      std::hash<Rep>()(value.denominator));
}

template <typename Rep, typename Ops>
std::size_t hash(const fraction<Rep, Ops>& value) noexcept
{
  return hash(value.raw());
}

template <typename Rep, typename Ops>
std::size_t hash(const mixed_number<Rep, Ops>& value) noexcept
{
  return hash_combine(std::hash<Rep>()(value.whole()),
                      hash(value.fractional()));
}

constexpr std::size_t hash_combine(const std::size_t left,
                                   const std::size_t right) noexcept
{
  return left ^ (right << 1);
}


}; // namespace ieme


namespace std {


template <typename Rep>
size_t hash<ieme::raw_fraction<Rep>>::
operator()(const ieme::raw_fraction<Rep>& value) const noexcept
{
  return ieme::hash(value);
}

template <typename Rep, typename Ops>
size_t hash<ieme::fraction<Rep, Ops>>::
operator()(const ieme::fraction<Rep, Ops>& value) const noexcept
{
  return ieme::hash(value);
}

template <typename Rep, typename Ops>
size_t hash<ieme::mixed_number<Rep, Ops>>::
operator()(const ieme::mixed_number<Rep, Ops>& value) const noexcept
{
  return ieme::hash(value);
}


}; // namespace std


#endif
