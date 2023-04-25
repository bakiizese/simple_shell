#include "shell.h"
/**
 * iscmd - entry
 * @p: var
 * @inf: var
 * Return: 0
 */
int iscmd(inf_o *inf, char *p)
{
	struct stat t;

	(void)inf;
	if (!p || stat(p, &t))
		return (0);

	if (t.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * char_dp - entry
 * @p: var
 * @s: var
 * @st: var
 * Return: 0
 */
char *char_dp(char *p, int s, int st)
{
	static char b[1024];
	int j = 0, k = 0;

	for (k = 0, j = s; j < st; j++)
	{
		if (p[j] != ':')
			b[k++] = p[j];
	}
	b[k] = 0;
	return (b);
}
/**
 * fd_p - entry
 * @p: var
 * @ps: var
 * @c: var
 * Return: 0
 */
char *fd_p(inf_o *inf, char *ps, char *c)
{
	int j = 0, cr = 0;
	char *p;

	if (!ps)
		return (NULL);
	if ((_strlen(c) > 2) && st_wi(c, "./"))
	{
		if (iscmd(inf, c))
			return (c);
	}
	while (1)
	{
		if (!ps[j] || ps[j] == ':')
		{
			p = char_dp(ps, cr, j);
			if (!*p)
				_strcat(p, c);
			else
			{
				_strcat(p, "/");
				_strcat(p, c);
			}
			if (iscmd(inf, p))
				return (p);
			if (!ps[j])
				break;
			cr = j;
		}
		j++;
	}
	return (NULL);
}
/**
 * _strncpy - entry
 * @p: dest
 * @src: var
 * @n: var
 * Return: s
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		for (j = i; j < n; j++)
			dest[j] = '\0';
	}
	return (s);
}
/**
 * _strncat - entry
 * @p: dest
 * @src: var
 * @n: var
 * Return: s
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
