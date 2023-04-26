#include "shell.h"
/**
 * _eputs - void func
 * @s: char var
 */
void _eputs(char *s)
{
	int i = 0;

	if (!s)
		return;
	for (i = 0; s[i] != '\0'; i++)
		_eputchar(s[i]);
}
/**
 * _eputchar - func
 * @c: char var
 * Return: 1
 */
int _eputchar(char c)
{
	static int i;
	static char b[WB_SIZE];

	if (c == BUFSH || i >= WB_SIZE)
	{
		write(2, b, i);
		i = 0;
	}
	if (c != BUFSH)
		b[i++] = c;
	return (1);
}
/**
 * _putfd - func
 * @c: char var
 * @f: int var
 * Return: 1
 */
int _putfd(char c, int f)
{
	static int i;
	static char b[WB_SIZE];

	if (c == BUFSH || i >= WB_SIZE)
	{
		write(f, b, i);
		i = 0;
	}
	if (c != BUFSH)
		b[i++] = c;
	return (1);
}
/**
 * _putsfd - func
 * @s: char var
 * @f: int var
 * Return: i
 */
int _putsfd(char *s, int f)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += _putfd(*s++, f);
	}
	return (i);
}
