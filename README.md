# _printf Project

## Overview

This project is an implementation of the C standard library function `printf`. The goal is to create a custom function that produces formatted output according to a format string and additional arguments.

## Project Requirements

- Allowed editors: vi, vim, emacs
- All files compiled on Ubuntu 20.04 LTS using gcc with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files end with a newline
- Code follows Betty style guide
- No global variables allowed
- Maximum 5 functions per file
- All function prototypes included in `main.h`
- Header file includes guards

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c -o printf
```

## Files Included

- **main.h**: Header file with function prototypes
- **_printf.c**: Main implementation of the _printf function
- **main.c**: Test file (for local testing only)
- **README.md**: This file
- **man_3_printf**: Manual page for the _printf function

## Implemented Features

### Task 1: Basic Format Specifiers
- `c`: Print a character
- `s`: Print a string
- `%`: Print a percent sign

### Task 2: Integer Format Specifiers
- `d`: Print an integer in decimal
- `i`: Print an integer in decimal

### Task 3: Additional Features
- `u`: Print unsigned integers

## Function Descriptions

### _printf
```c
int _printf(const char *format, ...);
```
Produces output according to a format string. Returns the number of characters printed (excluding the null byte).

**Parameters:**
- `format`: Character string composed of conversion specifiers and regular characters

**Return value:**
- Number of characters printed on success
- -1 if format is NULL

### _putchar
```c
int _putchar(char c);
```
Writes a character to stdout. Helper function for output.

### print_string
```c
int print_string(char *str);
```
Prints a string to stdout, handling NULL pointers by printing "(null)".

### print_integer
```c
int print_integer(int n);
```
Prints a signed integer to stdout, handling negative numbers.

### print_unsigned
```c
int print_unsigned(unsigned int n);
```
Prints an unsigned integer to stdout.

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

## Testing

Run the provided test file:
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format main.c _printf.c -o printf
./printf
```

## Authors

Holberton School Printf Project Group

## Notes

- This implementation does not handle buffer management like the standard printf
- No flag characters, field width, precision, or length modifiers are supported
- For edge cases not specified, the behavior matches standard printf
