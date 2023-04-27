#include "shell.h"
/**
 * _getenv - gets value of environment
 * @data: struct
 * @name: environments name
 * Return: 0 on success
 */
char *_getenv(data_t *data, const char *name)
{
	list_s *node = data->env;
	char *v;

	while (node)
	{
		v = starts_with(node->str, name);
		if (v && *v)
			return (v);
		node = node->next;
	}
	return (NULL);
}
/**
 * populate_env_list - environment linked list
 * @data: struct
 * Return: Always 0
 */
int populate_env_list(data_t *data)
{
	list_s *node = NULL;
	size_t e;

	for (e = 0; environ[e]; e++)
		add_node_end(&node, environ[e], 0);
		data->env = node;
		return (0);
}
/**
 * _myunsetenv - removes the environment
 * @data: struct
 * Return: 0
 */
int _myunsetenv(data_t *data)
{
	int t;

	if (data->argc == 1)
	{
		eputs("Too few arguments.\n");
		return (1);
	}
	for (t = 1; t <= data->argc; t++)
	_unsetenv(data, data->argv[t]);

	return (0);
}
/**
 * _myenv - function that prints the current environment
 * @data: struct
 * Return: 0
 */
int _myenv(data_t *data)
{
	print_list_str(data->env);
	return (0);
}
/**
 * _mysetenv - initializes a new environment
 * @data: struct
 * Return:0
 */
int _mysetenv(data_t *data)
{
	if (_setenv(data, data->argv[1], info->argv[2]))
		return (0);

	if (data->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}

	return (1);
}
