#include "shell.h"

/**
 * list_len - takes a pointer to the first node
 *            and returns the number of nodes in the list.
 *            It does this by traversing the list with a
 *            while loop and incrementing a counter for each node.
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_s *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings -  takes a pointer to the first node of a linked list
 *                    and returns an array of strings, where each string
 *                    corresponds to the str field of a node in the list.
 *                    It does this by first calling list_len to determine
 *                    the size of the array, and then iterating over the
 *                    list with a for loop, allocating memory for each
 *                    string with malloc, copying the string with _strcpy,
 *                    and storing the pointer to the string in the array.
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_s *head)
{
	list_s *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - takes a pointer to the first node of a linked list and
 *              prints the content of each node to the standard output.
 *              It does this by traversing the list with a while loop,
 *              calling _puts to print the numerical value of the node,
 *              a colon and a space, and the string value of the node.
 *              If the string value is null, it prints "(nil)" instead.
 * @h: a pointer to first node
 *
 * Return: list size
 */
size_t print_list(const list_s *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with -  takes a pointer to the first node of a linked list,
 *                     a prefix string, and a character.
 *                     It searches the list for the first node whose str
 *                     field starts with the prefix string and whose next
 *                     character is equal to the given character.
 *                     It does this by iterating over the list with a while
 *                     loop, calling starts_with to check if the str field
 *                     starts with the prefix, and checking if the next
 *                     character is equal to the given character.
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: a pointer to the matching node or null if no match is found.
 */
list_s *node_starts_with(list_s *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index -  takes a pointer to the first node of a linked list
 *                   and a pointer to a node in the list.
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: the index of the node in the list or -1
 *         if the node is not in the list.
 *         It does this by iterating over the list with a while loop,
 *         comparing each node to the given node pointer,
 *         and incrementing a counter until a match is found or the end
 *         of the list is reached.
 */
ssize_t get_node_index(list_s *head, list_s *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
