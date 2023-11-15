#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: a pointer to the memory previously allocated with a call to malloc
 * @old_size: the size, in bytes, of the allocated space for ptr
 * @new_size: the new size, in bytes of the new memory block
 * Return: ptr If new_size == old_size, a Pointer to the newly
 * allocated space, otherwise NULL
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *np;
	unsigned int i, size;

	if (new_size == old_size)
		return (ptr);

	if (ptr != NULL && new_size == 0)
		free(ptr);

	if (new_size != 0)
	{
		if (ptr == NULL)
		{
			np = malloc(new_size);
			if (np != NULL)
				return (np);
		}
		else
		{
			np = malloc(new_size);
			if (np != NULL)
			{
				if (old_size < new_size)
					size = old_size;
				else
					size = new_size;

				i = 0;
				while (i < size)
				{
					np[i] = ((char *)ptr)[i];
					i++;
				}
				free(ptr);
				return (np);
			}
		}
	}
	return (NULL);
}
/**
 * free_list - Frees a path_t list
 * @head: A pointer to the list to be freed
 *
 * Return: nothing
*/
void free_list(path_t *head)
{
	path_t *ptr;

	ptr = head;
	while (head != NULL)
	{
		ptr = head->next;
		free(head->d);
		free(head);
		head = ptr;
	}
}
/**
 * free_grid - Frees a 2 dimensional grid
 * @s: the address of the two dimensional grid
 * Return: Nothing
*/
void free_grid(char **s)
{
	unsigned int i;
	if (s)
	{
		for (i = 0; s[i] != NULL; i++)
			free(s[i]);
		free(s);
	}
}
