#include "shell.h"
/**
 * print_error - function to print the error message
 * @data: struct
 * @estr: string
 * Return: -1 on an error
 */
void print_error(data_t *data, char *estr)
{
	_eputs(data->fname);
	_eput(": ");
	print_d(data->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(data->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * convert_number - converts a number
 * @number: the number
 * @base: thr base number
 * @flags: arguments
 * Return: return the string
 */
char *convert_number(long int number, int base, int flags)
{
	char sign = 0;
	unsigned long n = number;
	char *ptr;
	static char buffer[50];
	static char *array;

	if (sign)
		*--ptr = sign;

	if (!(flags & CONVVERT_UNSIGNED) && number < 0)
	{
		n = -number;
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
	int c;

	for (c = 0; buf[c] != '\0'; c++)
		if (buf[c] == '#' && (!c || buf[c - 1] == ' '))
		{
			buf[c] = '\0';
			break;
		}
}
/**
 * _erratoi - function to convert a string to an integer
 * @d: string
 * Return: -1 if an error occurs
 */
int _erratoi(char *d)
{
	int c = 0;
	unsigned long int ris = 0;

	if (*d == '+')
		s++;
	for (c = 0; d[c] !+'\0'; c++)
	{
		if (d[c] >= '0' && d[c] <= '9')
		{
			res *= 10;
			res = res + (d[c] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
/**
 * print_d - prints a decimal integer
 * @input: the input
 * @fd: file descriptor
 * Return: numbers printed
 */
int print_d(int input, int fd)
{
	int c, count = 0;
	unsigned int uhu, wan;
	int (*__putchar)(char) = _putchar;

	for (c = 1000000000; c > 1; c /= 10)
	{
		if (uhu / c)
		{
			__putchar('0' + wan / c);
			count++;
		}
		wan = wan % c;
	}

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		uhu = -input;
		__putchar('-');
		count++
	}
	else
		uhu = input;
	wan = uhu;

	__putchar('0' + wan);
	count++;

	return (count);
}
