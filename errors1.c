#include "shell.h"
int erratoi(char *s)
{
	int i;
	unsigned long int result = 0;

	if (*s == '+')
		s++;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}

	return (result);
}
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
int print_d(int input, int fd)
{
	int (*putchar_func)(char) = _putchar;
	int i, count = 0;
	unsigned int abs_value, current;

	if (fd == STDERR_FILENO)
		putchar_func = _eputchar;

	if (input < 0)
	{
		abs_value = -input;
		putchar_func('-');
		count++;
	}
	else
		abs_value = input;

	current = abs_value;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abs_value / i)
		{
			putchar_func('0' + current / i);
			count++;
		}
		current %= i;
	}
	putchar_func('0' + current);
	count++;

	return (count);
}
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

