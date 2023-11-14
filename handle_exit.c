#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * _str_comp - compare between two strings
 * @s1: char
 * @s2: char
 * Return: int
 */
int _str_comp(char *s1, char *s2)
{
return (strcmp(s1, s2));
}

/**
 * my_exit - handles exit command
 * @command: tokenized command
 * @line: input read
 * Return: no return
 */
void my_exit(char **command, char *line)
{
int i;
free(line);

if (command)
{
for (i = 0; command[i]; i++)
{
free(command[i]);
}
free(command);
}

exit(0);
}
