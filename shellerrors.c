#include "shell.h"
/**
 * _putsfd - function to print an input
 * @str: string
 * @fd: filedecriptor
 * Return: the number of inputs
 */
int _putsfd(char *str, int fd)
{
	int b = 0;

	while (*str)
	{
		b = b + _putfd(*str++, fd);
	}

	if (!str)
		return (0);

	return (b);
}
/**
 * _eputchar - writes character to stderr
 *@c: character
 *Return: 1 on success
 */
int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int b;

	if (c != BUF_FLUSH)
		buf[b++] = c;

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, buf, b);
		b = 0;
	}

	return (1);
}
/**
 * _eputs - function to print an input srting
 * @str: string
 * Return: 0
 */
void _eputs(char *str)
{
	int b = 0;

	while (str[b] != '\0')
	{
		_eputchar(str[b]);
		b++;
	}

	if (!str)
		return;
}
/**
 * _putfd - write character to filedescriptor
 * @fd: file descriptor
 * @c: the character
 * Return: on success,1
 */
int _putfd(char c, int fd)
{
	static char buf[WRITE_BUF_SIZE];
	static int b;

	if (c != BUF_FLUSH)
		buf[b++] = c;

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(fd, buf, b);
		b = 0;
	}

	return (1);
}

