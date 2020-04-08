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

## Integration

### Headers

```c++
#include <ieme/ieme.hpp>
```

The header `ieme/ieme.hpp` contains everything the library offers.

### CMake

TODO

## Examples

TODO
