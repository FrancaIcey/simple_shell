#include "main.h"

/**
 * add_numbers - A function that adds two numbers.
 * @a: First number to be added.
 * @b: Second number to be added.
 *
 * Return: Sum of two numbers
 */
int add_numbers(int a, int b)
{
	return (a + b);
}

/**
 * main - The entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	int num1, num2, sum;

	num1 = 8;
	num2 = 9;

	sum = add_numbers(num1, num2);

	printf("The sum of %d and %d is: %d\n", num1, num2, sum);

	return (0);
}
