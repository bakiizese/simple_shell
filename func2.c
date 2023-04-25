#include "shell.h"
/**
 * _strlen - func
 * @s: char var
 * Return: j
 */
int _strlen(char *s)
{
	int j = 0;

	if (!s)
		return (0);

	while (*s++)
		j++;
	return (j);
}
/**
 * _strcmp - func
 * @s1: char var
 * @s2: char var
 * Return: 1 or -1
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * st_wi - func
 * @haystack: char var
 * @needle: char var
 * Return: haystack
 */
char *st_wi(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - func
 * @dest: char var
 * @src: char var
 * Return: ret
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
