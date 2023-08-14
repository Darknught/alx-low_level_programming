#include <stdio.h>
#include <string.h>

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
 * my_file - get the current source file name using __FILE__ macro
 * Return: void
 */
void my_file(void)
{
	const char *file_prot = __FILE__;
	const char *base_name = strrchr(file_prot, '/');
	const char *file_to_match = "2-main.c";
	const char *character = file_prot;

	if (base_name != NULL)
	{
		file_prot = base_name + 1;
	}
	if (strcmp(file_prot, file_to_match) == 0)
	{
		while (*character != '\0')
		{
			putchar(*character);
			character++;
		}
		putchar('\n');
	}
}
