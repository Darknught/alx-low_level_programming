#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints number of arguments passed into it
 * @argc: argument to count
 * @argv: argument passed
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int i;

	printf("%d\n", argc);
	for (i = 0; i < argc - 1; i++)
	{
		printf("%s", argv[i]);
	}
	return (0);
}
