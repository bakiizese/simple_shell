#include "shell.h"
/**
 * cls_inf - entry
 * @inf: var
 */
void cls_inf(inf_o *inf)
{
	inf->arg = NULL;
	inf->argv = NULL;
	inf->path = NULL;
	inf->argc = 0;
}
/**
 * st_inf - entry
 * @inf: var
 * @v: var
 */
void st_inf(inf_o *inf, char **v)
{
	int i = 0;

	inf->fn = v[0];
	if (inf->arg)
	{
		inf->argv = strtok1(inf->arg, " \t");
		if (!inf->argv)
		{

			inf->argv = malloc(sizeof(char *) * 2);
			if (inf->argv)
			{
				inf->argv[0] = _strdup(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for (i = 0; inf->argv && inf->argv[i]; i++)
			;
		inf->argc = i;

		re_alias(inf);
		re_vars(inf);
	}
}
/**
 * fr_inf - entry
 * @inf: var
 * @inf: l
 */
void fr_inf(inf_o *inf, int l)
{
	ffr(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
	if (l)
	{
		if (!inf->cmdb)
			free(inf->arg);
		if (inf->env)
			fr_list(&(inf->env));
		if (inf->hist)
			fr_list(&(inf->hist));
		if (inf->alias)
			fr_list(&(inf->alias));
		ffr(inf->environ);
			inf->environ = NULL;
		bfr((void **)inf->cmdb);
		if (inf->readfd > 2)
			close(inf->readfd);
		_putchar(BUFSH);
	}
}
/**
 * bfr - entry
 * @p: var
 * Return: 0
 */
int bfr(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
