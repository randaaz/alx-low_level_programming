#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_m(ELF64_Ehde d);
void print_c(ELF64_Ehdr d);
void print_o(ELF64_Ehdr d);
void print_d(ELF64_Ehdr d);
void print_v(ELF64_Ehdr d);

#endif
