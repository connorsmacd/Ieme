# Ieme

```c++
ieme::fraction<int> f {1, 2}; // f = 1/2
f = 3/4_Fr;                   // f = 3/4
f = 1/2_Fr + 3/4_Fr;          // f = 5/4
f = 1/2_Fr - 4/5_Fr;          // f = -3/10
f = 3/4_Fr * 3/7_Fr;          // f = 9/28
f = 8;                        // f = 8/1
f = 0.759_Dec;                // f = 759/1000
f = reciprocal(3/4_Fr);       // f = 4/3
f = reduce(16/24_Fr);         // f = 2/3
int i = round(19/10_Fr);      // i = 2
```

Ieme is a fast and simple C++ fractional arithmetic library intended for use in almost any environment.

## Features

* Intuitive syntax for storing and manipulating fractions
* Lightweight and portable implementation to support constrained environments such as embedded systems
* Arithmetic operations that can be tuned for performance, safety, ease-of-use, or debugging
* Header only

## Integration

### Requirements

Ieme must be built with a compiler that supports C++17

### Includes

```c++
#include <ieme/ieme.hpp>
```

The header `ieme/ieme.hpp` contains everything you need. There are individual headers for various modules, but these are not yet documented.

### CMake

Ieme is represented in CMake as an interface target.

If you've installed Ieme, include this line in your CMakeLists.txt:

```cmake
find_package(Ieme CONFIG REQUIRED)
```

If you're using Ieme as a subproject, add this line to your CMakeLists.txt, where "IemeSubdirectory" is the directory in your tree where Ieme is located:

```cmake
add_subdirectory(IemeSubdirectory)
```

To link to the target, do something like this:

```cmake
target_link_libraries(YourTarget Ieme::Ieme)
```

## Basic Usage

### Constructing Fractions

```c++
using namespace ieme;

auto a = fraction<int>();           // 0/1
auto b = fraction<int>(3, 4);       // 3/4
auto c = fraction<int>(-2);         // -2/1
auto d = fraction<int>(std::milli); // 1/1000

using namespace ieme::literals;

auto e = -2 / 7_Fr; // -2/7 (fraction<int>)
auto f = 7U / 9_Fr; // 7/9 (fraction<unsigned int>)
auto g = 2.37_Dec;  // 237/100 (fraction<std::intmax_t>)
```

### Math

#### Arithmetic

```c++
1/2_Fr + 3/4_Fr;   // 5/4
1/2_Fr - 4/5_Fr;   // -3/10
3/4_Fr * 3/7_Fr;   // 9/28

// For divide and modulo, the divisor must be wrapped in parentheses.
// Without parentheses, the operation 3/4_Fr / 3/2_Fr evalutes to ((3/4)/3)/2
// instead of (3/4)/(3/2)

3/4_Fr / (3/2_Fr); // 1/2
4/7_Fr % (2/5_Fr); // 6/35
```

#### Comparisons

```c++
// Fractions are compared based on value rather than on representation, e.g.,
// 1/2 and 2/4 are considered to be equal.
// To check if two fractions have the exact same representations, see
// "are_identical" and "are_different" in queries

1/2_Fr == 2/4_Fr; // true
1/2_Fr != 2/4_Fr; // false
1/2_Fr > 1/4_Fr;  // true
1/2_Fr >= 1/3_Fr; // true
1/2_Fr < 3/4_Fr;  // true
1/2_Fr <= 2/3_Fr; // true
```

#### Common Operations

```c++
reciprocal(3/4_Fr); // 4/3

reduce(16/24_Fr); // 2/3

round(19/10_Fr); // 2
trunc(19/10_Fr); // 1
floor(19/10_Fr); // 1
ceil(19/10_Fr);  // 2

abs(-4/5_Fr); // 4/5

pow2(-3); // 1/8

pow(3, -2); // 1/9
```

### Queries

```c++
is_undefined(2/0_Fr); // true

is_positive(3/4_Fr);  // true
is_zero(0/4_Fr);      // true
is_negative(-3/4_Fr); // true

is_integer(2/1_Fr);       // true
is_unit_fraction(1/3_Fr); // true

is_reduced(5/10_Fr); // false

is_proper(1/4_Fr);   // true
is_improper(5/4_Fr); // true

are_identical(1/2_Fr, 1/2_Fr);   // true
are_different(1/2_Fr, -1/-2_Fr); // true
```

### Mixed Numbers

```c++
// TODO
```

### Floating Point Conversions

```c++
// TODO
```
