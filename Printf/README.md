# ft_printf

A custom implementation of the C standard library `printf` function. This project provides a function `ft_printf` that mimics the behavior of the original `printf`, supporting a subset of its format specifiers.

## Features
- Implements a custom `ft_printf` function
- Supports the following format specifiers:
  - `%c` : Character
  - `%s` : String
  - `%p` : Pointer address
  - `%d` : Signed decimal integer
  - `%i` : Signed decimal integer
  - `%u` : Unsigned decimal integer
  - `%x` : Unsigned hexadecimal integer (lowercase)
  - `%X` : Unsigned hexadecimal integer (uppercase)
  - `%%` : Literal percent sign
- Outputs to standard output
- Returns the number of characters printed, or -1 on error

## Files
- `ft_printf.c` : Main implementation of `ft_printf`
- `ft_printf.h` : Header file with function prototypes
- `print_symbol.c`, `print_string.c`, `print_pointer.c`, `print_hex.c`, `print_number.c`, `count_hex_len.c` : Helper functions for different format specifiers
- `Makefile` : Build system

## Building
To build the static library, run:

```sh
make
```

This will produce `libftprintf.a`.

To clean object files:
```sh
make clean
```

To remove all build artifacts:
```sh
make fclean
```

To rebuild from scratch:
```sh
make re
```

## Usage
Include `ft_printf.h` in your project and link against `libftprintf.a`.

Example:
```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s! Number: %d\n", "world", 42);
    return 0;
}
```

Compile and link:
```sh
cc main.c -L. -lftprintf -o main
```

## Author
- mansargs <mansargs@student.42.fr>

## License
This project is for educational purposes and does not include a specific license.
