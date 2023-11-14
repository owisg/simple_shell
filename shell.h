#ifndef SHELL_H
#define SHELL_H

/*#include <stdrag.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

char *add_path(const char *path, const char *command);
char *get_path(void);
void prompt(void);
char *confirm_path(char **path, const char *command);
/*char *parse_args(char *command, char *arguments);*/
char **parse_args(char *command);
int _print(const char *format, ...);
int my_built(char **command, char *line);
void execute_command(char *cmd);
void free_buff(char **buf);
void handle_environ(void);
int _str_comp(char *s1, char *s2);
char *_strdupli(char *s);
int cmd_check(char **cmd, char *buf);
char **my_token(char *line);
void _input(char **command, size_t *size);
void handle_ctrl_c(int signo);
char *_strchr(char *s, char c);
int _strlen(char *s);
void mode_handler(int s);
int _strncmp(char *s1, char *s2, int n);
void my_exit(char **command, char *line);
int _putchar(char c);

/**
* struct opp - struct for 3
* @c: character to check
* @f: function to point to
*/
typedef struct opp
{
char *c;
int (*f)(va_list a);
} printer;

/**
 * struct flags - handle flags
 * @interactive: mode of the shell
 */
struct flags
{
bool interactive;
} flags;

/**
 * struct cond - condition of the shell
 * @final_exit: shell exit
 * @ln_count: line count
 */
struct cond
{
int final_exit;
int ln_count;
} cond;

extern char **environ;
#endif
