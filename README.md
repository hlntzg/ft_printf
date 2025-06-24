# ft_printf
This is a custom implementation of the C standard library function printf

## Features
If you've written C code before, you're likely already familiar with `printf`. In this project, the core functionality of `printf` was reimplemented without relying on the standard library. The goal wasn’t to cover all of its features, but rather to support a subset of the most commonly used format specifiers:

- `%c` – Print a single character
- `%s` – Print a string
- `%p` – Print a pointer (in hexadecimal format)
- `%d` – Print a signed decimal integer
- `%i` – Print a signed decimal integer (alias for %d)
- `%u` – Print an unsigned decimal integer
- `%x` – Print a number in hexadecimal (lowercase)
- `%X` – Print a number in hexadecimal (uppercase)
- `%%` – Print a literal % character

## Build Instructions
To compile and use `ft_printf` in C programs:

### 1. Clone the repository:
```
git clone https://github.com/hlntzg/ft_printf.git
cd ft_printf
```

### 2. Build the library:
```
make
```
This will generate `libftprintf.a`, which you can link to your programs.

### 3. Compile with your own file:
```
gcc main.c libftprintf.a -I. -o my_printf
```

### Project structure
```
ft_printf/
├── ft_printf.c               # Main implementation of ft_printf
├── ft_printf.h               # Header file with function prototypes and includes
├── ft_printf_char.c          # Handles %c conversion (characters)
├── ft_printf_hexadecimal.c   # Handles %x and %X conversions (hexadecimal)
├── ft_printf_int.c           # Handles %d and %i conversions (signed integers)
├── ft_printf_pointer.c       # Handles %p conversion (pointers)
├── ft_printf_string.c        # Handles %s conversion (strings)
├── ft_printf_unsigned_int.c  # Handles %u conversion (unsigned integers)
├── Makefile                  # Build script for compiling the project
├── README.md                 # This documentation file
└── libft/                    # Custom libft library used as a dependency
```

### License

This project is licensed under a custom Educational Use License. It is intended 
for personal and academic use within Hive Helsinki and the 42 Network. See [LICENSE](./LICENSE) for full terms.
