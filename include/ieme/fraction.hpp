#pragma once

#include <istream>
#include <limits>
#include <numeric>
#include <ostream>
#include <ratio>
#include <type_traits>
#include <utility>


namespace ieme {


class safe_ops;


template <typename Rep, typename Ops = safe_ops>
class fraction final {

public:
    using rep_type = Rep;
    using ops_type = Ops;

    constexpr fraction() = default;

    constexpr fraction(const Rep& numerator,
                       const Rep& denominator = 1) noexcept;

    template <typename OtherRep, typename OtherOps>
    constexpr fraction(const fraction<OtherRep, OtherOps>& other) noexcept;

    template <std::intmax_t Numerator, std::intmax_t Denominator>
    constexpr fraction(
        const std::ratio<Numerator, Denominator>& ratio) noexcept;

    constexpr const Rep& numerator() const noexcept { return numerator_; }

    constexpr Rep& numerator() noexcept { return numerator_; }

    constexpr const Rep& denominator() const noexcept { return denominator_; }

    constexpr Rep& denominator() noexcept { return denominator_; }

private:
    Rep numerator_ = 0;
    Rep denominator_ = 1;
};

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator+(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator-(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator+(const fraction<Rep, Ops>& left,
          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator-(const fraction<Rep, Ops>& left,
          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator*(const fraction<Rep, Ops>& left,
          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const fraction<Rep, Ops>& left,
          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator%(const fraction<Rep, Ops>& left,
          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator+(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator-(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator*(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator/(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator%(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator+(const Rep& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator-(const Rep& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator*(const Rep& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator/(const Rep& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
operator%(const Rep& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator+=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator-=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator*=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator/=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator%=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator+=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator-=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator*=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator/=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator%=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator==(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator!=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator<(const fraction<Rep, Ops>& left,
                         const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator<=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator>(const fraction<Rep, Ops>& left,
                         const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator>=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator==(const fraction<Rep, Ops>& left,
                          const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator!=(const fraction<Rep, Ops>& left,
                          const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator<(const fraction<Rep, Ops>& left,
                         const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator<=(const fraction<Rep, Ops>& left,
                          const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator>(const fraction<Rep, Ops>& left,
                         const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator>=(const fraction<Rep, Ops>& left,
                          const Rep& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator==(const Rep& left,
                          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator!=(const Rep& left,
                          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator<(const Rep& left,
                         const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator<=(const Rep& left,
                          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator>(const Rep& left,
                         const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool operator>=(const Rep& left,
                          const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool symbolically_equal(const fraction<Rep, Ops>& left,
                                  const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr bool not_symbolically_equal(const fraction<Rep, Ops>& left,
                                      const fraction<Rep, Ops>& right) noexcept;

template <typename Rep, typename Ops>
constexpr Rep numerator(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep denominator(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> reduce(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reciprocal(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr long double to_decimal(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops = safe_ops>
constexpr fraction<Rep, Ops> pow2(const Rep& exponent) noexcept;

template <typename Rep, typename Ops>
constexpr Rep ceil(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep floor(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep trunc(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr Rep round(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> abs(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_positive(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_negative(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_zero(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_integer(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_unit_fraction(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_defined(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
constexpr bool is_undefined(const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
std::ostream& operator<<(std::ostream& stream,
                         const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
std::istream& operator>>(std::istream& stream,
                         fraction<Rep, Ops>& value) noexcept;


// =================================================================================================


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>::fraction(const Rep& numerator,
                                       const Rep& denominator) noexcept :
    numerator_ {numerator},
    denominator_ {denominator}
{
}

template <typename Rep, typename Ops>
template <typename OtherRep, typename OtherOps>
constexpr fraction<Rep, Ops>::fraction(
    const fraction<OtherRep, OtherOps>& other) noexcept :
    numerator_ {Rep(other.numerator_)},
    denominator_ {Rep(other.denominator_)}
{
}

template <typename Rep, typename Ops>
template <std::intmax_t Numerator, std::intmax_t Denominator>
constexpr fraction<Rep, Ops>::fraction(
    const std::ratio<Numerator, Denominator>&) noexcept :
    numerator_ {std::ratio<Numerator, Denominator>::num},
    denominator_ {std::ratio<Numerator, Denominator>::den}
{
}

template <typename Rep, typename Ops>
std::ostream& operator<<(std::ostream& stream,
                         const fraction<Rep, Ops>& value) noexcept
{
    stream << value.numerator() << '/' << value.denominator();

    return stream;
}

template <typename Rep, typename Ops>
std::istream& operator>>(std::istream& stream,
                         fraction<Rep, Ops>& value) noexcept
{
    stream >> value.numerator();
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    stream >> value.denominator();

    return stream;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator+(const fraction<Rep, Ops>& value) noexcept
{
    return value;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator-(const fraction<Rep, Ops>& value) noexcept
{
    return {-value.numerator(), value.denominator()};
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator+(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::add(left, right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator-(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::subtract(left, right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator*(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::multiply(left, right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator/(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::divide(left, right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator%(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::remainder(left, right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator+(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept
{
    return left + fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator-(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept
{
    return left - fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator*(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept
{
    return left * fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator/(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept
{
    return left / fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator%(const fraction<Rep, Ops>& left,
                                       const Rep& right) noexcept
{
    return left % fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator+(const Rep& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) + right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator-(const Rep& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) - right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator*(const Rep& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) * right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator/(const Rep& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) / right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator%(const Rep& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) % right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator+=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept
{
    return left = left + right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator-=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept
{
    return left = left - right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator*=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept
{
    return left = left * right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator/=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept
{
    return left = left / right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>&
operator%=(fraction<Rep, Ops>& left, const fraction<Rep, Ops>& right) noexcept
{
    return left = left % right;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator+=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept
{
    return left += fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator-=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept
{
    return left -= fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator*=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept
{
    return left *= fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator/=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept
{
    return left /= fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>& operator%=(fraction<Rep, Ops>& left,
                                         const Rep& right) noexcept
{
    return left %= fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr bool operator==(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return Ops::equal_to(left, right);
}

template <typename Rep, typename Ops>
constexpr bool operator!=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return Ops::not_equal_to(left, right);
}

template <typename Rep, typename Ops>
constexpr bool operator<(const fraction<Rep, Ops>& left,
                         const fraction<Rep, Ops>& right) noexcept
{
    return Ops::less_than(left, right);
}

template <typename Rep, typename Ops>
constexpr bool operator<=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return Ops::less_than_or_equal_to(left, right);
}

template <typename Rep, typename Ops>
constexpr bool operator>(const fraction<Rep, Ops>& left,
                         const fraction<Rep, Ops>& right) noexcept
{
    return Ops::greater_than(left, right);
}

template <typename Rep, typename Ops>
constexpr bool operator>=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return Ops::greater_than_or_equal_to(left, right);
}

template <typename Rep, typename Ops>
constexpr bool operator==(const fraction<Rep, Ops>& left,
                          const Rep& right) noexcept
{
    return left == fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr bool operator!=(const fraction<Rep, Ops>& left,
                          const Rep& right) noexcept
{
    return left != fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr bool operator<(const fraction<Rep, Ops>& left,
                         const Rep& right) noexcept
{
    return left < fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr bool operator<=(const fraction<Rep, Ops>& left,
                          const Rep& right) noexcept
{
    return left <= fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr bool operator>(const fraction<Rep, Ops>& left,
                         const Rep& right) noexcept
{
    return left > fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr bool operator>=(const fraction<Rep, Ops>& left,
                          const Rep& right) noexcept
{
    return left >= fraction<Rep, Ops>(right);
}

template <typename Rep, typename Ops>
constexpr bool operator==(const Rep& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) == right;
}

template <typename Rep, typename Ops>
constexpr bool operator!=(const Rep& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) != right;
}

template <typename Rep, typename Ops>
constexpr bool operator<(const Rep& left,
                         const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) < right;
}

template <typename Rep, typename Ops>
constexpr bool operator<=(const Rep& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) <= right;
}

template <typename Rep, typename Ops>
constexpr bool operator>(const Rep& left,
                         const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) > right;
}

template <typename Rep, typename Ops>
constexpr bool operator>=(const Rep& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return fraction<Rep, Ops>(left) >= right;
}

template <typename Rep, typename Ops>
constexpr bool symbolically_equal(const fraction<Rep, Ops>& left,
                                  const fraction<Rep, Ops>& right) noexcept
{
    return left.numerator() == right.numerator()
           && left.denominator() == right.denominator();
}

template <typename Rep, typename Ops>
constexpr bool not_symbolically_equal(const fraction<Rep, Ops>& left,
                                      const fraction<Rep, Ops>& right) noexcept
{
    return !symbolically_equal(left, right);
}

template <typename Rep, typename Ops>
constexpr Rep numerator(const fraction<Rep, Ops>& value) noexcept
{
    return value.numerator();
}

template <typename Rep, typename Ops>
constexpr Rep denominator(const fraction<Rep, Ops>& value) noexcept
{
    return value.denominator();
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> reduce(const fraction<Rep, Ops>& value) noexcept
{
    const auto gcd = std::gcd(value.numerator(), value.denominator());

    const auto gcd_with_sign
        = (value.numerator() < 0 && value.denominator() < 0) ? -gcd : gcd;

    return fraction<Rep, Ops>(value.numerator() / gcd_with_sign,
                              value.denominator() / gcd_with_sign);
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>
reciprocal(const fraction<Rep, Ops>& value) noexcept
{
    return {value.denominator(), value.numerator()};
}

template <typename Rep, typename Ops>
constexpr long double to_decimal(const fraction<Rep, Ops>& value) noexcept
{
    return static_cast<long double>(value.numerator())
           / static_cast<long double>(value.denominator());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> pow2(const Rep& exponent) noexcept
{
    const auto constexpr_pow2 = [=](const Rep& exponent) {
        using unsigned_type = std::make_unsigned_t<Rep>;
        return Rep(unsigned_type(1) << unsigned_type(exponent));
    };

    return (exponent >= 0) ? fraction<Rep, Ops>(constexpr_pow2(exponent))
                           : fraction<Rep, Ops>(1, constexpr_pow2(-exponent));
}

template <typename Rep, typename Ops>
constexpr Rep ceil(const fraction<Rep, Ops>& value) noexcept
{
    const auto truncated = trunc(value);

    return (is_integer(value) || truncated < 0) ? truncated : truncated + 1;
}

template <typename Rep, typename Ops>
constexpr Rep floor(const fraction<Rep, Ops>& value) noexcept
{
    const auto truncated = trunc(value);

    return (is_integer(value) || truncated >= 0) ? truncated : truncated - 1;
}

template <typename Rep, typename Ops>
constexpr Rep trunc(const fraction<Rep, Ops>& value) noexcept
{
    return value.numerator() / value.denominator();
}

template <typename Rep, typename Ops>
constexpr Rep round(const fraction<Rep, Ops>& value) noexcept
{
    const auto floored = floor(value);

    return (value - floored < fraction<Rep, Ops>(1, 2)) ? floored : floored + 1;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> abs(const fraction<Rep, Ops>& value) noexcept
{
    return is_positive(value) ? value : -value;
}

template <typename Rep, typename Ops>
constexpr bool is_positive(const fraction<Rep, Ops>& value) noexcept
{
    return (value.numerator() > 0 && value.denominator() > 0)
           || (value.numerator() < 0 && value.denominator() < 0);
}

template <typename Rep, typename Ops>
constexpr bool is_negative(const fraction<Rep, Ops>& value) noexcept
{
    return (value.numerator() > 0 && value.denominator() < 0)
           || (value.numerator() < 0 && value.denominator() > 0);
}

template <typename Rep, typename Ops>
constexpr bool is_zero(const fraction<Rep, Ops>& value) noexcept
{
    return is_defined(value) && value.numerator() == 0;
}

template <typename Rep, typename Ops>
constexpr bool is_integer(const fraction<Rep, Ops>& value) noexcept
{
    return is_defined(value) && value.numerator() % value.denominator() == 0;
}

template <typename Rep, typename Ops>
constexpr bool is_unit_fraction(const fraction<Rep, Ops>& value) noexcept
{
    return is_integer(reciprocal(value));
}

template <typename Rep, typename Ops>
constexpr bool is_defined(const fraction<Rep, Ops>& value) noexcept
{
    return value.denominator() != 0;
}

template <typename Rep, typename Ops>
constexpr bool is_undefined(const fraction<Rep, Ops>& value) noexcept
{
    return !is_defined(value);
}


}; // namespace ieme


#include <ieme/safe_ops.hpp>
