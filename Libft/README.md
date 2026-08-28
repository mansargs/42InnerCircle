# Libft

Libft is a custom implementation of standard C library functions, developed as part of the 42 school curriculum. The goal of this project is to deepen understanding of C programming by recreating essential functions for memory management, string manipulation, linked lists, and more.

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Compiling](#compiling)
- [Bonus Functions](#bonus-functions)
- [Author](#author)

## Features

Libft includes re-implementations of many standard C library functions, such as:

- Memory functions: `memset`, `memcpy`, `memmove`, `calloc`, etc.
- String functions: `strlen`, `strchr`, `strdup`, `strlcpy`, `strlcat`, etc.
- Character checks: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, etc.
- Linked list utilities (bonus): `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`, etc.

## Project Structure

```
Libft/
  ├── ft_*.c           # Source files for each function
  ├── libft.h          # Header file with function prototypes and struct definitions
  ├── Makefile         # Build system
  └── README.md        # This file
```

## Usage

1. **Clone the repository:**
   ```sh
   git clone <git@github.com:mansargs/Libft.git>
   cd Libft
   ```

2. **Build the library:**
   ```sh
   make
   ```

   This will generate a `libft.a` static library.

3. **Include in your project:**
   - Add `libft.h` to your source files.
   - Link with `libft.a` during compilation:
     ```sh
     gcc your_program.c -L. -lft -o your_program
     ```

## Compiling

- To compile the library:
  ```sh
  make
  ```
- To clean object files:
  ```sh
  make clean
  ```
- To remove all generated files:
  ```sh
  make fclean
  ```
- To recompile from scratch:
  ```sh
  make re
  ```

## Bonus Functions

Bonus functions (linked list utilities) are included and can be compiled by running:
```sh
make bonus
```

## Author

- mansargs (mansargs@student.42.fr)

---

**Note:**
This project is for educational purposes and follows the 42 school guidelines.
For any issues or suggestions, feel free to open an issue or contact the author.
