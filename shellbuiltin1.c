#include "shell.h"
/**
 * unset_alias - function to set alias
 * @info: struct
 * @str: string
 * Return: On success, 0
 */
int unset_alias(info_t *info, char *str)
{
	int ret;
	char *p, c;

	p = _strchr(str, '=');
	if (!p)
		return (1);

	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}
/**
 * _myalias - copies the alias
 * @info: struct
 * Return: 0, if successful
 */
int _myalias(info_t *info)
{
	char *p = NULL;
	list_t *node = NULL;
	int i = 0;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i];
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
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
 * @info: struct
 * Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * set_alias - sets alias
 * @info: struct
 * @str: string
 * Return: on success,0
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

