#include <stdlib.h>
#include <stdio.h>
/**
 * main - adds positive numbers
 * @argc: argument to count
 * @argv: argument
 * Return: 0
 */
int main(int argc, char **argv)
{
	int y, z, sum = 0;
	char *flag;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}

	for (y = 1; argv[y]; y++)
	{
		z = strtol(argv[y], &flag, 10);
		if (*flag)
		{
			printf("Error\n");
			return (1);
		}
		else
		{
			sum += z;
		}
	}
	printf("%d\n", sum);
	return (0);
}
