#include "shell.h"
/**
 * _unsetenv - functions to unset the environment
 * @info: struct
 * @var: var property
 * Return: 0
 */
int _unsetenv(info_t *info, char *var)
{
	char *p;
	list_t *node = info->env;
	size_t i = 0;

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}

	if (!node || !var)
		return (0);

	return (info->env_changed);
}

/**
 * get_environ - function to get the environment
 * @info: struct
 * Return: 0
 */
char **get_environ(info_t *info)
{
	while (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}
/**
 * _setenv - function to set up the environment
 * @info: struct
 * @var: var property
 * @value: environment valueue
 * Return: 0
 */
int _setenv(info *info, char *var, char *value)
{
	char *buf = NULL;
	char *p;
	list_t *node;

	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
