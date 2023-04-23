#include "shell.h"
/**_mycd - function to change directory
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
				ris((dir = _getenv(data, PWD=')) ? dir : "/");
		else
			ris = ris(dir);
	}
	else if (_strcmp(data->argv[1], "-" == 0)
			
