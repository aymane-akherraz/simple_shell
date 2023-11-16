#include "main.h"
void search_exe(char **argv, path_t **head, char *buf, int *b);
/**
 * main - The entry point of the shell
 * Return: always 0
*/
int main(void)
{
	char *buf = NULL;
	char **argv = NULL;
	ssize_t c = 0;
	size_t size;
	int b = 0;
	path_t *head = NULL;

	while (1)
	{
		b = 0;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		c = getline(&buf, &size, stdin);
		if (c != -1)
		{
			argv = split_str(buf);
			if (argv)
				search_exe(argv, &head, buf, &b);
			else
				perror("malloc failed!");
		}
		else if (feof(stdin))
		{
			if (argv)
				free_grid(argv);
			free_list(head);
			free(buf);
			exit(0);
		}
		else if (ferror(stdin))
		{
			free_list(head);
			free(buf);
			perror("Reading from stdin failed!");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
/**
 * search_exe - searches and executes commandes
 * @argv: An array of strings
 * @head: A pointer to a path_t list
 * @buf: A buffer
 * @b: A boolean
 * Return: Nothing
*/
void search_exe(char **argv, path_t **head, char *buf, int *b)
{
	char *p = NULL;
	pid_t pid;
	int st;

	if (_strcmp(argv[0], "exit") == 0)
	{
		free_grid(argv);
		if (*head)
			free_list(*head);
		free(buf);
		exit(0);
	}
	if (cmd_exist(argv[0]))
	{
		p = search_path(head, argv[0]);
		if (p == NULL)
		{
			perror("Command not found!");
			*b = 1;
		}
		else
			argv[0] = p;
	}
	if (*b == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Fork failed!");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Failed to execute");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&st);
	}
	free_grid(argv);
}

