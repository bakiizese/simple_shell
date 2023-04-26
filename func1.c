#include "shell.h"
/**
 * _strcpy - func
 * @dest: char var
 * @src: char var
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return (dest);
}
/**
 * _strdup - func
 * @str: string
 * Return: r
 */
char *_strdup(const char *str)
{
	int l = 0;
	char *r;

	if (str == NULL)
		return (NULL);
	while (*str++)
		l++;
	r = malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	for (l++; l--;)
		r[l] = *--str;
	return (r);
}
/**
 * _puts - void func
 * @str: string
 */
void _puts(char *str)
{
	int j = 0;

	if (!str)
		return;
	for (j = 0; str[j] != '\0'; j++)
	{
		_putchar(str[j]);
	}
}
/**
 * _putchar - func
 * @c: char var
 * Return: 1
 */
int _putchar(char c)
{
	static int j;
	static char b[WB_SIZE];

	if (c == BUFSH || j >= WB_SIZE)
	{
		write(1, b, j);
		j = 0;
	}
	if (c != BUFSH)
		b[j++] = c;
	return (1);
}
