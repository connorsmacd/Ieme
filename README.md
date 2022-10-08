# Ieme

```c++
ieme::fraction<int> f {1, 2}; // f = 1/2
f = 3/4_fr;                   // f = 3/4
f = 1/2_fr + 3/4_fr;          // f = 5/4
f = 1/2_fr - 4/5_fr;          // f = -3/10
f = 3/4_fr * 3/7_fr;          // f = 9/28
f = 8;                        // f = 8/1
f = 0.759_dec;                // f = 759/1000
f = reciprocal(3/4_fr);       // f = 4/3
f = reduce(16/24_fr);         // f = 2/3
int i = round(19/10_fr);      // i = 2
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

The header `ieme/ieme.hpp` contains everything you need.

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

auto f1 = fraction<int>();           // 0/1
auto f2 = fraction<int>(3, 4);       // 3/4
auto f3 = fraction<int>(-2);         // -2/1
auto f4 = fraction<int>(std::milli); // 1/1000

using namespace ieme::fraction_literals;

auto f5 = -2/7_fr; // -2/7 (fraction<int>)
auto f6 = 7U/9_fr; // 7/9 (fraction<unsigned int>)
auto f7 = 2.37_dec;  // 237/100 (fraction<std::intmax_t>)
```

### Math

#### Arithmetic

```c++
auto f1 = 1/2_fr + 3/4_fr;   // 5/4
auto f2 = 1/2_fr - 4/5_fr;   // -3/10
auto f3 = 3/4_fr * 3/7_fr;   // 9/28

auto f4 = 3/4_fr / (3/2_fr); // 1/2
auto f5 = 4/7_fr % (2/5_fr); // 6/35
```

#### Comparisons

```c++
auto b1 = 1/2_fr == 2/4_fr; // true
auto b2 = 1/2_fr != 2/4_fr; // false
auto b3 = 1/2_fr > 1/4_fr;  // true
auto b4 = 1/2_fr >= 1/3_fr; // true
auto b5 = 1/2_fr < 3/4_fr;  // true
auto b6 = 1/2_fr <= 2/3_fr; // true
```

#### Common Operations

```c++
auto f1 = reciprocal(3/4_fr); // 4/3

auto f2 = reduce(16/24_fr); // 2/3

auto i1 = round(19/10_fr); // 2
auto i2 = trunc(19/10_fr); // 1
auto i3 = floor(19/10_fr); // 1
auto i4 = ceil(19/10_fr);  // 2

auto f3 = abs(-4/5_fr); // 4/5

auto f4 = pow2(-3); // 1/8

auto f5 = pow(3, -2); // 1/9
```

### Queries

```c++
auto b1 = is_undefined(2/0_fr); // true

auto b2 = is_positive(3/4_fr);  // true
auto b3 = is_zero(0/4_fr);      // true
auto b4 = is_negative(-3/4_fr); // true

auto b5 = is_integer(2/1_fr);       // true
auto b6 = is_unit_fraction(1/3_fr); // true

auto b7 = is_reduced(5/10_fr); // false

auto b8 = is_proper(1/4_fr);   // true
auto b9 = is_improper(5/4_fr); // true

auto b10 = are_identical(1/2_fr, 1/2_fr);   // true
auto b11 = are_different(1/2_fr, -1/-2_fr); // true
```

### Floating Point Conversions

```c++
auto f1 = to_fraction<int>(0.375f); // 3/8
auto f2 = to_fraction<int>(-2.25); // -9/4

auto fl1 = to_float(1/4_fr); // 0.25f
auto d1 = to_double(5/8_fr); // 0.625
auto l1 = to_long_double(-1/16_fr); // 0.0625L
```
