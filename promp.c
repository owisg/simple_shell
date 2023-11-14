#include "shell.h"

/**
* prompt - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
*/
void prompt(void)
{
if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
flags.interactive = 1;

if (flags.interactive)
{
printf("$ ");
fflush(stdout);
}
}
