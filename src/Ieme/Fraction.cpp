#include <Ieme/Fraction.hpp>

#include <limits>


namespace Ieme {


std::ostream& operator<<(std::ostream& stream, const Fraction& fraction) noexcept
{
    stream << fraction.numerator_ << '/' << fraction.denominator_;

    return stream;
}

std::istream& operator>>(std::istream& stream, Fraction& fraction) noexcept
{
    stream >> fraction.numerator_;
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    stream >> fraction.denominator_;

    return stream;
}


}; // namespace Ieme
