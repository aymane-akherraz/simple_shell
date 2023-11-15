#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

typedef struct dirs
{
	char *d;
	struct dirs *next;
} path_t;

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_list(path_t *head);
char **split_str(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
int cmd_exist(char *c);
char *search_path(path_t **head, char *s);
void free_grid(char **s);


#endif