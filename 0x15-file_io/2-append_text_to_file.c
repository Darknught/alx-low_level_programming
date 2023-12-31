#include "main.h"

/**
 * append_text_to_file - appends text at end of a file
 * @filename: the name of the file
 * @text_content: NULL terminating string to add to the end of the file
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int op, wt;
	int len;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	len = strlen(text_content);

	op = open(filename, O_WRONLY | O_APPEND);

	if (op == -1)
		return (-1);

	wt = write(op, text_content, len);

	close(op);

	if (wt == -1)
		return (-1);

	return (1);
}
