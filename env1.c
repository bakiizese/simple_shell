#include "shell.h"
/**
 * menv - entry
 * @inf: var
 * Return: 0
 */
int menv(inf_o *inf)
{
	p_list_str(inf->env);
	return (0);
}
/**
 * genv - entry
 * @inf: var
 * @name: var
 * Return: NULL
 */
char *genv(inf_o *inf, const char *name)
{
	lists_t *n = inf->env;
	char *p;

	while (n)
	{
		p = st_wi(n->str, name);
		if (p && *p)
			return (p);
		n = n->next;
	}
	return (NULL);
}
/**
 * msetenv - entry
 * @inf: var
 * Return: 1
 */
int msetenv(inf_o *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (stenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}
/**
 * munsetenv - entry
 * @inf: var
 * Return: 0
 */
int munsetenv(inf_o *inf)
{
	int j = 1;

	if (inf->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	while (j <= inf->argc)
	{
		_unsetenv(inf, inf->argv[j]);
		j++;
	}

	return (0);
}
/**
 * penv - entry
 * @inf: var
 * Return: 0
 */
int penv_list(inf_o *inf)
{
	lists_t *n = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&n, environ[j], 0);
	inf->env = n;
	return (0);
}