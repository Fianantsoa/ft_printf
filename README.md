*This project has been created as part of the 42 curriculum by finoment.*

## Description

This project consists of implementing a custom version of `printf` in C, named `ft_printf`.  
The goal of the project is to understand variadic functions, memory management, type promotion, and formatted output in C.  
It provides support for multiple format specifiers, such as `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

The project allows a deeper understanding of:

- How variadic functions work with `va_list`, `va_start`, `va_arg`, and `va_end`.
- How type promotion affects variadic arguments (e.g., `char` and `short` promoted to `int`, `float` to `double`).
- Converting integers and pointers to strings in decimal and hexadecimal formats.
- Handling edge cases like `NULL` pointers and integer limits.

## Instructions

### Installation
First, clone the repository:
```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-a9aecd4e-972d-4efa-b1bd-d514663de489-7240777-finoment libftprintf
cd libftprintf
```
Note: The repository link may change depending on the project or user.
In general, the command follows this format:
```bash
git clone <repository_url> <folder_name>
cd <folder_name>
```

### Compilation

To compile the library, run :

```bash
make
```
This will generate a ```libftprintf.a``` static library.

Other orders :
```bash
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Rebuild the library from scratch
```
### Usage

Include the header in your C files : 
```c
#include "libftprintf.h"
```

Compile your project with : 
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf libft/libft.a -o main
```

This command enables warnings and treats them as errors, compiles `main.c`, and links it with the `libftprintf` library in the current directory and the `libft` library located in libft/libft.a.

Example usage:

```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Hello %s, number: %d, hex: %x\n", "World", 42, 255);
    return 0;
}
```
## Resources

### Classic References 
- Linux manual pages (man printf, free, write, malloc)
- W3Schools — C programming tutorials
- cppreference.com 

### AI Usage
AI was used as a learning and guidance tool to better understand specific concepts of the project, including:

Clarifying type promotion rules in variadic functions (char and short promoted to int, float to double), so that arguments are handled correctly with va_arg.

Generating examples of test cases for all supported % format specifiers, helping to ensure edge cases and proper output formatting.

Explaining algorithms for converting pointers and integers to strings without using printf, including how to handle hexadecimal and decimal conversions manually.

Important: No AI-generated code was directly copied into the project. All implementations, testing, and final code were written manually, relying on AI only for explanations, examples, and guidance.