#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>

extern char **environ;

/**
 * FuncPtr - typedef for the struct member func.
 */
typedef int (*FuncPtr)(char **, char *);

/**
 * struct FuncInfo - struct that define pointer to func details.
 * @name: name of the function.
 * @func: pointer to the function.
 * Description: name is name of the function.
 */
typedef struct FuncInfo
{
	char *name;
	FuncPtr func;
}funcinfo;

char **tokenize(char *str);
int handle_command(char *commands_array[], char *argv);
FuncPtr find_builtin(char *name, struct FuncInfo *funcs, int num_funcs);
int builtin(char *commands_array[], char *argv);
char *my_getenv(char *name);
int exit_func(char *commands_array[], char *argv);
int env_func(char *commands_array[], char *argv);
int cd_func(char *commands_array[], char *argv);
char *handle_path(char *commands_array[]);
int execute_cmd(char *commands_array[], char *argv);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
char *_strdup(char *s);
char **strtow(char *str);
int count_word(char *s);

#endif
