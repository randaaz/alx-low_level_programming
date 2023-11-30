# 0x1A. C - Hash tables

## Description
This project involves the implementation of hash tables in the C programming language. The goal is to create a set of functions that allow the creation, manipulation, and deletion of hash tables. The tasks include writing functions for creating a hash table, implementing a hash function (djb2 algorithm), finding the index of a key in the hash table, setting a key-value pair in the hash table, retrieving the value associated with a key, printing the hash table, and deleting the hash table.

## Learning Objectives
Upon completion of this project, you should be able to:

### General
- Explain what a hash function is and what makes a good hash function.
- Understand how hash tables work and how to use them.
- Deal with collisions in the context of a hash table.
- Recognize the advantages and drawbacks of using hash tables.
- Identify common use cases for hash tables.

## Requirements
### General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, with the options -Wall -Werror -Wextra -pedantic -std=gnu89.
- All your files should end with a new line.
- A README.md file at the root of the project is mandatory.
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl.
- Do not use global variables.
- No more than 5 functions per file.
- You are allowed to use the C standard library.
- The prototypes of all your functions should be included in your header file called hash_tables.h.
- Don’t forget to push your header file.
- All your header files should be include guarded.

## Data Structures
Please use the following data structures for this project:

## Tasks
- 0. >>> ht = {}
- 1. djb2
- 2. key -> index
- 3. >>> ht['betty'] = 'cool'
- 4. >>> ht['betty']
- 5. >>> print(ht)
- 6. >>> del ht
- 1 advanced task

```c
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

