#pragma once

#include <ieme/ops.hpp>
#include <ieme/raw_fraction.hpp>

#include <istream>
#include <limits>
#include <ostream>
#include <ratio>
#include <type_traits>
#include <utility>


namespace ieme {


template <typename Rep, typename Ops = ops::strict>
class fraction final {

public:
    using raw_fraction_type = raw_fraction<Rep>;
    using rep_type = typename raw_fraction_type::rep_type;
    using ops_type = Ops;

    constexpr fraction() = default;

    constexpr fraction(const raw_fraction_type& raw) noexcept;

    constexpr fraction(const Rep& numerator,
                       const Rep& denominator = 1) noexcept;

    template <typename OtherRep, typename OtherOps>
    constexpr fraction(const fraction<OtherRep, OtherOps>& other) noexcept;

    template <std::intmax_t Numerator, std::intmax_t Denominator>
    constexpr fraction(
        const std::ratio<Numerator, Denominator>& ratio) noexcept;

    constexpr const Rep& numerator() const noexcept;

    constexpr const Rep& denominator() const noexcept;

    constexpr const raw_fraction_type& raw() const noexcept { return raw_; }

private:
    raw_fraction_type raw_ = {0, 1};
};

template <typename Rep, typename Ops>
std::ostream& operator<<(std::ostream& stream,
                         const fraction<Rep, Ops>& value) noexcept;

template <typename Rep, typename Ops>
std::istream& operator>>(std::istream& stream,
                         fraction<Rep, Ops>& value) noexcept;

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

template <typename Rep, typename Ops = ops::strict>
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


// =================================================================================================


template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>::fraction(const raw_fraction_type& raw) noexcept :
    raw_ {raw}
{
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops>::fraction(const Rep& numerator,
                                       const Rep& denominator) noexcept :
    raw_ {numerator, denominator}
{
}

template <typename Rep, typename Ops>
template <typename OtherRep, typename OtherOps>
constexpr fraction<Rep, Ops>::fraction(
    const fraction<OtherRep, OtherOps>& other) noexcept :
    raw_ {Rep(numerator), Rep(denominator)}
{
}

template <typename Rep, typename Ops>
template <std::intmax_t Numerator, std::intmax_t Denominator>
constexpr fraction<Rep, Ops>::fraction(
    const std::ratio<Numerator, Denominator>&) noexcept :
    raw_ {std::ratio<Numerator, Denominator>::num,
          std::ratio<Numerator, Denominator>::den}
{
}

template <typename Rep, typename Ops>
constexpr const Rep& fraction<Rep, Ops>::numerator() const noexcept
{
    return raw_.numerator;
}

template <typename Rep, typename Ops>
constexpr const Rep& fraction<Rep, Ops>::denominator() const noexcept
{
    return raw_.denominator;
}

template <typename Rep, typename Ops>
std::ostream& operator<<(std::ostream& stream,
                         const fraction<Rep, Ops>& value) noexcept
{
    return stream << value.numerator() << '/' << value.denominator();
}

template <typename Rep, typename Ops>
std::istream& operator>>(std::istream& stream,
                         fraction<Rep, Ops>& value) noexcept
{
    typename fraction<Rep, Ops>::raw_fraction_type new_raw;

    stream >> new_raw.numerator;
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    stream >> new_raw.denominator;

    value = new_raw;

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
    return Ops::negate(value.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator+(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::plus(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator-(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::minus(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator*(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::multiplies(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator/(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::divides(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> operator%(const fraction<Rep, Ops>& left,
                                       const fraction<Rep, Ops>& right) noexcept
{
    return Ops::modulus(left.raw(), right.raw());
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
    return Ops::equal_to(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr bool operator!=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return Ops::not_equal_to(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr bool operator<(const fraction<Rep, Ops>& left,
                         const fraction<Rep, Ops>& right) noexcept
{
    return Ops::less(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr bool operator<=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return Ops::less_equal(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr bool operator>(const fraction<Rep, Ops>& left,
                         const fraction<Rep, Ops>& right) noexcept
{
    return Ops::greater(left.raw(), right.raw());
}

template <typename Rep, typename Ops>
constexpr bool operator>=(const fraction<Rep, Ops>& left,
                          const fraction<Rep, Ops>& right) noexcept
{
    return Ops::greater_equal(left.raw(), right.raw());
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
