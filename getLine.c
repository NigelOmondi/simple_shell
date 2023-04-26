#include "shell.h"
/**
 * input_buf - function to buffer the chained commands
 * @data: struct
 * @buf: buffer
 * @length: address of the variable length
 * Return: the bytes
 */
ssize_t input_buf(data_t *data, char **buf, size_t *length)
{
	ssize_t a = 0;
	size_t length_r = 0;

	if (!*length)
	{
		free(*buf);
		*buff = NULL;
		signal(SIGINT, sigintHandler);

#if USE_GETLINE
		a = getline(buf, &length_r, stdin);
#else
		a = _getline(data, buf, &length_r);
#endif
	if (a > 0)
	{
		if ((*buf)[a - 1] == '\n')
		{
			(*buf)[a - 1] = '\0';
			a--;
		}
		data->linecount_flag = 1;
		remove_comments(*buf);
		build_history_list(data, *buf, data->histcount++);

		{
			*length = a;
			data->cmd_buf = buf;
		}
	}
	}
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
 * @data: struct
 * @buf: the buffer
 * @a: the size
 * Return: the variable of reading a buffer
 */
ssize_t read_buf(data_t *data, char *buf, size_t *a)
{
	ssize_t c = 0;

	if (c >= 0)
		*a = c;

	if (*a)
		return (0);
	c = read(data->readfd, buf, READ_BUF_SIZE);

	return (c);
}
/**
 * get_input - function to get an input
 * @data: struct
 * Return: the function should return the bytes read
 */
ssize_t get_input(data_t *data)
{
	static size_t a, b, length;
	static char *buf;
	ssize_t c = 0;
	char **buf_r = &(data->argv), *r;

	_putchar(BUF_FLUSH);
	p = input_buf(data, &buf, &length);

	if (length)
	{
		b = a;
		r = buf + a;

		check_chain(data, buf, &b, a, length);
		while (b < length)
		{
			if (is_chain(data, buf, &b))
				break;
			b++;
		}
		a = b + 1;
		if (a >= length)
		{
			a = length = 0;
			data->cmd_buf_type = CMD_NORM;
		}

		*buf_r = r;
		return (_strlen(r));
	}

	if (p == -1)
		return (-1);

	*buf_p = buf;
	return (p);
}
/**
 * _getline - function to get the next line of input
 * @data: struct
 * @ptr: the address of the pointer
 * @len: the size
 * Return: the value
 */
int _getline(data_t *data, char **ptr, size_t *len)
{
	size_t a;
	ssize_t b = 0, c = 0;
	static char buf[READ_BUF_SIZE];
	char *p = NULL, *new_p = NULL, *d;
	static size_t e, length;

	a = d ? 1 + (unsigned int)(d - buf) : length;
	b = read_buf(data, buf, &length);
	if (b == -1 || (b == 0 && length == 0))
		return (-1);

	p = *ptr;
	if (p && len)
		c = *len;
	if (e == length)
		e = length = 0;

	d = _strchr(buf + e, '\n');
	new_p = _realloc(p, c, c ? c + a : a + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (b)
		_strncat(new_p, buf + e, a - e);
	else
		_strncpy(new_p, buf + e, a - e + 1);

	e = a;
	p = new_p;
	c += a - e;

	if (len)
		*len = c;

	*ptr = p;
	return (c);
}
