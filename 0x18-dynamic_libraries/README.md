# 0x18. C - Dynamic libraries

## Description
This project is part of the ALX Low-Level Programming curriculum and focuses on understanding and creating dynamic libraries in C. The tasks involve creating a dynamic library, understanding the differences between static and dynamic libraries, and using various tools such as `nm`, `ldd`, and `ldconfig`. The project is designed to enhance your knowledge of dynamic libraries, their creation, usage, and related concepts.

## Learning Objectives
By the end of this project, you should be able to:
- Explain what a dynamic library is, how it works, how to create one, and how to use it.
- Understand the environment variable `$LD_LIBRARY_PATH` and how to use it.
- Differentiate between static and shared libraries.
- Use basic tools such as `nm`, `ldd`, and `ldconfig`.

## Copyright - Plagiarism
Please ensure that you come up with solutions for the tasks on your own, without copying and pasting someone else's work. Plagiarism is strictly forbidden and will result in removal from the program.

## Requirements
### C
- Allowed editors: vi, vim, emacs
- All files compiled on Ubuntu 20.04 LTS using gcc with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A `README.md` file at the root of the project folder is mandatory
- Code should use the Betty style, checked using `betty-style.pl` and `betty-doc.pl`
- No global variables allowed
- No more than 5 functions per file
- Do not use the standard library (functions like `printf`, `puts`, etc. are forbidden)
- Allowed to use `_putchar`
- Do not push `_putchar.c`; it will not be taken into account
- Prototypes of all functions and the `_putchar` function should be included in the header file `main.h`
- Push the header file

### Bash
- Allowed editors: vi, vim, emacs
- All scripts tested on Ubuntu 20.04 LTS
- All files should end with a new line
- The first line of all files should be `#!/bin/bash`
- A `README.md` file at the root of the project folder describing each script
- All files must be executable

## Tasks

### Task 0: A library is not a luxury but one of the necessities of life
**Files:** `libdynamic.so`, `main.h`, `0-main.c`

Create the dynamic library `libdynamic.so` containing the listed functions. If any functions are missing, create empty ones with the correct prototype. Make sure to include the `main.h` file with the prototypes.

**Example Usage:**
```bash
$ ls -la lib*
-rwxrwxr-x 1 user user 13632 Jan  7 06:25 libdynamic.so

$ nm -D libdynamic.so
# ... (output listing symbols in the library)

# Task 1: Without libraries what have we? We have no past and no future

## File: 1-create_dynamic_lib.sh

Create a script that generates a dynamic library called `liball.so` from all the `.c` files in the current directory.

### Example Usage:

```bash
$ ls *.c
abs.c   isalpha.c  islower.c  memcpy.c  putchar.c  strcat.c  strcmp.c  strlen.c   strncpy.c  strspn.c
atoi.c  isdigit.c  isupper.c  memset.c  puts.c     strchr.c  strcpy.c  strncat.c  strpbrk.c  strstr.c

$ ./1-create_dynamic_lib.sh
$ nm -D --defined-only liball.so
# ... (output listing symbols in the library)
## 2 Advanced tasks
