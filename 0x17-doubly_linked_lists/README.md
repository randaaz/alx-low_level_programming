# 0x17. C - Doubly Linked Lists

## Description

This repository contains the C code for a project on doubly linked lists. It includes various functions to work with doubly linked lists.

## Table of Contents

	- [Description](#description)
	- [Requirements](#requirements)
	- [Files](#files)
	- [Usage](#usage)
- [Tasks](#tasks)

## Requirements

	- Allowed editors: `vi`, `vim`, `emacs`
	- All files will be compiled on Ubuntu 20.04 LTS using `gcc` with the flags `-Wall`, `-pedantic`, `-Werror`, and `-Wextra`
	- All your files should end with a new line
	- A `README.md` file, at the root of the folder, is mandatory
	- Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
	- You are not allowed to use global variables
	- No more than 5 functions per file
	- The only C standard library functions allowed are `malloc`, `free`, `printf`, and `exit`
	- The prototypes of all your functions should be included in your header file called `lists.h`
	- Don't forget to push your header file
	- All your header files should be include guarded

## Files

	- `0-print_dlistint.c`: Function that prints all the elements of a `dlistint_t` list.
	- `1-dlistint_len.c`: Function that returns the number of elements in a linked `dlistint_t` list.
	- `2-add_dnodeint.c`: Function that adds a new node at the beginning of a `dlistint_t` list.
	- `3-add_dnodeint_end.c`: Function that adds a new node at the end of a `dlistint_t` list.
	- `4-free_dlistint.c`: Function that frees a `dlistint_t` list.
	- `5-get_dnodeint_at_index.c`: Function that returns the nth node of a `dlistint_t` linked list.
	- `6-sum_dlistint.c`: Function that returns the sum of all the data (`n`) of a `dlistint_t` linked list.
	- `7-insert_dnodeint.c`: Function that inserts a new node at a given position.
	- `8-delete_dnodeint.c`: Function that deletes the node at a given index of a `dlistint_t` linked list.
	- `lists.h`: Header file containing function prototypes and the `dlistint_t` struct definition.
	- `0-main.c`, `1-main.c`, `2-main.c`, `3-main.c`, `4-main.c`, `5-main.c`, `6-main.c`, `7-main.c`, `8-main.c`: Main programs to test the respective functions.

## Usage

	To compile the C programs, you can use the following commands:

	```bash
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 <main_program.c> <function_file.c> -o <output_program>
