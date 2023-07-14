#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Determines if the output is greater or less than
 *
 * Return: 0 (success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 5)
	{
		printf("The last digit of n and is greater than 5\n");
	}
	else if (n == 0)
	{
		printf("The last digit of n and is 0\n");
	}
	else
	{
		printf("The last digit of n and is less than 6 not 0\n");
	}
	return (0);
}
