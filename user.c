#include "shell.h"

/**
 * _input - takes input from the user
 * @command: command entered by the user
 * @size: size in the memory
 */
void _input(char **command, size_t *size)
{
ssize_t linesize;
linesize = getline(command, size, stdin);
if (linesize == -1)
{
if (feof(stdin))
{
_print("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}
(*command)[linesize - 1] = '\0';
}
