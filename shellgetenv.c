#include "shell.h"
/**
 * _unsetenv - functions to unset the environment
 * @data: struct
 * @var: var property
 * Return: 0
 */
int _unsetenv(data_t *data, char *var)
{
	char *c;
	list_s *node = data->env;
	size_t a = 0;

	while (node)
	{
		c = starts_with(node->str, var);
		if (c && *c == '=')
		{
			data->env_changed = delete_node_at_index(&(data->env), a);
			a = 0;
			node = data->env;
			continue;
		}
		node = node->next;
		a++;
	}

	if (!node || !var)
		return (0);

	return (data->env_changed);
}

/**
 * get_environ - function to get the environment
 * @data: struct
 * Return: 0
 */
char **get_environ(data_t *data)
{
	while (!data->environ || data->env_changed)
	{
		data->environ = list_to_strings(data->env);
		data->env_changed = 0;
	}
	return (data->environ);
}
/**
 * _setenv - function to set up the environment
 * @data: struct
 * @var: var property
 * @val: environment value
 * Return: 0
 */
int _setenv(data *data, char *var, char *val)
{
	char *buf = NULL;
	char *a;
	list_s *node;

	node = data->env;
	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			free(node->str);
			node->str = buf;
			data->env_changed = 1;
			return (0);
		}
		node = node->next;
	}

	if (!var || !val)
		return (0);

	buf = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buf)
		return (1);

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, val);
	add_node_end(&(data->env), buf, 0);
	free(buf);
	data->env_changed = 1;
	return (0);
}
