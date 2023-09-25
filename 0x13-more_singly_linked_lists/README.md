#Project README
##Description
This project is a C programming project that focuses on singly linked lists. It contains a set of tasks that involve creating and manipulating singly linked lists. The main objective of this project is to improve your understanding of linked lists and their usage in C programming.

##Learning Objectives
By completing this project, you will achieve the following learning objectives:

How to use linked lists: You will gain a deep understanding of how linked lists work and how to create and manipulate them in C.

Start to look for the right source of information without too much help: You will develop the skill of searching for relevant information and resources independently to solve programming challenges.

Copyright - Plagiarism: You will learn about the importance of originality and the consequences of plagiarism. It is essential to produce your own work and avoid copying or using someone else's work without proper attribution.

##Requirements
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the following options: -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line.
A README.md file, at the root of the project folder, is mandatory.
Your code should follow the Betty style. It will be checked using betty-style.pl and betty-doc.pl.
You are not allowed to use global variables.
No more than 5 functions per file.
The only C standard library functions allowed are malloc, free, and exit. Avoid using functions like printf, puts, calloc, realloc, etc.
You are allowed to use _putchar.
You don’t have to push _putchar.c; we will use our own file.
The prototypes of all your functions and the prototype of the function _putchar should be included in your header file called lists.h.
Don’t forget to push your header file.
All your header files should be include guarded.
Task List
Task 0: Print list
Write a function that prints all the elements of a listint_t list.

Prototype: size_t print_listint(const listint_t *h);

Return: the number of nodes

Format: see example

You are allowed to use printf.

##Task 1: List length
Write a function that returns the number of elements in a listint_t list.

Prototype: size_t listint_len(const listint_t *h);

##Task 2: Add node
Write a function that adds a new node at the beginning of a listint_t list.

Prototype: listint_t *add_nodeint(listint_t **head, const int n);

Return: the address of the new element, or NULL if it failed

##Task 3: Add node at the end
Write a function that adds a new node at the end of a listint_t list.

Prototype: listint_t *add_nodeint_end(listint_t **head, const int n);

Return: the address of the new element, or NULL if it failed

##Task 4: Free list
Write a function that frees a listint_t list.

Prototype: void free_listint(listint_t *head);

##Task 5: Free
Write a function that frees a listint_t list.

Prototype: void free_listint2(listint_t **head);

The function sets the head to NULL.

##Task 6: Pop
Write a function that deletes the head node of a listint_t linked list, and returns the head node’s data (n).

Prototype: int pop_listint(listint_t **head);

If the linked list is empty, return 0.

##Task 7: Get node at index
Write a function that returns the nth node of a listint_t linked list.

Prototype: listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

Where index is the index of the node, starting at 0.

If the node does not exist, return NULL.

##Task 8: Sum list
Write a function that returns the sum of all the data (n) of a listint_t linked list.

Prototype: int sum_listint(listint_t *head);

If the list is empty, return 0.

##Task 9: Insert
Write a function that inserts a new node at a given position.

## advanced tasks
4 advanced tasks
Prototype: listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

Where idx is the index of the list where the new node should be added. Index starts at 0.

Return: the address of the new node, or NULL if it failed.

If it is not possible to add the new node at index idx, do not add the new node and return NULL.

##Task 10: Delete at index
Write a function that deletes the node at index index of a listint_t linked list.

Prototype: int delete_nodeint_at_index(listint_t **head, unsigned int index);

Where index is the index of the node that should be deleted. Index starts at 0.

Return: 1 if it succeeded, -1 if it failed.

###Repository
GitHub repository: alx-low_level_programming
Directory: 0x13-more_singly_linked_lists
Usage
To test your code for each task, you can use the provided main.c files as examples. Compile them with the necessary source files to create executables. For example:

bash
Copy code
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-print_listint.c -o 0-print_listint
Execute the resulting executable:

bash
Copy code
./0-print_listint
Make sure to replace the file names and task numbers accordingly when testing other tasks.

##Author RANDA ABDELAZIZE

##Email randaaziz972@gmail.com
