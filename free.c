#include "shell.h"

/**
 * free_buff - frees buffers
 * @buf: buffer to be freed
 *
 * Return: no return
 */
void free_buff(char **buf)
{
int i;
if (buf == NULL)
return;

for (i = 0; buf[i] != NULL; i++)
{
free(buf[i]);
buf[i] = NULL;
}

free(buf);
}
