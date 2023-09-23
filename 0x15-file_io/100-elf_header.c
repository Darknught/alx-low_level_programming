#include "main.h"

void checking_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_myclass(unsigned char *e_ident);
void print_mydata(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * checking_elf - checks if a file is an ELF file
 * @e_ident: A pointer to an array containing ELF magic numbers
 *
 */
void checking_elf(unsigned char *e_ident)
{
	int myidx;

	for (myidx = 0; myidx < 4; myidx++)
	{
		if (e_ident[myidx] != 127 &&
				e_ident[myidx] != 'E' &&
				e_ident[myidx] != 'L' &&
				e_ident[myidx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prints the magic numbers of an ELF hearder
 * @e_ident: A pointer to an array containing the ELF magic numbers
 *
 */
void print_magic(unsigned char *e_ident)
{
	int myidx;

	printf("  Magic:   ");

	for (myidx = 0; myidx < EI_NIDENT; myidx++)
	{
		printf("%02x", e_ident[myidx]);

		if (myidx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_myclass - prints the class of an ELF header
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_myclass(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF54\n");
		break;
	default:
		printf("unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_mydata - prints the data of an ELF header
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_mydata(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's compliment, little endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - prints the version of an ELF header
 * @e_ident: A pointer to an array containing the ELF version
 *
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
				e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - prints the OS/ABI of an ELF header
 * @e_ident: A pointer to an array containing the ELF version
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX -IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints the ABI version of an ELF header
 * @e_ident:
 * A pointer to an array containing the ELF ABI version
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of an ELF header
 * @e_type: The ELF type
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - prints the entry point of an ELF header
 * @e_entry: the address of the ELF entry point
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file
 * @elf: The file descriptor of the ELF file
 *
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Cant close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information in the ELF header at start
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 * Return: 0 (success)
 *
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *myheader;
	int x, y;

	x = open(argv[1], O_RDONLY);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant read file %s\n", argv[1]);
		exit(98);
	}
	myheader = malloc(sizeof(Elf64_Ehdr));
	if (myheader == NULL)
	{
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: Cant read file %s\n", argv[1]);
		exit(98);
	}
	y = read(x, myheader, sizeof(Elf64_Ehdr));

	if (y == -1)
	{
		free(myheader);
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	checking_elf(myheader->e_ident);
	printf("ELF Header:\n");
	print_magic(myheader->e_ident);
	print_myclass(myheader->e_ident);
	print_mydata(myheader->e_ident);
	print_version(myheader->e_ident);
	print_osabi(myheader->e_ident);
	print_abi(myheader->e_ident);
	print_type(myheader->e_type, myheader->e_ident);
	print_entry(myheader->e_entry, myheader->e_ident);

	free(myheader);
	close_elf(x);
	return (0);
}
