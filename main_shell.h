#ifndef MAIN_SHELL_H
#define MAIN_SHELL_H

#define EOF (-1)

#include <sys/wait.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/*temporary mains*/
void str(void);
int ls(int ac, char **av);
int dear(void);
int pic(void);
int get(void);
void is(void);
void em(void);
void today(void);
int bab(void);
int who(void);
int phone(void);
void frr(void);
void cm(void);
void add(void);
void len(void);
/*not temporary*/
int cmd_execute(char **argv);
void created_puts1(const char *str);
int main(int argc, char **argv);
int parsing_strtok(void);
int prompt_nexit(int argc, char **argv);
/*void free_info(info_t *info, int all);*/
/*void set_info(info_t *info, char **av);*/
/*void clear_info(info_t *info);*/
char *_strncpy(char *dest, char *src, int n);
/*char *_strncat(char *dest, char *src, int n);*/
/*char *_strchr(char *s, char c);*/
/*char **get_environ(info_t *info);*/
/*int _unsetenv(info_t *info, char *var);*/
/*int _setenv(info_t *info, char *var, char *value);*/
/*int _isalpha(int c);*/
/*int interactive(info_t *info);*/
/*int is_delim(char c, char *delim);*/
/*int _atoi(char *s);*/
/*int _myexit(info_t *info)*/
/*int _mycd(info_t *info);*/
/*int _myhelp(info_t *info);*/
/*int _myalias(info_t *info);*/
/*int print_alias(list_t *node);*/
/*int set_alias(info_t *info, char *str);*/
/*int unset_alias(info_t *info, char *str);*/
/*int _myhistory(info_t *info);*/
/*int populate_env_list(info_t *info);*/
/*int _mysetenv(info_t *info);*/
/*char *_getenv(info_t *info, const char *name);*/
/*int _myenv(info_t *info);*/
int _putchar(char c);
/*void remove_comments(char *buffer);*/

#endif
