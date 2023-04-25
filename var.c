/*
 * File: var
 * Auth: Bereket Zeselassie
 *       Mahder Gebremikael
 */

#include "shell.h"

int ischain(inf_o *inf, char *b, size_t *p)
{
	size_t i = *p;

	if (b[i] == '|' && b[i + 1] == '|')
	{
		b[i] = 0;
		i++;
		inf->cmdb_type = OR;
	}
	else if (b[i] == '&' && b[i + 1] == '&')
	{
		b[i] = 0;
		i++;
		inf->cmdb_type = AND;
	}
	else if (b[i] == ';')
	{
		b[i] = 0;
		inf->cmdb_type = CHAIN;
	}
	else
		return (0);
	*p = i;
	return (1);
}

void chchain(inf_o *inf, char *b, size_t *p, size_t i, size_t l)
{
	size_t k = *p;

	if (inf->cmdb_type == AND)
	{
		if (inf->stat)
		{
			b[i] = 0;
			k = l;
		}
	}
	if (inf->cmdb_type == OR)
	{
		if (!inf->stat)
		{
			b[i] = 0;
			k = l;
		}
	}

	*p = k;
}

int re_alias(inf_o *inf)
{
	int j = 0;
	lists_t *n;
	char *p;

	for (j = 0; j < 10; j++)
	{
		n = node_starts_with(inf->alias, inf->argv[0], '=');
		if (!n)
			return (0);
		free(inf->argv[0]);
		p = _strchr(n->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		inf->argv[0] = p;
	}
	return (1);
}

int re_vars(inf_o *inf)
{
	int i = 0;
	lists_t *n;

	for (i = 0; inf->argv[i]; i++)
	{
		if (inf->argv[i][0] != '$' || !inf->argv[i][1])
			continue;

		if (!_strcmp(inf->argv[i], "$?"))
		{
			re_string(&(inf->argv[i]),
				_strdup(conv_n(inf->stat, 10, 0)));
			continue;
		}
		if (!_strcmp(inf->argv[i], "$$"))
		{
			re_string(&(inf->argv[i]),
				_strdup(conv_n(getpid(), 10, 0)));
			continue;
		}
		n = node_starts_with(inf->env, &inf->argv[i][1], '=');
		if (n)
		{
			re_string(&(inf->argv[i]),
				_strdup(_strchr(n->str, '=') + 1));
			continue;
		}
		re_string(&inf->argv[i], _strdup(""));
	}
	return (0);
}

int re_string(char **o, char *n)
{
	free(*o);
	*o = n;
	return (1);
}
