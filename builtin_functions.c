#include "main.h"

/**
 * exit_func - Exits the shell with exit code 0.
 * @commands_array: Array of command line arguments.
 * @argv: argument to the program.
 *
 * Return: nothing. Exits the program with exit code 0.
 */
int exit_func(char *commands_array[], char *argv)
{
	(void)commands_array;
	(void)argv;

	exit(0);
}

/**
 * find_builtin - Searches an array of FuncInfo structs to find the
 * function pointer for the given command name.
 * @name: The name of the command to find.
 * @funcs: Array of FuncInfo structs containing name and function pointer.
 * @num_funcs: Number of elements in funcs array.
 *
 * Return: a function pointer if found, NULL if not found.
 */
FuncPtr find_builtin(char *name, struct FuncInfo *funcs, int num_funcs)
{
	int i = 0;
	char *token = strtok(name, " \n");

	if (token == NULL)
	{
		return (NULL);
	}

	while (i < num_funcs)
	{
		if (_strcmp(token, funcs[i].name) == 0)
		{
			free(token);
			return (funcs[i].func);
		}
		i++;
	}
	return (NULL);
}