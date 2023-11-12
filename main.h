#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <error.h>
#include <fcntl.h>

extern char **environ;

char *cmd_line(void);
char **split_command(char *line);
int _execute(char **cmd, char **argv, int index);
char *handel_path(char *cmd);



/******help*****/
int count_tokens(char *line);
char *_strdup(const char *str);
void freeBuff(char **buf);
void printerror(char *name, char *cmd, int idx);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *int_convert(int num);
void reverse_string(char *str, int length);
void printerror(char *name, char *cmd, int idx);
char *dir_path(char *cmd, char *dir);
char *wach_kayn(char *cmd);
char *handel_env(char *var);
char *find_in_path(char *cmd, char *path_env);


#endif
