#include "shell.h"
/**
 * *_strncat - function to concatenate two strings
 * @dest: the first string
 * @src: the second string
 * @n: number of bytes
 * Return: the full string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;

	if (j < n)
		dest[i] = '\0';

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++
	}
	return (s);
}
/**
 * *_strchr - function to locate a character
 * @s: parsed string
 * @c: character
 * Return: a pointer
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s ==  c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
/**
 * *_strncpy - function to copy a string
 * @dest: destination string
 * @src: source string
 * @n: number of characters
 * Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
