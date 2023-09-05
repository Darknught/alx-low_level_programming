#include "main.h"

/**
 * print_error - prints error message and exit
 * @ex_code: exit code of the program
 * @format: format string of the error message
 *
 */
void print_error(int ex_code, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(ex_code);
}

/**
 * delf_info - display information from the ELF header
 * @header: pointer to the ELF header
 *
 */
void delf_info(Elf64_Ehdr *header)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("Class: %d\n", header->e_ident[EI_CLASS]);
	printf("Data: %d\n", header->e_ident[EI_DATA]);
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type: %d\n", header->e_type);
	printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t r_bytes;

	Elf64_Ehdr header;

	if (argc != 2)
	{
		print_error(97, "Usage: elf_header elf_filename\n");
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		print_error(98, "Error: Unable to open file\n");
	}

	r_bytes = read(fd, &header, sizeof(header));

	if (r_bytes == -1 || (size_t)r_bytes < sizeof(header))
	{
		print_error(98, "Error: Unable to read ELF header\n");
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0
			|| header.e_ident[EI_MAG1] != ELFMAG1
			|| header.e_ident[EI_MAG2] != ELFMAG2
			|| header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error(98, "Error: Not an ELF file\n");
	}

	delf_info(&header);

	close(fd);
	return (0);
}
