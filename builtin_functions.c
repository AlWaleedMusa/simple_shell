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
 * env_func - Prints the current environment variables to stdout.
 * @commands_array: Array of command line arguments.
 * @argv: argument to the program.
 *
 * Return: 0 on success.
 */
int env_func(char *commands_array[], char *argv)
{
	int i = 0;

	(void)commands_array;
	(void)argv;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	exit(0);
}

/**
 *  cd_func - Changes the current working directory.
 * @commands_array: Array of command line arguments.
 * @argv: argument to the program.
 *
 * Return: Returns 0 on success, non-zero on failure.
 */
int cd_func(char *commands_array[], char *argv)
{
	if (commands_array[1] == NULL)
	{
		fprintf(stderr, "%s: expected argument to \"cd\"\n", argv);
	}
	else
	{
		if (chdir(commands_array[1]) != 0)
		{
			perror("Error");
		}
	}
	return (0);
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
