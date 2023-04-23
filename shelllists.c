#include "shell.h"

/**
 * add_node - This function adds a new node
 *            to the start of the linked list
 * @head: a pointer to a pointer to the head node of the list.
 * @str: a pointer to a string that will be associated with new node
 *       (or NULL if no string is associated with the node)
 * @num:  a integer value used as an index used by history
 *
 * Return: the list size
 */
list_s *add_node(list_s **head, const char *str, int num)
{
	list_s *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_s));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_s));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a new node to the end of the linked list
 * @head: a pointer to a pointer to the head node of the list.
 * @str:  a pointer to a string that will be associated with new node
 *       (or NULL if no string is associated with the node)
 * @num: a integer value used as an index used by history
 *
 * Return: list size
 */
list_s *add_node_end(list_s **head, const char *str, int num)
{
	list_s *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_s));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_s));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - prints the string associated with each node
 *                  in the linked list list_s
 * @h: a pointer to first node in the list
 *
 * Return: list size
 */
size_t print_list_str(const list_s *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes a node from the linked list
 *                        at a specified index
 * @head: a pointer to a pointer to the head node of the list.
 * @index:  the index of the node to be deleted.
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_s **head, unsigned int index)
{
	list_s *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees the memory allocated for all nodes in the linked list
 * @head_ptr:  a pointer to a pointer to the head node of the list.
 *
 * Return: void
 */
void free_list(list_s **head_ptr)
{
	list_s *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
