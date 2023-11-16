#include "main.h"
/**
 * split_str - splits a string by the given delimiters
 * @s: the given string
 * Return: An array of the resulted strings otherwise NULL
*/
char **split_str(char *s)
{
	char **a = NULL;
	char *t;
	unsigned int i;

	t = strtok(s, " \t\n");
	a = malloc(sizeof(char *) * 1024);
	if (a != NULL)
	{
		i = 0;
		while (t)
		{
			a[i] = t;
			t = strtok(NULL, " \t\n");
			i++;
		}
		a[i] = NULL;
	}
	else
		return (NULL);

	return (a);
}
/**
 * _strcpy - Copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: the destination array to copy to
 * @src: the source array to copy from
 * Return: the pointer to dest array
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - Compares two strings.
 * @s1: The first given string
 * @s2: The second given string
 * Return: 0 if s1 and s2 are identical,
 * less than 0 if s1 is less than s2,
 * greater than 0 if s1 is greater than s2.
*/

int _strcmp(char *s1, char *s2)
{
	int i, j;

	j = 0;
	while (s2[j] != '\0')
		j++;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (j > i)
		return (s1[i] - s2[i]);
	return (0);
}
/**
 * _strcat - Concatenates two strings.
 * @dest: A pointer to the first string
 * @src: A pointer to the second string
 * Return: A pointer to the resulting string dest
*/

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *  which contains a copy of the string given as a parameter.
 * @str: A pointer to the given string
 * Return: NULL if str = NULL or if insufficient memory was available,
 * otherwise a pointer to the duplicated string
*/

char *_strdup(char *str)
{
	char *d;
	int i, l;

	if (str != NULL)
	{
		l = 0;
		while (str[l] != '\0')
			l++;

		d = malloc(sizeof(char) * (l + 1));
		if (d != NULL)
		{
			for (i = 0; i < l; i++)
				d[i] = str[i];

			d[i] = '\0';
			return (d);
		}
	}
	return (NULL);
}

