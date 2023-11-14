#include "shell.h"

/**
 * my_token - creates tokens for user commands
 * @line: commands entered by the user
 *
 * Return: array of tokens
 */
char **my_token(char *line)
{
char *token = NULL, *saveptr = NULL;
char **tokens = NULL;
int tokensize = 0;
int i;

if (line == NULL)
return (NULL);
for (
token = strtok_r(line, " :\t\r\n", &saveptr);
token != NULL;
token = strtok_r(NULL, " :\t\r\n", &saveptr)
)
{
tokensize++;
}

if (tokensize == 0)
return (NULL);

tokens = malloc(sizeof(char *) * (tokensize + 1));
if (tokens == NULL)
return (NULL);

token = strtok_r(line, " :\t\r\n", &saveptr);
for (i = 0; i < tokensize; i++)
{
tokens[i] = _strdupli(token);
if (tokens[i] == NULL)
{
free_buff(tokens);
return (NULL);
}
token = strtok_r(NULL, " :\t\r\n", &saveptr);
}

tokens[tokensize] = NULL;

return (tokens);
}
