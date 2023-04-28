#include "shell.h"
/**
 * input_buf - function to buffer the chained commands
 * @info: struct
 * @buf: buffer
 * @len: address of the variable length
 * Return: the bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buff = NULL;
		signal(SIGINT, sigintHandler);

#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);

			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}
/**
 * sigintHandler -function to block the control c function
 * @sig_num: signal  number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
/**
 * read_buf - function to read a buffer
 * @info: struct
 * @buf: the buffer
 * @i: the size
 * Return: the variable of reading a buffer
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (r >= 0)
		*i = r;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);

	return (r);
}
/**
 * get_input - function to get an input
 * @info: struct
 * Return: the function should return the bytes read
 */
ssize_t get_input(info_t *info)
{
	static size_t i, j, len;
	static char *buf;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);

	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		**buf_p = p;
		return (_strlen(p));
	}

	if (r == -1)
		return (-1);

	*buf_p = buf;
	return (r);
}
/**
 * _getline - function to get the next line of input
 * @info: struct
 * @ptr: the address of the pointer
 * @length: the size
 * Return: the value
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	size_t k;
	ssize_t r = 0, s = 0;
	static char buf[READ_BUF_SIZE];
	char *p = NULL, *new_p = NULL, *c;
	static size_t i, len;

	k = c ? 1 + (unsigned int)(c - buf) : len;
	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	c = _strchr(buf + i, '\n');
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	i = k;
	p = new_p;
	s += k - ei

	if (length)
		*length = s;

	*ptr = p;
	return (s);
}
