#include "main.h"

void delf_info(const char *filename);

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
 * @filename: pointer to the name of the file
 *
 */
void delf_info(const char *filename)
{
	FILE *myfile;
	Elf32_Ehdr *header;
	int i;

	myfile = fopen(filename, "rb");
	if (myfile == NULL)
	{
		printf("Error: Unable to open file\n");
		return;
	}

	header = (Elf32_Ehdr *)malloc(sizeof(Elf32_Ehdr));
	if (header == NULL)
	{
		printf("Error: Unable to allocate memory\n");
		fclose(myfile);
		return;
	}

	if (fread(header, sizeof(Elf32_Ehdr), 1, myfile) != 1)
	{
		printf("Error: Unable to read file\n");
		free(header);
		fclose(myfile);
		return;
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             ");

	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF54\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
	printf("  Entry point address: 0x%lx\n", (unsigned long)header->e_entry);

	free(header);
	fclose(myfile);
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
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
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

	delf_info(argv[1]);

	close(fd);
	return (0);
}
