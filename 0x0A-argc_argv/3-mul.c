#include <stdlib.h>
#include <stdio.h>
/**
 * main - multiples two numbers
 * @argc: argument to count
 * @argv: argument
 * Return: 0, if no two arguments, 1
 */
int main(int argc, char **argv)
{
	int i, j;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	printf("%d\n", i * j);
	return (0);
}
