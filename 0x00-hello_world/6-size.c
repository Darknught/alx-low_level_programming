#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: 0 (success)
 *
 */
int main(void)
{
	printf("Size of a char: %lu byte(n)\n", sizeof(char));
	printf("Size of a int: %lu byte(n)\n", sizeof(int));
	printf("Size of a long int: %lu byte(n)\n", sizeof(long int));
	printf("Size of a long long int: %lu byte(n)\n", sizeof(long long int));
	printf("Size of a float: %lu byte(n)\n", sizeof(float));

	return (0);
}
