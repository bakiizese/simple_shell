#include "shell.h"
/**
 * genvn - entry
 * @inf: var
 * Return: 0
 */
char **genvn(inf_o *inf)
{
	if (!inf->environ || inf->env_ch)
	{
		inf->environ = l_to_s(inf->env);
		inf->env_ch = 0;
	}

	return (inf->environ);
}
/**
 * _unsetenv - entry
 * @inf: var
 * @l: var
 * Return: 0
 */
int _unsetenv(inf_o *inf, char *l)
{
	lists_t *n = inf->env;
	size_t i = 0;
	char *k;

	if (!n || !l)
		return (0);

	while (n)
	{
		k = st_wi(n->str, l);
		if (k && *k == '=')
		{
			inf->env_ch = delete_node_at_i(&(inf->env), i);
			i = 0;
			n = inf->env;
			continue;
		}
		n = n->next;
		i++;
	}
	return (inf->env_ch);
}
/**
 * stenv - entry
 * @inf: var
 * @l: var
 * @i: var
 * Return: 0
 */
int stenv(inf_o *inf, char *l, char *i)
{
	char *b = NULL;
	lists_t *n;
	char *k;

	if (!l || !i)
		return (0);

	b = malloc(_strlen(l) + _strlen(i) + 2);
	if (!b)
		return (1);
	_strcpy(b, l);
	_strcat(b, "=");
	_strcat(b, i);
	n = inf->env;
	while (n)
	{
		k = st_wi(n->str, l);
		if (k && *k == '=')
		{
			free(n->str);
			n->str = b;
			inf->env_ch = 1;
			return (0);
		}
		n = n->next;
	}
	add_node_end(&(inf->env), b, 0);
	free(b);
	inf->env_ch = 1;
	return (0);
}
