#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>


/**
 * print_m - Print the ELF header's magic bytes.
 * @d: ELF header structure
 */

void print_m(Elf64_Ehdr d)
{
	int j;

	printf("  Magic:   ");
	for (j = 0; j < EI_NIDENT; j++)
	{
		printf("%2.2x%s", d.e_ident[j], j == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_c - Print the ELF header's class information.
 * @d: ELF header structure
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
 * print_o - Print the ELF header's OS/ABI information.
 * @d: ELF header structure
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
			printf("UNIX - HP_UX");
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
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			printf("<unknown: %x>", d.e_ident[EI_OSABI]);
			break;
	}
	printf("\n");
}

/**
 * print_p_o_m - Print the ELF header's processor-specific OS/ABI information.
 * @d: ELF header structure
 */

void print_p_o_m(Elf64_Ehdr d)
{
	switch (d.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Non-ELF - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone APP");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("<unknown: %x>", d.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_d - Print the ELF header's data format information.
 * @d: ELF header structure
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
 * print_v - Print the ELF header's version information.
 * @d: ELF header structure
 */

void print_v(Elf64_Ehdr d)
{
	printf("  Version:                           %d", d.e_ident[EI_VERSION]);
	switch (d.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
			break;
		default:
			printf("%s", "");
			break;
	}
	printf("\n");
}

/**
 * print_a - Print the ELF header's ABI version information.
 * @d: ELF header structure
 */

void print_a(Elf64_Ehdr d)
{
	printf("  ABI Version:                       %d\n", d.e_ident[EI_ABIVERSION]);
}

/**
 * print_t - Print the ELF header's type information.
 * @d: ELF header structure
 */

void print_t(Elf64_Ehdr d)
{
	char *ptr = (char *)&d.e_type;
	int j = 0;

	printf("  Type:                              ");
	if (d.e_ident[EI_DATA] == ELFDATA2MSB)
		j = 1;
	switch (ptr[j])
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
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", ptr[j]);
			break;
	}
	printf("\n");
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 98 on error
 */

int main(int argc, char **argv)
{
	int ptr;
	Elf64_Ehdr d;
	ssize_t n;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
	return (98);
	ptr = open(argv[1], O_RDONLY);
	if (ptr == -1)
		dprintf(STDERR_FILENO, "Can't open file : %s\n", argv[1]);
	return (98);
	n = read(ptr, &d, sizeof(d));
	if (n < 1 || n != sizeof(d))
		dprintf(STDERR_FILENO, "Can't read file : %s\n", argv[1]);
	return (98);
	if (d.e_ident[0] == 0x7f && d.e_ident[1] == 'E' &&
			d.e_ident[2] == 'L' && d.e_ident[3] == 'F')
		printf("ELF Header:\n");
	else
		dprintf(STDERR_FILENO, "NOT ELF file: %s\n", argv[1]);
	return (98);
	print_m(d);
	print_c(d);
	print_d(d);
	print_v(d);
	print_o(d);
	print_a(d);
	print_t(d);
	if (close(ptr) == -1)
		dprintf(STDERR_FILENO, "ERROR close file descriptor: %d\n", ptr);
	return (98);
	return (0);
}
