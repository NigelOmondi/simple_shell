#include "shell.h"
/**
 * _putsfd - function to print an input
 * @str: string
 * @fd: filedecriptor
 * Return: the number of inputs
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	while (*str)
	{
		i = i + _putfd(*str++, fd);
	}

	if (!str)
		return (0);

	return (i);
}
/**
 * _eputchar - writes character to stderr
 *@c: character
 *Return: 1 on success
 */
int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c != BUF_FLUSH)
		buf[i++] = c;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
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
	int i = 0;

	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
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
	static int i;

	if (c != BUF_FLUSH)
		buf[i++] = c;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}

	return (1);
}

