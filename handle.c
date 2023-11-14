#include "shell.h"
#include <stdio.h>

/**
 * handle_environ - prints environment string to stdout
 *
 * Return: 0
 */
void handle_environ(void)
{
int x = 0;
char **env = environ;

while (env[x])
{
_print("%s\n", env[x]);
x++;
}
}
