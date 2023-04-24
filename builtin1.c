#include "shell.h"
/**
 * unset_alias - function to set alias
 * @data: struct
 * @str: string
 * Return: On success, 0
 */
int unset_alias(data_t *data, char *str)
{
	int bro;
	char *v, b;

	v = _strchr(str, '=');
	if (!v)
		return (1);

	b = *v;
	*v = 0;
	bro = delete_node_at_index(&(data->alias),
		get_node_index(data->alias, node_starts_with(data->alias, str, -1)));
	*v = b;
	return (bro);
}
/**
 * _myalias - copies the alias
 * @data: struct
 * Return: 0, if successful
 */
int _myalias(data_t *data)
{
	char *v = NULL;
	data_t *node = NULL;
	int r = 0;

	if (data->argv == 1)
	{
		node = data->alias;
			while (node)
			{
				print_alias(node);
				node = node->next;
			}
			return (0);
	}

	for (r = 1; data->argv[r]; r++)
	{
		v = _strchr(data->argv[r], '=');
		if (v)
			set_alias(data, data->argv[r];
		else
			print_alias(node_starts_with(data->alias, data->argv[r], '='));
	}
	return (0);
}
/**
 * print_alias - prints an alias
 * @node: the node
 * Return: If successful,0
 */
int print_alias(list_s *node)
{
	char *v = NULL, *a = NULL;

	if (node)
	{
		v = strchr(node->str, '=');
		for (a == node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(v + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myhistory - displays history
 * @data: struct
 * Return: 0
 */
int _myhistory(data_t *data)
{
	print_list(data->history);
	return (0);
}
/**
 * set_alias - sets alias
 * @data: struct
 * @str: string
 * Return: on success,0
 */
int set_alias(data_t *data, char *str)
{
	char *v;

	v = _strchr(str, '=');
	if (!v)
		return (1);
	if (!*++v)
		return (unset_alias(data, str));
	unset_alias(data, str);
	return (add_node_end(&(data->alias), str, 0) == NULL);
}





