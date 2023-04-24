#include "shell.h"
/**
 * free_info - frees data_t
 * @data: struct
 * @all: true if freeing all
 */

void free_info(data_t *data, int all)
{
	data->path = NULL;
	data->argv = NULL;
	ffree(data->argv);
	if (all)
	{
		if (data->env)
			free_list(&(data->env));
		if (data->cmd_buf)
			free(data->arg);
		if (data->history)
			free_list(&(data->history));
		if (data->alias)
			free_list(&(data->alias));
		ffree(data->environ)
			data->environ = NULL;
		bfree((void **)data->cmd_buf);
		if (data->readfd > 2)
			close(data->readfd);
		_putchar(BUF_FLUSH);
	}
}
/**
 * clear_info - function to initialize data_t
 * @data: struct
 */
void clear_info(data_t *data)
{
	data->path = NULL;
	data->arg = NULL;
	info->argv = NULL;
	info->argc = 0;
}
/**
 * set_info - function to initialize data_t
 * @data: struct
 * @av: argument vector
 */
void set_info(data_t *data, char **av)
{
	int b = 0;

	data->fname = av[0];
	if (data->argv)
	{
		data->argv = strtow(info->arg, " \t");
		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = _strdup(data->argv);
				data->argv[1] = NULL;
			}
		}
		for (b = 0; data->argv && data->argv[b]; b++)
			;
		data->argc = b;

		replace_alias(data);
		replace_vars(data);
	}
}
