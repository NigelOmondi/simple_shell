#include "shell.h"
/**
 * is_delim - function for checking if its a delimeter
 * @c: character
 * @delim: string
 * Return: 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _atoi - function that converts a string to an integer
 * @s: string
 * Return: 0 if no number is converted to a string
 */
int _atoi(char *s)
{
	unsigned int result = 0;
	int i, sign = 1, flag = 0, output;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}


	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
/**
 * _isalpha - function to check an alphabet
 * @c: the character
 * Return: 0 if not an alphabet
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * interactive - check if shell is interactive mode
 * @info: struct address
 * Return: 0 if it is not in interactive mode
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}



