#include "main.h"

/**
 * read_textfile - Reads a textfile and prints it to POSIX stdout
 * @filename: pointer to the name of the file
 * @letters: number of letters for the function to print
 * Return: 0 if file cannot open.
 * 0 if write fails and does not print actual number of bytes.
 *
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t op, rd, wt;
	char *buff;

	buff = malloc(sizeof(char) * letters);

	op = open(filename, O_RDONLY);
	rd = read(op, buff, letters);
	wt = write(STDOUT_FILENO, buff, rd);

	if (filename == NULL)
		return (0);

	if (buff == NULL)
		return (0);

	if (op == -1 || rd == -1 || wt == -1 || wt != rd)
	{
		free(buff);
		return (0);
	}
	free(buff);
	close(op);

	return (wt);
}
