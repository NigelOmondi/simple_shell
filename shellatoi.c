#include "shell.h"
/**
 * is_delim - function for checking if its a delimeter
 * @d: character
 * @delim: string
 * Return: 0 if false
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 * _atoi - function that converts a string to an integer
 * @c: string
 * Return: 0 if no number is converted to a string
 */
int _atoi(char *c)
{
	unsigned int ris = 0;
	int a, sign = 1, flag = 0, output;

	for (a = 0; c[a] != '\0' && flag != 2; a++)
	{
		if (c[a] == '-')
			sign *= -1;

		if (c[a] >= '0' && c[a] <= '9')
		{
			flag = 1;
			ris *= 10;
			ris += (c[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}


	if (sign == -1)
		output = -ris;
	else
		output = ris;

	return (output);
}
/**
 * _isalpha - function to check an alphabet
 * @s: the character
 * Return: 0 if not an alphabet
 */
int _isalpha(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * interactive - check if shell is interactive mode
 * @data: struct address
 * Return: 0 if it is not in interactive mode
 */
int interactive(data_t *data)
{
	return (isatty(STDIN_FILENO) && data->readfd <= 2);
}



