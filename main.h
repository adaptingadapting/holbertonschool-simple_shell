#ifndef main_h
#define main_h

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

#endif
