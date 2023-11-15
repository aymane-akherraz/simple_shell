#include "main.h"
/**
 * cmd_exist - Checks if the commande exists
 * @c: The command directory
 * Return: 0 if the command exists otherwise 1
*/
int cmd_exist(char *c)
{
	if (!(access(c, F_OK)))
		return (0);
	else
		return (1);
}
/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the given string
 * Return: The length of the given string.
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
/**
 * _puts - Prints a string, followed by a new line, to stdout.
 * @str: A pointer to the given string
*/

void _puts(char *str)
{
	while (*str != '\0')
		_putchar(*(str++));

	_putchar('\n');
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}