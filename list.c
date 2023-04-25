/*
 * File: list
 * Auth: Bereket Zeselassie
 *       Mahder Gebremikael
 */

#include "shell.h"

lists_t *add_node(lists_t **h, const char *str, int n)
{
	lists_t *new;

	if (!h)
		return (NULL);
	new = malloc(sizeof(lists_t));
	if (!new)
		return (NULL);
	memset((void *)new, 0, sizeof(lists_t));
	new->n = n;
	if (str)
	{
		new->str = _strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	new->next = *h;
	*h = new;
	return (new);
}

lists_t *add_node_end(lists_t **h, const char *str, int n)
{
	lists_t *new, *on;

	if (!h)
		return (NULL);

	on = *h;
	new = malloc(sizeof(lists_t));
	if (!new)
		return (NULL);
	memset((void *)new, 0, sizeof(lists_t));
	new->n = n;
	if (str)
	{
		new->str = _strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	if (on)
	{
		while (on->next)
			on = on->next;
		on->next = new;
	}
	else
		*h = new;
	return (new);
}

size_t p_list_str(const lists_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	
	return (j);
}

int delete_node_at_i(lists_t **h, unsigned int i)
{
	lists_t *n, *old;
	unsigned int j = 0;

	if (!h || !*h)
		return (0);

	if (!i)
	{
		n = *h;
		*h = (*h)->next;
		free(n->str);
		free(n);
		return (1);
	}
	n = *h;
	while (n)
	{
		if (j == i)
		{
			old->next = n->next;
			free(n->str);
			free(n);
			return (1);
		}
		i++;
		old = n;
		n = n->next;
	}
	return (0);
}

void fr_list(lists_t **h_ptr)
{
	lists_t *n, *h, *new;

	if (!*h_ptr || !h_ptr)
		return;
	h = *h_ptr;
	n = h;
	while (n)
	{
		new = n->next;
		free(n->str);
		free(n);
		n = new;
	}
	*h_ptr = NULL;
}
