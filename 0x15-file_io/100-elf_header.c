#include "main.h"
#include <elf.h>

void print_m(Elf64_Ehdr d);
void print_c(Elf64_Ehdr d);
void print_d(Elf64_Ehdr d);
void print_v(Elf64_Ehdr d);
void print_o(Elf64_Ehdr d);
void print_a(Elf64_Ehdr d);
void print_t(Elf64_Ehdr d);
void print_entry(Elf64_Ehdr d);

/**
 * main - Entry point
 * @argc: number
 * @argv: An array
 *
 * Return: 0 on successful execution
 */

int main(int argc, char **argv)
{
	int num;
	Elf64_Ehdr d;
	ssize_t b;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	num = open(argv[1], O_RDONLY);
	if (num == -1)
		dprintf(STDERR_FILENO, "Can't open file: %s\n", argv[1]), exit(98);
	b = read(num, &d, sizeof(d));
	if (b < 1 || b != sizeof(d))
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", argv[1]), exit(98);
	if (d.e_ident[EI_MAG0] != ELFMAG0 || d.e_ident[EI_MAG1] != ELFMAG1 ||
			d.e_ident[EI_MAG2] != ELFMAG2 || d.e_ident[EI_MAG3] != ELFMAG3)
		dprintf(STDERR_FILENO, " NOT ELF file: %s\n", argv[1]), exit(98);
	printf("ELF Header:\n");
	print_m(d);
	print_c(d);
	print_d(d);
	print_v(d);
	print_o(d);
	print_a(d);
	print_t(d);
	print_entry(d);
	if (close(num))
		dprintf(STDERR_FILENO, " Error closing file: %d\n", num), exit(98);
	return (EXIT_SUCCESS);
}

/**
 * print_m - Print the magic
 * @d: The ELF
 */
void print_m(Elf64_Ehdr d)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x%s", d.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * print_c - Print the ELF class
 * @d: The ELF
 */
void print_c(Elf64_Ehdr d)
{
	printf("  Class:                             ");
	switch (d.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASSNONE:
			printf("none");
			break;
	}
	printf("\n");
}

/**
 * print_d - Print the endianness
 * @d: The ELF
 */
void print_d(Elf64_Ehdr d)
{
	printf("  Data:                              ");
	switch (d.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			break;
		case ELFDATANONE:
			printf("none");
			break;
	}
	printf("\n");
}

/**
 * print_v - Print ELF version
 * @d: The ELF
 */
void print_v(Elf64_Ehdr d)
{
	printf("  Version:                           %d", d.e_ident[EI_VERSION]);
	switch (d.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}
}

/**
 * print_o - Print the Operating System/ABI
 * @d: The ELF
 */
void print_o(Elf64_Ehdr d)
{
	printf("  OS/ABI:                            ");
	switch (d.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			print_a(d);
	}
	printf("\n");
}

/**
 * print_a - Print more detailed OS/ABI information
 * @d: The ELF
 */
void print_a(Elf64_Ehdr d)
{
	switch (d.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Nove11 - Modesto");
			break;
		default:
			printf("<unknown: %x>", d.e_ident[EI_OSABI]);
	}
}

/**
 * print_t - Print the ABI version
 * @d: The ELF
 */
void print_t(Elf64_Ehdr d)
{
	printf("  ABI Version:                       %d\n", d.e_ident[EI_ABIVERSION]);
}

/**
 * print_entry - Print the ELF type
 * @d: The ELF
 */
void print_entry(Elf64_Ehdr d)
{
	int i, l = 0;
	unsigned char *p = (unsigned char *)&d.e_entry;

	printf("  Entry point address:               0x");
	if (d.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		i = (d.e_ident[EI_CLASS] == ELFCLASS64) ? 7 : 3;
		while (!p[i])
			i--;
		printf("%x", p[i--]);
		for (; i >= 0; i--)
			printf("%02x", p[i]);
		printf("\n");
	}
	else
	{
		i = 0;
		l = (d.e_ident[EI_CLASS] == ELFCLASS64) ? 7 : 3;
		while (!p[i])
			i++;
		printf("%x", p[i++]);
		for (; i <= l; i++)
			printf("%02x", p[i]);
		printf("\n");
	}
}
