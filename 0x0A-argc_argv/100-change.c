#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints min number of coins to make change
 * @argc: argument count
 * @argv: argument
 * Return: 0
 */
int main(int argc, char **argv)
{
	int total, count;
	unsigned int y;
	char *p;
	int cent[] = {25, 10, 5, 2};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	total = strtol(argv[1], &p, 10);
	count = 0;

	if (!*p)
	{
		while (total > 1)
		{
			for (y = 0; y < sizeof(cent[y]); y++)
			{
				if (total >= cent[y])
				{
					count += total / cent[y];
					total = total % cent[y];
				}
			}
		}
		if (total == 1)
			count++;
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", count);
	return (0);
}
