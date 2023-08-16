#include <stdlib.h>
#include <stdio.h>
/**
 * print_opcodes - prints the opcodes of the program
 * @a: address of main
 * @n: number of bytes
 * Return: void
 */
void print_opcodes(char *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%.2hhx", a[i]);
		if (i < n - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * main - prints opcodes of its own main
 * @argc: argument to count
 * @argv: array of pointers to arguments
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	int x;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	x = atoi(argv[1]);
	if (x < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes((char *)&main, x);
	return (0);
}
