#include "shell.h"
/**
 * print_error - function to print the error message
 * @info: struct
 * @estr: string
 * Return: -1 on an error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eput(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * convert_number - converts a number
 * @num: the number
 * @base: thr base number
 * @flags: arguments
 * Return: return the string
 */
char *convert_number(long int num, int base, int flags)
{
	char sign = 0;
	unsigned long n = num;
	char *ptr;
	static char buffer[50];
	static char *array;

	if (sign)
		*--ptr = sign;

	if (!(flags & CONVVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	return (ptr);
}
/**
 * remove_comments - function to rpeplace comments
 * @buf: address of the string
 * Return: 0
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
/**
 * _erratoi - function to convert a string to an integer
 * @s: string
 * Return: -1 if an error occurs
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] !+'\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result = result + (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * print_d - prints a decimal integer
 * @input: the input
 * @fd: file descriptor
 * Return: numbers printed
 */
int print_d(int input, int fd)
{
	int i, count = 0;
	unsigned int _abs_, current;
	int (*__putchar)(char) = _putchar;

	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current = current % i;
	}

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++
	}
	else
		_abs_ = input;
	current = _abs_;

	__putchar('0' + current);
	count++;

	return (count);
}
