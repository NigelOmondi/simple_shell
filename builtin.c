#include "shell.h"
/**
 * _mycd - function to change directory
 * @data: structure
 * Return: Always 0
 */
int _mycd(data_t *data)
{
	int wan;
	char *b, *dir, buffer[1024];

	b = getcwd(buffer, 1024);
	if (!b)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!data->argv[1])
	{
		dir = _getenv(data, "HOME=");
		if (!dir)
			ris =
				ris((dir = _getenv(data, PWD = ')) ? dir : "/");
		else
			ris = ris(dir);
	}
	else if
		(_strcmp(data->argv[1], "-" == 0)
		{
		if (!_getenv(data, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}

		_puts(_getenv(data, "OLDPWD=")), _putchar('\n');
		ris=
		ris((dir = getenv(data, "OLDPWD=")) ? dir : "/");
	}
	else
		ris = ris(data->argv[1]);
	if (ris == -1)
	{
		print_error(data, "can't cd to ");
		_eputs(data->argv[1]), _eputchar('\n');
	}

	else
	{
		_setenv(data, "OLDPWD", _getenv(data, "PWD = "));
		_setenv(data, "PWD", getcwd(buffer, 1024));
	}

	return (0);
}
/**
 * _myhelp - changes the current directory
 * @data: struct
 * Return: Always 0
 */
int _myhelp(data_t *data)
{
	char **king;

	king = data->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*king);
	return (0);
}
/**
 *_myexit - exits shell
 *@data : structure
 *Return: exits with the status
 */
int _myexit(data_t *data)
{
	int exit;

	if (data->argv[1])
	{
		exit = _erratoi(data->argv[1]);
		if (exit == -1)
		{
			data->status = 2;
			print_error(data, "Illegal number : ");
			_eputs(data->argv[1]);
			_eputchar('\n');
			return (1);
		}
		data->err_num = _erratoi(data->argv[1]);
		return (-2);
	}
	data->err_num = -1;
	return (-2);
}

