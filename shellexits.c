#include "shell.h"
/**
 * *_strncat - function to concatenate two strings
 * @str1: the first string
 * @str2: the second string
 * @n: number of bytes
 * Return: the full string
 */
char *_strncat(char *str1, char *str2, int n)
{
	int a, b;
	char *s = str1;

	a = 0;
	b = 0;

	if (b < n)
		str1[a] = '\0';

	while (str1[a] != '\0')
		a++;
	while (str2[b] != '\0' && b < n)
	{
		str1[a] = str2[b];
		a++;
		b++
	}
	return (s);
}
/**
 * *_strchr - function to locate a character
 * @a: parsed string
 * @b: character
 * Return: a pointer
 */
char *_strchr(char *a, char b)
{
	do {
		if (*a ==  b)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}
/**
 * *_strncpy - function to copy a string
 * @str1: destination string
 * @str2: source string
 * @n: number of characters
 * Return: copied string
 */
char *_strncpy(char *str1, char *str2, int n)
{
	int a, b;
	char *s = str1;

	a = 0;
	while (str2[a] != '\0' && a < n - 1)
	{
		str1[a] = str2[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			str1[b] = '\0';
			b++;
		}
	}
	return (s);
}
