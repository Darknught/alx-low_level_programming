#include "main.h"
/**
 * _print - moves a string and prints the string
 * @str: string
 * @l: size of string
 * Return: void
 */
void _print(char *str, int l)
{
	int x, y;

	x = y = 0;
	while (x < l)
	{
		if (str[x] != '\0')
			y = 1;
		if (y || x == l - 1)
			_putchar(str[x]);
		x++;
	}
	_putchar('\n');
	free(str);
}

/**
 * mul - multiplies a char with a string giving the answer to dest
 * @n: char
 * @num1: string to multiply
 * @num_index: index of num
 * @dest: destination of multiplication
 * @dest_index: highest index to start
 * Return: pointer to dest
 */
char *mul(char n, char *num1, int num_index, char *dest, int dest_index)
{
	int i, j, mul, rem, add, addrem;

	rem = addrem = 0;
	for (i = num_index, j = dest_index; i >= 0; i--, j--)
	{
		mul = (n - '0') * (num1[i] - '0') + rem;
		rem = mul / 10;
		add = (dest[j] - '0') + (mul % 10) + addrem;
		addrem = add / 10;
		dest[j] = add % 10 + '0';
	}
	for (addrem += rem; j >= 0 && addrem; j--)
	{
		add = (dest[j] - '0') + addrem;
		addrem = add / 10;
		dest[j] = add % 10 + '0';
	}
	if (addrem)
	{
		return (NULL);
	}
	return (dest);
}
/**
 * check_digits - checks for digit arguments
 * @av: pointer
 * Return: 0 or 1
 */
int check_digits(char **av)
{
	int m, n;

	for (m = 1; m < 3; m++)
	{
		for (n = 0; av[m][n]; n++)
		{
			if (av[m][n] < '0' || av[m][n] > '9')
				return (1);
		}
	}
	return (0);
}

/**
 * init - initializes a string
 * @str: string
 * @len: length
 * Return: void
 */
void init(char *str, int len)
{
	int i;

	for (i = 0; i < len; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - multiplies two numbers
 * @argc: argument to count
 * @argv: argument vector
 * Return: 0 or exit status of 98 if failure
 */
int main(int argc, char *argv[])
{
	int len1, len2, len0, hi, i;
	char *a;
	char *p;
	char b[] = "Error\n";

	if (argc != 3 || check_digits(argv))
	{
		for (hi = 0; b[hi]; hi++)
			_putchar(b[hi]);
		exit(98);
	}
	for (len1 = 0; argv[1][len1]; len1++)
		;
	for (len2 = 0; argv[2][len2]; len2++)
		;
	len0 = len1 + len2 + 1;
	a = malloc(len0 * sizeof(char));
	if (a == NULL)
	{
		for (hi = 0; b[hi]; hi++)
			_putchar(b[hi]);
		exit(98);
	}
	init(a, len0 - 1);
	for (hi = len2 - 1, i = 0; hi >= 0; hi--, i++)
	{
		p = mul(argv[2][hi], argv[1], len1 - 1, a, (len0 - 2) - i);
		if (p == NULL)
		{
			for (hi = 0; b[hi]; hi++)
				_putchar(b[hi]);
			free(a);
			exit(98);
		}
	}
	_print(a, len0 - 1);
	return (0);
}
