#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * parse_args - Parsing Arguments
 * @command: char
 * Return: char
 */
char **parse_args(char *command)
{
char **args = malloc(sizeof(char *) * 10);
char *tokentemp = NULL;
int argc = 0;

if (args == NULL)
{
perror("malloc");
exit(1);
}

tokentemp = strtok(command, " ");
while (tokentemp != NULL && argc < 10)
{
args[argc++] = strdup(tokentemp);
tokentemp = strtok(NULL, " ");
}
args[argc] = NULL;
return (args);
}

/**
 * get_path - finds PATH in global environment
 * Return: PATH or NULL
 */
char *get_path(void)
{
char **env = environ;
char *path = NULL;

while (*env)
{
if (strncmp(*env, "PATH=", 5) == 0)
{
path = *env + 5;
return (path);
}
env++;
}
return (NULL);
}

/**
 * add_path - adds path to command
 * @path: path of command entered by the user
 * @command: user input
 * Return: buffer containing command on success or NULL
 */
char *add_path(const char *path, const char *command)
{
size_t path_len;
size_t command_len;
char *buf;
if (path == NULL)
path = "";

path_len = strlen(path);
command_len = strlen(command);

buf = malloc(path_len + command_len + 2);
if (!buf)
return (NULL);

strcpy(buf, path);
if (path_len > 0 && path[path_len - 1] != '/')
strcat(buf, "/");

strcat(buf, command);
return (buf);
}

/**
 * confirm_path - checks if the path is valid
 * @path: tokenized path from the user
 * @command: user entered input
 * Return: NULL or the full path
 */
char *confirm_path(char **path, const char *command)
{
int i = 0;
char *output;

while (path[i])
{
output = add_path(path[i], command);
if (access(output, F_OK | X_OK) == 0)
return (output);

free(output);
i++;
}
return (NULL);
}
