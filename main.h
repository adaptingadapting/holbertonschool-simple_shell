#ifndef main_h
#define main_h

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void free3(char *str, char *str2, char *str1);
void free4(char *s, char *s1, char *s2, char *s3);
char *programStat(char *line);
int executePathProgram(char **token);
void tokenize(char **token, char *delim);
int xcuteFunc(char *string, char **token, int *pcount);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void sigintHandler(int sig_num);
char *_getenv(char *str);

#endif
