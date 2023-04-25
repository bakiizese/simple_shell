#include "shell.h"
/**
 * _eatoi - func
 * @str: string
 * Return: l
 */
int _eatoi(char *str)
{
	int i = 0;
	unsigned long int l = 0;

	if (*str == '+')
		str++;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			l *= 10;
			l += (str[i] - '0');
			if (l > INT_MAX)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (l);
}
/**
 * p_err - func
 * @inf: struct
 * @str: string
 */
void p_err(inf_o *inf, char *str)
{
	_eputs(inf->fn);
	_eputs(": ");
	p_d(inf->lcount, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(str);
}
/**
 * p_d - func
 * @in: int var
 * @f: int var
 * Return: j
 */
int p_d(int in, int f)
{
	int (*__putchar)(char) = _putchar;
	int i, j = 0;
	unsigned int s, cr;

	if (f == STDERR_FILENO)
		__putchar = _eputchar;
	if (in < 0)
	{
		s = -in;
		__putchar('-');
		j++;
	}
	else
		s = in;
	cr = s;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (s / i)
		{
			__putchar('0' + cr / i);
			j++;
		}
		cr %= i;
	}
	__putchar('0' + cr);
	j++;

	return (j);
}
/**
 * conv_n - func
 * @m: int var
 * @bs: buf
 * @f: int var
 * Return: p
 */
char *conv_n(long int m, int bs, int f)
{
	static char *r;
	static char b[50];
	char s = 0;
	char *p;
	unsigned long n = m;

	if (!(f & CONV_UNSIGN) && m < 0)
	{
		n = -m;
		s = '-';

	}
	r = f & CONV_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &b[49];
	*p = '\0';

	do	{
		*--p = r[n % bs];
		n /= bs;
	} while (n != 0);

	if (s)
		*--p = s;
	return (p);
}
/**
 * r_comm - void func
 * @b: char var
 */
void r_comm(char *b)
{
	int i = 0;

	while (b[i] != '\0')
	{
		if (b[i] == '#' && (!i || b[i - 1] == ' '))
		{
			b[i] = '\0';
			break;
		}
		i++;
	}
}
