#include "main.h"
#include <elf.h>

void printOsabiMore(Elf64_Ehdr d);
void printMagic(Elf64_Ehdr d);
void printClass(Elf64_Ehdr d);
void printData(Elf64_Ehdr d);
void printVersion(Elf64_Ehdr d);
void printOsabi(Elf64_Ehdr d);
void printAbiVersion(Elf64_Ehdr d);
void printType(Elf64_Ehdr d);
void printEntry(Elf64_Ehdr d);

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
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
	printMagic(d);
	printClass(d);
	printData(d);
	printVersion(d);
	printOsabi(d);
	printAbiVersion(d);
	printType(d);
	printEntry(d);
	if (close(num))
		dprintf(STDERR_FILENO, " Error closing file: %d\n", num), exit(98);
	return (EXIT_SUCCESS);
}

/**
 * printMagic - Print the magic bytes from the ELF header
 * @d: The ELF header structure
 */
void printMagic(Elf64_Ehdr d)
{
	int j;

	printf("  Magic:   ");
	for (j = 0; j < EI_NIDENT; j++)
		printf("%2.2x%s", d.e_ident[j], j == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * printClass - Print the ELF class information from the ELF header
 * @d: The ELF header structure
 */
void printClass(Elf64_Ehdr d)
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
 * printData - Print the endianness information from the ELF header
 * @d: The ELF header structure
 */
void printData(Elf64_Ehdr d)
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
 * printVersion - Print the ELF version from the ELF header
 * @d: The ELF header structure
 */
void printVersion(Elf64_Ehdr d)
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
 * printOsabi - Print the Operating System/ABI information from the ELF header
 * @d: The ELF header structure
 */
void printOsabi(Elf64_Ehdr d)
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
			printOsabiMore(d);
	}
	printf("\n");
}

/**
 * printOsabiMore - Print more detailed OS/ABI information from the ELF header
 * @d: The ELF header structure
 */
void printOsabiMore(Elf64_Ehdr d)
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
 * printAbiVersion - Print the ABI version from the ELF header
 * @d: The ELF header structure
 */
void printAbiVersion(Elf64_Ehdr d)
{
	printf("  ABI Version:                       %d\n", d.e_ident[EI_ABIVERSION]);
}

/**
 * printType - Print the ELF type information from the ELF header
 * @d: The ELF header structure
 */
void printType(Elf64_Ehdr d)
{
	char *ptr = (char *)&d.e_type;
	int i = (d.e_ident[EI_DATA] == ELFDATA2MSB) ? 1 : 0;

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
 * printEntry - Print the entry point address
 * @d: The ELF header structure
 */
void printEntry(Elf64_Ehdr d)
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

