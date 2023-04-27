#include "shell.h"
/**
 * renumber_history - function to renumber the history
 * @data: struct
 * Return: the new number
 */
int renumber_history(data_t *data)
{
	int a = 0;
	list_s *node = data->history;

	while (node)
	{
		node->num = a++;
		node = node->next;
	}
	return (data->histcount = a);
}
/**
 * get_history_file -functions that gets the history of the file
 * @data: struct
 *Return: history file
 */
char *get_history_file(data_t *data)
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

	dir = _getenv(data, "HOME=");
	if (!dir)
	return (NULL);
}
/**
 * build_history_list - function to build the history list
 * @data: struct
 * @buf: buffer
 * @line: the linecount
 * Return: 0
 */
int build_history_list(data_t *data, char *buf, int line)
{
	list_s *node = NULL;

	if (!data->history)
		data->history = node;

	if (data->history)
		node = data->history;
	add_node_end(&node, buf, line);

	return (0);
}
/**
 * write_history - function to write history
 * @data: the struct
 * Return: on success, 1.
 */
int write_history(data_t *data)
{
	ssize_t fd;
	list_s *node = NULL;
	char *filename = get_history_file(data);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	for (node = data->history; node; node = node->next)
	{
		putfd('\n', fd);
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
 * @data: struct
 * Return: 0 if unsuccessful
 */
int read_history(data_t *data)
{
	ssize_t fd, len, fsize = 0;
	struct stat st;
	int a, lastline = 0, line = 0;
	char *buf = NULL, *filename = get_history;

	if (last != a)
		build_history_list(data, buf + lastline, line++);
	free(buf);
	data->histcount = linecount;

	for (a = 0; a < fsize; a++)
		if (buf[a] == '\n')
		{
			buf[a] = 0;
			build_history_list(data, buf + lastline, line++);
			lastline = a + 1;
		}
	if (!filename)
		return (0);

	fd = open(filenmae, O_RDONLY);
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

	len = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (len <= 0)
		return (free(buf), 0);
	close(fd);
}
