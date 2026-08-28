# get_next_line

## Overview

`get_next_line` is a C project that implements a function to read a file or input stream line by line, returning each line with each call. This is a common utility in many applications, especially those that process text files or streams.

The project is split into two parts:
- **Mandatory part**: Basic functionality for reading from a single file descriptor.
- **Bonus part**: Extended functionality to handle multiple file descriptors simultaneously.

---

## How it Works

The core function is:

```c
char *get_next_line(int fd);
```
- **fd**: The file descriptor to read from.
- Returns: A pointer to a string containing the next line (including the newline character, if present), or `NULL` if there is nothing more to read or an error occurs.

The function uses a static buffer to store leftover data between calls, ensuring that lines are returned correctly even if they span multiple reads.

Helper functions (in `get_next_line_utils.c` and `get_next_line_utils_bonus.c`) handle string operations and memory management.

---

## Files

- `get_next_line.c` / `get_next_line.h`: Mandatory implementation and header.
- `get_next_line_utils.c`: Utility functions for the mandatory part.
- `get_next_line_bonus.c` / `get_next_line_bonus.h`: Bonus implementation and header.
- `get_next_line_utils_bonus.c`: Utility functions for the bonus part.

---

## Usage

1. **Include the header** in your C file:
   ```c
   #include "get_next_line.h" // or get_next_line_bonus.h for bonus
   ```
2. **Compile** with all required source files. Example:
   ```sh
   cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl
   # For bonus:
   cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
   ```
3. **Call `get_next_line(fd)`** in a loop to read lines from a file descriptor:
   ```c
   int fd = open("file.txt", O_RDONLY);
   char *line;
   while ((line = get_next_line(fd)) != NULL) {
       // process line
       free(line);
   }
   close(fd);
   ```

---

## Differences: Mandatory vs Bonus Part

### Mandatory Part
- Only supports reading from **one file descriptor at a time**.
- Uses a single static buffer to store leftover data between calls.
- If you call `get_next_line` with a different file descriptor, the previous state is lost.

### Bonus Part
- Supports reading from **multiple file descriptors simultaneously**.
- Uses an array of static buffers, one for each possible file descriptor (up to `OPEN_MAX`).
- You can call `get_next_line` with different file descriptors in any order, and each will maintain its own state.

**Summary Table:**

| Feature                | Mandatory | Bonus  |
|------------------------|:---------:|:------:|
| Multiple FDs           |     ❌     |   ✅   |
| Static buffer per FD   |     ❌     |   ✅   |
| Suitable for multiplex |     ❌     |   ✅   |

---

## Notes
- The buffer size can be changed by defining `BUFFER_SIZE` at compile time.
- Remember to free the returned line after use to avoid memory leaks.
- Error handling is included for invalid file descriptors and memory allocation failures.

---

## Author
- mansargs <mansargs@student.42.fr>
