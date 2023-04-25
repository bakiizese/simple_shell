#include "shell.h"
/**
 * l_len - struct
 * @head: struct
 * Return: j
 */
size_t l_len(const lists_t *head)
{
	size_t j = 0;

	while (head)
	{
		head = head->next;
		j++;
	}
	return (j);
}
/**
 * l_to_s - func
 * @head: struct
 * Return: tr
 */
char **l_to_s(lists_t *head)
{
	lists_t *n = head;
	size_t i = l_len(head), k;
	char **tr;
	char *st;

	if (!head || !i)
		return (NULL);
	tr = malloc(sizeof(char *) * (i + 1));
	if (!tr)
		return (NULL);
	for (i = 0; n; n = n->next, i++)
	{
		st = malloc(_strlen(n->str) + 1);
		if (!st)
		{
			for (k = 0; k < i; k++)
				free(tr[i]);
			free(tr);
			return (NULL);
		}

		st = _strcpy(st, n->str);
		tr[i] = st;
	}
	tr[i] = NULL;
	return (tr);
}
/**
 * p_list - struct
 * @head: struct
 * Return: j
 */
size_t p_list(const lists_t *head)
{
	size_t j = 0;

	while (head)
	{
		_puts(conv_n(head->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		j++;
	}
	return (j);
}
/**
 * node_starts_with - func
 * @n: struct
 * @pre: char var
 * @c: char var
 * Return: NULL
 */
lists_t *node_starts_with(lists_t *n, char *pre, char c)
{
	char *p = NULL;

	while (n)
	{
		p = st_wi(n->str, pre);
		if (p && ((c == -1) || (*p == c)))
			return (n);
		n = n->next;
	}
	return (NULL);
}
/**
 * get_node_i - struct
 * @head: struct
 * @n: struct
 * Return: -1
 */
ssize_t get_node_i(lists_t *head, lists_t *n)
{
	size_t j = 0;

	while (head)
	{
		if (head == n)
			return (j);
		head = head->next;
		j++;
	}
	return (-1);
}
