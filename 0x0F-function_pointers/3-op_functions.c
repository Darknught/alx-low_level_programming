#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * op_add - add two parameters
 * @a: first parameter
 * @b: second parameter
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two parameters
 * @a: first parameter
 * @b: second parameter
 * Return: difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two parameters
 * @a: first parameter
 * @b: second parameter
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - devides two parameters
 * @a: first parameter
 * @b: second parameter
 * Return: result of the division of a and b
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - gets the remainder of two parameters
 * @a: first parameter
 * @b: second parameter
 * Return: the remainder of the division a by b
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
