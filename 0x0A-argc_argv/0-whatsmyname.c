#include <stdlib.h>
#include <stdio.h>
/**
 * main - Entry point
 * @argc: argument to count
 * @argv: array of pointers
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int i;

	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	return (0);
}
