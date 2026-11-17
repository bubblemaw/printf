*This project has been created as part of the 42 curriculum by masase.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the C standard `printf` function. The goal is to learn how **variadic functions** (`<stdarg.h>`) work and to build a clean, extensible formatting function.

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, like the original.

### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | A single character |
| `%s` | A string |
| `%p` | A pointer address in hexadecimal |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | Unsigned hexadecimal (lowercase) |
| `%X` | Unsigned hexadecimal (uppercase) |
| `%%` | A literal percent sign |

## Instructions

### Compilation

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes objects and the library
make re     # rebuilds everything
```

### Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are number %d (0x%x)\n", "world", 42, 42);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

## Structure


- `ft_printf.c`: parses the format string and dispatches each specifier
- Helper functions per conversion (chars, strings, numbers, hex, pointers)
- `Makefile`: builds `libftprintf.a`

## Resources

- `man 3 printf`, `man 3 stdarg`
