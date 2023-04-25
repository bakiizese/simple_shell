#include "shell.h"
/**
 * ghist_file - func
 * @inf: struct
 * Return: b
 */
char *ghist_file(inf_o *inf)
{
	char *b, *d;

	d = genv(inf, "HOME=");
	if (!d)
		return (NULL);
	b = malloc(sizeof(char) * (_strlen(d) + _strlen(H_F) + 2));
	if (!b)
		return (NULL);
	b[0] = 0;
	_strcpy(b, d);
	_strcat(b, "/");
	_strcat(b, H_F);
	return (b);
}
/**
 * w_hist - func
 * @inf: struct
 * Return: 1
 */
int w_hist(inf_o *inf)
{
	ssize_t f;
	char *fname = ghist_file(inf);
	lists_t *n = NULL;

	if (!fname)
		return (-1);

	f = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (f == -1)
		return (-1);
	for (n = inf->hist; n; n = n->next)
	{
		_putsfd(n->str, f);
		_putfd('\n', f);
	}
	_putfd(BUFSH, f);
	close(f);
	return (1);
}
/**
 * r_hist - func
 * @inf: struct
 * Return: inf
 */
int r_hist(inf_o *inf)
{
	int i, l = 0, lc = 0;
	ssize_t f, rlen, fs = 0;
	struct stat s;
	char *b = NULL, *fname = ghist_file(inf);

	if (!fname)
		return (0);

	f = open(fname, O_RDONLY);
	free(fname);
	if (f == -1)
		return (0);
	if (!fstat(f, &s))
		fs = s.st_size;
	if (fs < 2)
		return (0);
	b = malloc(sizeof(char) * (fs + 1));
	if (!b)
		return (0);
	rlen = read(f, b, fs);
	b[fs] = 0;
	if (rlen <= 0)
		return (free(b), 0);
	close(f);
	for (i = 0; i < fs; i++)
		if (b[i] == '\n')
		{
			b[i] = 0;
			b_hist_list(inf, b + l, lc++);
			l = i + 1;
		}
	if (l != i)
		b_hist_list(inf, b + l, lc++);
	free(b);
	inf->hcount = lc;
	while (inf->hcount-- >= H_M)
		delete_node_at_i(&(inf->hist), 0);
	re_hist(inf);
	return (inf->hcount);
}
/**
 * b_hist_list - func
 * @inf: struct
 * @b: char var
 * @lc: int var
 * Return: 0
 */
int b_hist_list(inf_o *inf, char *b, int lc)
{
	lists_t *n = NULL;

	if (inf->hist)
		n = inf->hist;
	add_node_end(&n, b, lc);

	if (!inf->hist)
		inf->hist = n;
	return (0);
}
/**
 * re_hist - func
 * @inf: struct
 * Return: inf
 */
int re_hist(inf_o *inf)
{
	lists_t *n = inf->hist;
	int i = 0;

	while (n)
	{
		n->n = i++;
		n = n->next;
	}
	return (inf->hcount = i);
}
