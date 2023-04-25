#include "shell.h"
/**
 * strtok1 - entry
 * @sr: var
 * @a: var
 * Return: v
 */
char **strtok1(char *sr, char *a)
{
	int i, j, z, m, count = 0;
	char **v;

	if (sr == NULL || sr[0] == 0)
		return (NULL);
	if (!a)
		a = " ";
	for (i = 0; sr[i] != '\0'; i++)
		if (!is_delim(sr[i], a) && (is_delim(sr[i + 1], a) || !sr[i + 1]))
			count++;

	if (count == 0)
		return (NULL);
	v = malloc((1 + count) * sizeof(char *));
	if (!v)
		return (NULL);
	for (i = 0, j = 0; j < count; j++)
	{
		while (is_delim(sr[i], a))
			i++;
		z = 0;
		while (!is_delim(sr[i + z], a) && sr[i + z])
			z++;
		v[j] = malloc((z + 1) * sizeof(char));
		if (!v[j])
		{
			for (z = 0; z < j; z++)
				free(v[z]);
			free(v);
			return (NULL);
		}
		for (m = 0; m < z; m++)
			v[j][m] = sr[i++];
		v[j][m] = 0;
	}
	v[j] = NULL;
	return (v);
}
/**
 * strtok2 - entry
 * @sr: var
 * @a: var
 * Return: v
 */
char **strtok2(char *sr, char a)
{
	int i, j, z, m, count = 0;
	char **v;

	if (sr == NULL || sr[0] == 0)
		return (NULL);
	i = 0;
	for (i = 0; sr[i] != '\0'; i++)
	{
		if ((sr[i] != a && sr[i + 1] == a) ||
		    (sr[i] != a && !sr[i + 1]) || sr[i + 1] == a)
			count++;
	}
	if (count == 0)
		return (NULL);
	v = malloc((1 + count) * sizeof(char *));
	if (!v)
		return (NULL);
	i = 0;
	j = 0;
	for (i = 0, j = 0; j < count; j++)
	{
		while (sr[i] == a && sr[i] != a)
			i++;
		z = 0;
		while (sr[i + z] != a && sr[i + z] && sr[i + z] != a)
			z++;
		v[j] = malloc((z + 1) * sizeof(char));
		if (!v[j])
		{
			for (z = 0; z < j; z++)
				free(v[z]);
			free(v);
			return (NULL);
		}
		for (m = 0; m < z; m++)
			v[j][m] = sr[i++];
		v[j][m] = 0;
	}
	v[j] = NULL;
	return (v);
}
/**
 * _memset - entry
 * @s: var
 * @b: var
 * @n: var
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
/**
 * ffr - entry
 * @p: var
 */
void ffr(char **p)
{
	char **i = p;

	if (!p)
		return;
	while (*p)
		free(*p++);
	free(i);
}
/**
 * _realloc - entry
 * @ptr: var
 * @o: var
 * @n: var
 * Return: p
 */
void *_realloc(void *ptr, unsigned int o, unsigned int n)
{
	char *p;

	if (!ptr)
		return (malloc(n));
	if (!n)
		return (free(ptr), NULL);
	if (n == o)
		return (ptr);
	p = malloc(n);
	if (!p)
		return (NULL);
	o = o < n ? o : n;
	while (o--)
		p[o] = ((char *)ptr)[o];
	free(ptr);
	return (p);
}
