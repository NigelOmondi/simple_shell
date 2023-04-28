#include "shell.h"
/**
 * free_info - frees info_t
 * @info: struct
 * @all: true if freeing all
 */

void free_info(info_t *info, int all)
{
	info->path = NULL;
	info->argv = NULL;
	ffree(info->argv);
	if (all)
	{
		if (info->env)
			free_list(&(info->env));
		if (!info->cmd_buf)
			free(info->arg);
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ)
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
/**
 * clear_info - function to initialize info_t
 * @info: struct
 */
void clear_info(info_t *info)
{
	info->path = NULL;
	info->arg = NULL;
	info->argv = NULL;
	info->argc = 0;
}
/**
 * set_info - function to initialize info_t
 * @info: struct
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->argv)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->argv);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}
