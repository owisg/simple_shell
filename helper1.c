#include "shell.h"

/**
 * cmd_check - checks for builtin functions or executes external commands
 * @cmd: tokenized input
 * @buf: buffer
 * Return: 1 if cmd found, 0 if not
 */
int cmd_check(char **cmd, char *buf)
{
if (my_built(cmd, buf))
return (1);

if (**cmd == '/' || **cmd == '.')
{
execute_command(cmd[0]);
return (1);
}

return (0);
}

/**
 * handle_ctrl_c - handle Ctrl+C signal
 * @signo: signal number
 */
void handle_ctrl_c(int signo)
{
(void)signo;
_putchar('\n');
exit(EXIT_SUCCESS);
}
