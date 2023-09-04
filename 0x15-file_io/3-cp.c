#include "main.h"

/**
 * print_error - prints an error and exits
 * @ex_code: exit code
 * @format: format string for the error message
 * @arg: argument for the format string
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
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success or an error code on failure
 */
int main(int argc, char *argv[])
{
	int frm, f_to, rd, wt;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		print_error(97, "Usage: cp frm f_to\n", 0);
	frm = open(argv[1], O_RDONLY);

	if (frm == -1)
		print_error(98, "Error: Can't read from file %s\n", argv[1]);

	f_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (f_to == -1)
	{
		close(frm);
		print_error(99, "Error: Can't write to %s\n", argv[2]);
	}
	while ((rd = read(frm, buffer, BUFFER_SIZE)) > 0)
	{
		wt = write(f_to, buffer, rd);

		if (wt == -1)
		{
			close(frm);
			close(f_to);
			print_error(99, "Error: Can't write to %s\n", argv[2]);
		}
	}
	if (rd == -1)
	{
		close(frm);
		close(f_to);
		print_error(98, "Error: Can't read from file %s\n", argv[1]);
	}
	if (close(frm) == -1)
		print_error(100, "Error: Can't close fd %d\n", frm);
	if (close(f_to) == -1)
		print_error(100, "Error: can't close fd %d\n", f_to);

	return (0);
}
