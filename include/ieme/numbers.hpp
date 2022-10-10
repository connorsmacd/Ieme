#ifndef IEME_NUMBERS_HPP
#define IEME_NUMBERS_HPP


namespace ieme {


template <auto V, typename T>
static constexpr auto number = static_cast<T>(V);

template <typename T>
static constexpr auto _0 = number<0, T>;

template <typename T>
static constexpr auto _1 = number<1, T>;

template <typename T>
static constexpr auto _2 = number<2, T>;

template <typename T>
static constexpr auto _10 = number<10, T>;
} // namespace ieme


#endif
