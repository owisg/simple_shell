#include "shell.h"

/**
 * _strdupli - duplicate a string
 * @s: string to duplicate
 * Return: pointer to duplicated string
 */
char *_strdupli(char *s)
{
int len;
char *ptr;
int i;
if (s == NULL)
return (NULL);

len = _strlen(s);
ptr = malloc(sizeof(char) * (len + 1));
if (!ptr)
return (NULL);

for (i = 0; s[i] != '\0'; i++)
{
ptr[i] = s[i];
}
ptr[len] = '\0';
return (ptr);
}

/**
 * _strchr - locate character in a string
 * @s: string to check
 * @c: character to locate
 * Return: pointer to the first character found or NULL if not found
 */
char *_strchr(char *s, char c)
{
while (*s)
{
if (*s == c)
return (s);
s++;
}
if (!c)
return (s);
return (NULL);
}

/**
 * _strlen - get the length of a string
 * @s: input string
 * Return: length of the string
 */
int _strlen(char *s)
{
int count = 0;
while (*s)
{
count++;
s++;
}
return (count);
}

extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/**
 * mode_handler - handles the shell mode
 * @s: signal number
 */
void mode_handler(int s)
{
(void)s;
write(STDERR_FILENO, "\n", 1);
write(STDERR_FILENO, "$ ", 2);
}

/**
 * _strncmp - compare two strings up to n bytes
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: 0 if the strings are equal up to n bytes
 */
int _strncmp(char *s1, char *s2, int n)
{
int i;
for (i = 0; s1[i] && s2[i] && i < n; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}
return (0);
}
