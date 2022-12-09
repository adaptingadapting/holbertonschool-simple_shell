#ifndef main_h
#define main_h

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *programStat(char *line);
void executePathProgram(char **token);
void tokenize(char **token, char *delim);
void xcuteFunc(char *string, char **token);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void sigintHandler(int sig_num);
char *_getenv(char *str);

#endif
