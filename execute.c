#include "shell.h"

/**
 * execute_command - execute commands using system
 * @cmd: command entered by the user
 */
void execute_command(char *cmd)
{
int status;

status = system(cmd);
if (status == -1)
{
perror("system");
exit(98);
}
}
