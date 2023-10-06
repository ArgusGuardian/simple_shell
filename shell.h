#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/* BASIC_FUNCTIONS.C */
void free2DArray(char **array);
void free_combo(char ***args, char **input, char *new_dir, int alert);
char *_strdup(const char *str);
size_t _strlen(const char *str);
void _strcpy(char *dest, const char *src);

/* BASIC_FUNCTIONS2.C */
void _strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);

/* ARGS.C */
int _getline(char **input, size_t *len);
char **parse_arguments(char *input);
int check_empty(char *input);
int check_cd(char ***args, char **input, int index);
int check_path(char **args);

/* ARGS2.C */
void check_exit(char ***args, char **input, int index);
void exit_message(char ***args, char **input, int *index);

/* EXECUTION.C */
int execution(char **args, char *input);

#endif
