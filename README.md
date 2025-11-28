# _printf Project

This is a Holberton School project implementing a custom version of the C standard library `printf` function.

## Description

The `_printf` function produces output according to a format string, similar to the standard `printf` function. It writes the output to stdout and returns the number of characters printed.

## Requirements

- Allowed editors: vi, vim, emacs
- All files compiled on Ubuntu 20.04 LTS using gcc with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files end with a newline
- Code follows Betty style guide
- No global variables allowed
- Maximum 5 functions per file
- All function prototypes in `main.h`
- Header file includes guards

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf
```

## Files

- `main.h` - Header file with function prototypes and include guards
- `_printf.c` - Main implementation file containing the `_printf` function and helper functions
- `man_3_printf` - Manual page for the `_printf` function
- `README.md` - This file

## Implemented Features

### Task 1: Basic Format Specifiers
- `%c` - Print a character
- `%s` - Print a string
- `%%` - Print a percent sign

### Task 2: Integer Format Specifiers
- `%d` - Print an integer in decimal
- `%i` - Print an integer in decimal

### Task 3: Manual Page
- Created man page documentation (`man_3_printf`)

## Function Prototype

```c
int _printf(const char *format, ...);
```

### Return Value
- Number of characters printed (excluding the null byte) on success
- -1 if format is NULL

## Usage Example

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Number: %d\n", 42);
    _printf("Character: %c\n", 'A');
    _printf("Percent: %%\n");
    return (0);
}
```

## Notes

- This implementation does not handle buffer management like the standard printf
- Flag characters, field width, precision, and length modifiers are not supported
- For unrecognized conversion specifiers, a percent sign followed by the character is printed
- A trailing percent sign at the end of the format string is ignored

## Authors

Holberton School printf implementation group

