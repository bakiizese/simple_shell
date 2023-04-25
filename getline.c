#include "shell.h"
/**
 * in_buf - func
 * @inf: struct
 * @b: char var
 * @l: var
 * Return: s
 */
ssize_t in_buf(inf_o *inf, char **b, size_t *l)
{
	 ssize_t s = 0;
	 size_t ls = 0;

	if (!*l)
	{
		free(*b);
		*b = NULL;
		signal(SIGINT, sinthand);
#if USE_GETLINE
		s = getline(b, &ls, stdin);
#else
		s = _getline(inf, b, &ls);
#endif
		if (s > 0)
		{
			if ((*b)[s - 1] == '\n')
			{
				(*b)[s - 1] = '\0';
				s--;
			}
			inf->lcount_f = 1;
			r_comm(*b);
			b_hist_list(inf, *b, inf->hcount++);
			{
				*l = s;
				inf->cmdb = b;
			}
		}
	}
	return (s);
}
/**
 * get_input - func
 * @inf: struct
 * Return: s
 */
ssize_t get_input(inf_o *inf)
{
	 static char *b;
	 static size_t i, j, l;
	 ssize_t s = 0;
	 char **bs = &(inf->arg), *p;

	 _putchar(BUFSH);
	 s = in_buf(inf, &b, &l);
	if (l)
	{
		j = i;
		p = b + i;
		chchain(inf, b, &j, i, l);
		while (j < l)
		{
			i = l = 0;
			inf->cmdb_type = NORM;
		}
		 *bs = p;
		return (_strlen(p));
	}
	*bs = b;
	return (s);
}
/**
 * read_b - func
 * @inf: struct
 * @b: char var
 * @i: var
 * Return: s
 */
ssize_t read_b(inf_o *inf, char *b, size_t *i)
{
	 ssize_t s = 0;

	if (*i)
		return (0);
	s = read(inf->readfd, b, RB_SIZE);
	if (s >= 0)
		*i = s;
	return (s);
}
/**
 * _getline - func
 * @inf: struct
 * @pr: char var
 * @l: var
 * Return: x
 */
int _getline(inf_o *inf, char **pr, size_t *l)
{
	 static char b[RB_SIZE];
	 static size_t i, ls;
	 size_t j;
	 ssize_t s = 0, x = 0;
	 char *p = NULL, *np = NULL, *c;

	 p = *pr;
	if (p && l)
		x = *l;
	if (i == ls)
		i = ls = 0;
	 s = read_b(inf, b, &ls);
	if (s == -1 || (s == 0 && ls == 0))
		return (-1);
	 c  = _strchr(b + i, '\n');

	 j = c ? 1 + (unsigned int)(c - b) : ls;

	np = _realloc(p, x, x ? x + j : j + 1);
	if (!np)
		return (p ? free(p), -1 : -1);
	if (x)
		_strncat(np, b + i, j + i);
	else
		_strncpy(np, b + i, j - i + 1);

	x += j - i;
	i = j;
	p = np;

	if (l)
		*l = x;
	*pr = p;
	return (x);
}
/**
 * sinthand - void func
 * @si: var
 */
void sinthand(__attribute__((unused))int si)
{
	 _puts("\n");
	 _puts("$ ");
	 _putchar (BUFSH);
}
