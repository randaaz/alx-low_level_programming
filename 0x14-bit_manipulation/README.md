# 0x14. C - Bit Manipulation

Welcome to the "0x14. C - Bit Manipulation" project. In this project, we will explore the world of bit manipulation in the C programming language.

## Learning Objectives

Upon completion of this project, you will be able to:

- Independently research and find relevant information.
- Understand and apply bit manipulation techniques using bitwise operators in C.

## Requirements

To successfully complete this project, you must adhere to the following guidelines:

- Use one of the allowed editors: vi, vim, or emacs.
- Compile all your files on Ubuntu 20.04 LTS using gcc with the following options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Ensure all your code files end with a newline character.
- Include a `README.md` file at the root of your project directory.
- Follow the Betty coding style guidelines. Validate your code using `betty-style.pl` and `betty-doc.pl`.
- Avoid using global variables.
- Limit the number of functions in each source file to no more than 5.
- Utilize the following C standard library functions only: `malloc`, `free`, and `exit`. Do not use functions like `printf`, `puts`, `calloc`, `realloc`, etc.
- You are allowed to use `_putchar`, and you don't need to include `_putchar.c`; it will be provided separately.
- In the provided examples, the `main.c` files are shown as examples for testing your functions. You do not need to push these files to your repository, as we will use our own `main.c` files for compilation.
- Ensure that the prototypes for all your functions and the `_putchar` function are included in your `main.h` header file.
- Protect all your header files with include guards.

## Tasks

### Task 0: Binary to Decimal Conversion

Write a function `binary_to_uint` that converts a binary number represented as a string to an unsigned integer.

**Prototype:**
```c
unsigned int binary_to_uint(const char *b);

##Tasks
##Task 0: Binary to Decimal Conversion
Write a function binary_to_uint that converts a binary number represented as a string to an unsigned integer.

Prototype:


unsigned int binary_to_uint(const char *b);
b points to a string containing only '0' and '1' characters.
Return the converted number or 0 if:
The string b contains one or more characters that are not '0' or '1'.
b is NULL.
Example:


unsigned int n;

n = binary_to_uint("1"); // Should return 1
n = binary_to_uint("101"); // Should return 5
n = binary_to_uint("1e01"); // Should return 0
n = binary_to_uint("1100010"); // Should return 98
n = binary_to_uint("0000000000000000000110010010"); // Should return 402
##Task 1: Binary Printing
Write a function print_binary that prints the binary representation of a number.

Prototype:


void print_binary(unsigned long int n);
The output should match the examples provided.
You are not allowed to use arrays, malloc, or the % or / operators.
Example:


print_binary(0); // Output: 0
print_binary(1); // Output: 1
print_binary(98); // Output: 1100010
print_binary(1024); // Output: 10000000000
print_binary((1 << 10) + 1); // Output: 10000000001
##Task 2: Get Bit Value
Write a function get_bit that returns the value of a bit at a given index.

Prototype:


int get_bit(unsigned long int n, unsigned int index);
index is the index (starting from 0) of the bit you want to get.
Return the value of the bit at index index, or -1 if an error occurs.
Example:


int n;

n = get_bit(1024, 10); // Should return 1
n = get_bit(98, 1); // Should return 1
n = get_bit(1024, 0); // Should return 0

##Task 3: Set Bit Value
Write a function set_bit that sets the value of a bit to 1 at a given index.

Prototype:


int set_bit(unsigned long int *n, unsigned int index);
index is the index (starting from 0) of the bit you want to set.
Return 1 if the operation succeeds, or -1 if an error occurs.
Example:


unsigned long int n;

n = 1024;
set_bit(&n, 5); // n should be updated to 1056
n = 0;
set_bit(&n, 10); // n should be updated to 1024
n = 98;
set_bit(&n, 0); // n should be updated to 99
##Task 4: Clear Bit Value
Write a function clear_bit that sets the value of a bit to 0 at a given index.

Prototype:


int clear_bit(unsigned long int *n, unsigned int index);
index is the index (starting from 0) of the bit you want to set to 0.
Return 1 if the operation succeeds, or -1 if an error occurs.
Example:


unsigned long int n;

n = 1024;
clear_bit(&n, 10); // n should be updated to 0
n = 0;
clear_bit(&n, 10); // n should remain 0
n = 98;
clear_bit(&n, 1); // n should be updated to 96
##Task 5: Flip Bits
Write a function flip_bits that returns the number of bits you would need to flip to get from one number to another.

Prototype:


unsigned int flip_bits(unsigned long int n, unsigned long int m);
Do not use the % or / operators.
Example:

c
unsigned int n;

n = flip_bits(1024, 1); // Should return 2
n = flip_bits(402, 98); // Should return 5
n = flip_bits(1024, 3); // Should return 3
n = flip_bits(1024, 1025); // Should return 1

##2 advanced taskes

##Author
This project was created by Julien Barbier.
