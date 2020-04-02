#ifndef IEME_PARSE_UTILITIES_HPP
#define IEME_PARSE_UTILITIES_HPP

#include <string_view>
#include <utility>


namespace ieme {
namespace parse_utilities {


struct floating_point_string_scan_results {
  bool is_valid = false;
  unsigned int base = 10;
  std::string_view whole;
  std::string_view fractional;
  unsigned int fractional_precision = 0;
  char exponent_sign = '+';
  std::string_view exponent;
};

constexpr floating_point_string_scan_results
scan_floating_point_string(std::string_view string) noexcept;

constexpr bool is_valid_digit_sequence(std::string_view sequence,
                                       unsigned int base) noexcept;


// =============================================================================


constexpr floating_point_string_scan_results
scan_floating_point_string(const std::string_view string) noexcept
{
  if (string.size() < 2)
    return {};

  auto remaining_string = string;

  const auto last_pos = [&]() { return remaining_string.size() - 1; };

  floating_point_string_scan_results results;
  results.is_valid = true;

  if (remaining_string.size() > 2)
  {
    const auto first_two = remaining_string.substr(0, 2);

    if (first_two == "0x" || first_two == "0X")
    {
      remaining_string.remove_prefix(2);
      results.base = 16;
    }
  }

  const auto radix_separator_pos = remaining_string.find('.');

  results.whole = remaining_string.substr(0, radix_separator_pos);

  const auto no_whole = results.whole.empty();

  if (!(no_whole || is_valid_digit_sequence(results.whole, results.base)))
    return {};

  if (radix_separator_pos == last_pos())
  {
    if (results.base == 10)
      return results;

    return {};
  }

  const auto no_radix_separator = radix_separator_pos == std::string_view::npos;

  if (!no_radix_separator)
    remaining_string.remove_prefix(radix_separator_pos + 1);

  const auto exponent_separator_pos = [&]() {
    const auto [lower, upper] = (results.base == 10) ? std::make_pair('e', 'E')
                                                     : std::make_pair('p', 'P');

    if (const auto lower_pos = remaining_string.find(lower);
        lower_pos != std::string_view::npos)
      return lower_pos;

    return remaining_string.find(upper);
  }();

  if (exponent_separator_pos == last_pos())
    return {};

  const auto no_exponent_separator
    = exponent_separator_pos == std::string_view::npos;

  if (no_radix_separator && no_exponent_separator)
    return {};

  if (results.base == 16 && no_exponent_separator)
    return {};

  results.fractional = remaining_string.substr(0, exponent_separator_pos);

  const auto no_fractional = results.fractional.empty();

  if (no_whole && no_fractional)
    return {};

  if (!(no_fractional
        || is_valid_digit_sequence(results.fractional, results.base)))
    return {};

  results.fractional_precision = [&]() {
    auto result = 0U;

    for (const auto digit : results.fractional)
      if (digit != '\'')
        ++result;

    return result;
  }();

  if (no_exponent_separator)
    return results;

  remaining_string.remove_prefix(exponent_separator_pos + 1);

  if (remaining_string.front() == '-' || remaining_string.front() == '+')
  {
    results.exponent_sign = remaining_string.front();
    remaining_string.remove_prefix(1);
  }

  results.exponent = remaining_string;

  if (!is_valid_digit_sequence(results.exponent, 10))
    return {};

  return results;
}

constexpr bool is_valid_digit_sequence(const std::string_view sequence,
                                       const unsigned int base) noexcept
{
  auto digit_preceeded = false;

  for (const auto c : sequence)
  {
    if (c == '\'')
    {
      if (!digit_preceeded)
        return false;

      digit_preceeded = false;
    }
    else
    {
      if ((c < '0' || c > '9')
          && (((c < 'a' || c > 'f') && (c < 'A' || c > 'F')) || base != 16))
        return false;

      digit_preceeded = true;
    }
  }

  return digit_preceeded;
}


}; // namespace parse_utilities
}; // namespace ieme


#endif
