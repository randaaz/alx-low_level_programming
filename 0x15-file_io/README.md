# 0x15. C - File I/O

## Description
This project focuses on working with file I/O operations in C, including creating, reading, writing, and copying files. The main learning objectives are as follows:

### General
- How to create, open, close, read, and write files
- Understanding file descriptors and their purpose
- Knowledge of the 3 standard file descriptors and their POSIX names
- Usage of I/O system calls like open, close, read, and write
- Understanding and use of flags like O_RDONLY, O_WRONLY, O_RDWR
- Managing file permissions when creating a file with the open system call
- Understanding the concept of system calls
- Distinguishing between a function and a system call

## Requirements
- Allowed editors: vi, vim, emacs
- Compilation on Ubuntu 20.04 LTS using gcc with the following options: -Wall -Werror -Wextra -pedantic -std=gnu89
- All code files should end with a new line
- A `README.md` file must be included at the root of the project folder
- Code should adhere to the Betty style and be checked using betty-style.pl and betty-doc.pl
- No use of global variables is allowed
- Each file should contain no more than 5 functions
- Only the C standard library functions `malloc`, `free`, and `exit` are allowed
- Allowed syscalls: `read`, `write`, `open`, `close`
- Usage of `_putchar` is allowed, and you don't need to push `_putchar.c`
- Prototypes of all functions and the `_putchar` function should be included in a header file named `main.h`
- All header files should have include guards
- Symbolic constants (POSIX) should be used instead of numbers when applicable

## Tasks

### 0. Tread lightly, she is near
Write a function `read_textfile` that reads a text file and prints it to the POSIX standard output.

- Prototype: `ssize_t read_textfile(const char *filename, size_t letters);`
- `letters` is the number of letters it should read and print
- Returns the actual number of letters it could read and print
- If the file cannot be opened or read, return 0
- If `filename` is NULL, return 0
- If write fails or does not write the expected amount of bytes, return 0

### 1. Under the snow
Create a function `create_file` that creates a file.

- Prototype: `int create_file(const char *filename, char *text_content);`
- `filename` is the name of the file to create, and `text_content` is a NULL-terminated string to write to the file
- Returns: 1 on success, -1 on failure
- The created file must have permissions: `rw-------`
- If the file already exists, do not change the permissions
- If the file already exists, truncate it
- If `filename` is NULL, return -1
- If `text_content` is NULL, create an empty file

### 2. Speak gently, she can hear
Write a function `append_text_to_file` that appends text at the end of a file.

- Prototype: `int append_text_to_file(const char *filename, char *text_content);`
- `filename` is the name of the file, and `text_content` is the NULL-terminated string to add at the end of the file
- Returns: 1 on success and -1 on failure
- Do not create the file if it does not exist
- If `filename` is NULL, return -1
- If `text_content` is NULL, do not add anything to the file

### 3. cp
Write a program that copies the content of a file to another file.

- Usage: `cp file_from file_to`
- If the number of arguments is not correct, exit with code 97 and print `Usage: cp file_from file_to`, followed by a new line, on the POSIX standard error
- If `file_to` already exists, truncate it
- If `file_from` does not exist or if you cannot read it, exit with code 98 and print `Error: Can't read from file NAME_OF_THE_FILE`, followed by a new line, on the POSIX standard error (where `NAME_OF_THE_FILE` is the first argument passed to your program)
- If you cannot create or if write to `file_to` fails, exit with code 99 and print `Error: Can't write to NAME_OF_THE_FILE`, followed by a new line, on the POSIX standard error (where `NAME_OF_THE_FILE` is the second argument passed to your program)
- If you cannot close a file descriptor, exit with code 100 and print `Error: Can't close fd FD_VALUE`, followed by a new line, on the POSIX standard error (where `FD_VALUE` is the value of the file descriptor)
- Permissions of the created file: `rw-rw-r--`
- You must read 1,024 bytes at a time from `file_from` to make fewer system calls. Use a buffer
- You are allowed to use `dprintf`
### 1 advanced taske
## Author
- Julien Barbier
