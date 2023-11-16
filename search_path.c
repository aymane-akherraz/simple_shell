#include "main.h"
char *_getenv(const char *name);
path_t *add_node_e(path_t **head, char *str);

/**
 * search_path - search for a command in the PATH
 * @head: A pointer to the head of path_t
 * @s: the command to search for
 *
 * Return: The absolute path of s otherwise NULL
*/
char *search_path(path_t **head, char *s)
{
	char *t, *p;
	path_t *h;
	struct stat st;

	if (*head == NULL)
	{
		p = _getenv("PATH");
		t = strtok(p, ":");
		while (t)
		{
			if (add_node_e(head, t) == NULL)
			{
				free(p);
				free(t);
				return (NULL);
			}
			t = strtok(NULL, ":");
		}
	}
	h = *head;
	t = NULL;
	p = _strdup("/");
	if (p)
		_strcat(p, s);

	while (h != NULL)
	{
		t = _strdup(h->d);
		if (t)
			_strcat(t, p);
		if (stat(t, &st) == 0)
		{
			free(p);
			return (t);
		}
		free(t);
		t = NULL;
		h = h->next;
	}
	return (NULL);
}
/**
 * _getenv - gets the value of the given variable name
 * @name: the variable name
 * Return: the correspondant value otherwise NULL
*/
char *_getenv(const char *name)
{
	char **env = environ;
	char *t = NULL;
	int i = 0;

	while (env[i])
	{
		t = strtok(env[i], "=");
		if (strcmp(t, name) == 0)
		{
			t = strtok(NULL, "\n");
			return (t);
		}
		i++;
	}
	return (NULL);
}
/**
 * add_node_e - Adds a new node at the end of a path_t list.
 * @head: A pointer to the list
 * @str: A pointer to the given string
 *
 * Return: the address of the new element, or NULL if it failed
*/
path_t *add_node_e(path_t **head, char *str)
{
	path_t *new, *ptr;

	new = malloc(sizeof(path_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->d = _strdup(str);

	if (new->d == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = new;
	}
	return (new);
}

