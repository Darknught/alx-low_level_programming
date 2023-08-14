#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void my_file(void);
/**
 * main - Entry point
 * Return: 0 (success)
 */
int main(void)
{
	my_file();
	return (0);
}

/**
 * myfile - get the current source file name using __FILE__ macro
 * Return: void
 */
void my_file(void)
{
	const char *file_prot = __FILE__;
	const char *base_name = strrchr(file_prot, '/');
	int fd = open(file_prot, O_RDONLY);
	char buffer[1];
	ssize_t result;

	if (base_name != NULL)
	{
		file_prot = base_name + 1;
	}
	if (strcmp(file_prot, "2-main.c") == 0)
	{
		if (fd != -1)
		{
			while ((result = read(fd, buffer, sizeof(buffer))) > 0)
			{
				write(STDOUT_FILENO, buffer, result);
			}
			write(STDOUT_FILENO, "\n", 1);
			close(fd);
		}
	}
}
