#ifndef MAIN_SHELL_H
#define MAIN_SHELL_H
#include <stdio.h>
#include <stddef.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
/*temporary mains*/
int _main(void);
int __main(void);
int main();
int getmain();
int main(void);
int *main(void);
void main(void);
/*not temporary*/
int prompt_nexit(int argc, char **argv);
/*void free_info(info_t *info, int all);*/
/*void set_info(info_t *info, char **av);*/
/*void clear_info(info_t *info);*/
/*char *_strncpy(char *dest, char *src, int n);*/
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
/*int _putchar(char c);*/
/*void remove_comments(char *buf);*/
#endif
