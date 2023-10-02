#include "main.h"
#include <elf.h>

void print_osabi_more(Elf64_Ehdr x);
void print_magic(Elf64_Ehdr x);
void print_class(Elf64_Ehdr x);
void print_data(Elf64_Ehdr x);
void print_version(Elf64_Ehdr x);
void print_osabi(Elf64_Ehdr x);
void print_abiversion(Elf64_Ehdr x);
void print_type(Elf64_Ehdr x);
void print_entry(Elf64_Ehdr x);

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
	Elf64_Ehdr x;
	ssize_t b;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	num = open(argv[1], O_RDONLY);
	if (num == -1)
		dprintf(STDERR_FILENO, "Can't open file: %s\n", argv[1]), exit(98);
	b = read(num, &x, sizeof(x));
	if (b < 1 || b != sizeof(x))
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", argv[1]), exit(98);
	if (x.e_ident[EI_MAG0] != ELFMAG0 || x.e_ident[EI_MAG1] != ELFMAG1 ||
			x.e_ident[EI_MAG2] != ELFMAG2 || x.e_ident[EI_MAG3] != ELFMAG3)
		dprintf(STDERR_FILENO, " NOT ELF file: %s\n", argv[1]), exit(98);
	printf("ELF Header:\n");
	print_magic(x);
	print_class(x);
	print_data(x);
	print_version(x);
	print_osabi(x);
	print_abiversion(x);
	print_type(x);
	print_entry(x);
	if (close(num))
		dprintf(STDERR_FILENO, " Error closing file: %d\n", num), exit(98);
	return (EXIT_SUCCESS);
}

/**
 * print_magic - Print the magic
 * @x: The ELF
 */
void print_magic(Elf64_Ehdr x)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x%s", x.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * print_class - Print the ELF class
 * @x: The ELF
 */
void print_class(Elf64_Ehdr x)
{
	printf("  Class:                             ");
	switch (x.e_ident[EI_CLASS])
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
 * print_data - Print the endianness
 * @x: The ELF
 */
void print_data(Elf64_Ehdr x)
{
	printf("  Data:                              ");
	switch (x.e_ident[EI_DATA])
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
 * print_version - Print ELF version
 * @x: The ELF
 */
void print_version(Elf64_Ehdr x)
{
	printf("  Version:                           %d", x.e_ident[EI_VERSION]);
	switch (x.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}
}

/**
 * print_osabi - Print the Operating System/ABI
 * @x: The ELF
 */
void print_osabi(Elf64_Ehdr x)
{
	printf("  OS/ABI:                            ");
	switch (x.e_ident[EI_OSABI])
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
			print_osabi_more(x);
	}
	printf("\n");
}

/**
 * print_osabi_more - Print more detailed OS/ABI information
 * @x: The ELF
 */
void print_osabi_more(Elf64_Ehdr x)
{
	switch (x.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Nove11 - Modesto");
			break;
		default:
			printf("<unknown: %x>", x.e_ident[EI_OSABI]);
	}
}

/**
 * print_abiversion - Print the ABI version
 * @x: The ELF
 */
void print_abiversion(Elf64_Ehdr x)
{
	printf("  ABI Version:                       %d\n", x.e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Print the ELF type
 * @x: The ELF
 */
void print_type(Elf64_Ehdr x)
{
	char *ptr = (char *)&x.e_type;
	int i = (x.e_ident[EI_DATA] == ELFDATA2MSB) ? 1 : 0;

	printf("  Type:                              ");
	switch (ptr[i])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (core file)");
			break;
		default:
			printf("<unknown>: %x", ptr[i]);
	}
	printf("\n");
}

/**
 * print_entry - Print the entry point address
 * @x: The ELF
 */
void print_entry(Elf64_Ehdr x)
{
	int i, l = 0;
	unsigned char *p = (unsigned char *)&x.e_entry;

	printf("  Entry point address:               0x");
	if (x.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		i = (x.e_ident[EI_CLASS] == ELFCLASS64) ? 7 : 3;
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
		l = (x.e_ident[EI_CLASS] == ELFCLASS64) ? 7 : 3;
		while (!p[i])
			i++;
		printf("%x", p[i++]);
		for (; i <= l; i++)
			printf("%02x", p[i]);
		printf("\n");
	}
}
