#include "shell.h"

/**
* my_built - execute built-ins commands
* @command: tokenized input
* @line: input read from the user
* Return: 1 if a built-in command is found, 0 otherwise
*/

int my_built(char **command, char *line)
{
char *builtins[] = {"env", "exit"};
int num_builtins = sizeof(builtins) / sizeof(builtins[0]);
int i;
for (i = 0; i < num_builtins; i++)
{
/*if (_str_comp(*command, builtins[i]) == 0)*/
/*{*/
if (_str_comp(*command, "env") == 0)
{
handle_environ();
return (1);
}
else if (_str_comp(*command, "exit") == 0)
{
my_exit(command, line);
}
return (1);
/*}*/
}

return (0);
}
