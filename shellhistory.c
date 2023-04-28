#include "shell.h"
/**
 * renumber_history - function to renumber the history
 * @info: struct
 * Return: the new number
 */
int renumber_history(info_t *info)
{
	int i = 0;
	list_t *node = info->history;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
/**
 * get_history_file -functions that gets the history of the file
 * @info: struct
 *Return: history file
 */
char *get_history_file(info_t *info)
{
	char *buf, *dir;

	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);

	dir = _getenv(info, "HOME=");
	if (!dir)
	return (NULL);
}
/**
 * build_history_list - function to build the history list
 * @info: struct
 * @buf: buffer
 * @linecount: the linecountcount
 * Return: 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (!info->history)
		info->history = node;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	return (0);
}
/**
 * write_history - function to write history
 * @info: the struct
 * Return: on success, 1.
 */
int write_history(info_t *info)
{
	ssize_t fd;
	list_t *node = NULL;
	char *filename = get_history_file(info);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	for (node = info->history; node; node = node->next)
	{
		_putfd('\n', fd);
		_putsfd(node->str, fd)
	}

	if (fd == -1)
		return (-1);
	if (!filename)
		return (-1);

	_putfd(BUF_FLUSH, fd);
	close(fd);
		return (1);
}
/**
 * read_history - function to read  the history
 * @info: struct
 * Return: 0 if unsuccessful
 */
int read_history(info_t *info)
{
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	int i, last = 0, linecount = 0;
	char *buf = NULL, *filename = get_history_file(info);

	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;

	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);

	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);

	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);

	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
