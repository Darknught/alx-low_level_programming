#include <stdio.h>

/**
 * myOpenFunc - Apply the constructor attribute to myOpenFunc()
 */
void myOpenFunc(void) __attribute__ ((constructor));


/**
 * myOpenFunc - implentation of the function
 */
void myOpenFunc(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
