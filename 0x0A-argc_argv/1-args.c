#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints number of arguments passed into it
 * @argc: argument to count
 * @argv: argument passed
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}
