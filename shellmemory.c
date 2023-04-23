#include "shell.h"

/**
 * bfree - free the memory that is being pointed to by the pointer passed in,
 *         and set the pointer itself to NULL
 *         to prevent it from being used again.
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
