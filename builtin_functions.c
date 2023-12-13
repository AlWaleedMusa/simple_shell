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

	free(commands_array);
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
	return (0);
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
	char curr_cwd[1024];

	(void)argv;

	if (commands_array[1] == NULL)
	{
		getcwd(curr_cwd, sizeof(curr_cwd));
		setenv("OLDPWD", curr_cwd, 1);
		chdir(my_getenv("HOME"));
		setenv("PWD", my_getenv("HOME"), 1);
	}
	else if (_strcmp(commands_array[1], "-") == 0)
	{
		chdir(my_getenv("OLDPWD"));
		getcwd(curr_cwd, sizeof(curr_cwd));
		setenv("OLDPWD", my_getenv("PWD"), 1);
		setenv("PWD", curr_cwd, 1);
	}
	else
	{
		setenv("OLDPWD", my_getenv("PWD"), 1);
		chdir(commands_array[1]);
		getcwd(curr_cwd, sizeof(curr_cwd));
		setenv("PWD", curr_cwd, 1);
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

/**
 * builtin - Checks if the given command is a builtin, and if so calls
 * the corresponding function.
 * @commands_array: Array of command and arguments.
 * @argv: argument to the program.
 *
 * Return: 0 if a builtin function was found and executed, -1 otherwise.
 */
int builtin(char *commands_array[], char *argv)
{
	funcinfo funcs[] = {
		{"exit", exit_func},
		{"env", env_func},
		{"cd", cd_func}};

	int num_funcs = sizeof(funcs) / sizeof(struct FuncInfo);
	FuncPtr func = find_builtin(commands_array[0], funcs, num_funcs);

	if (func != NULL)
	{
		func(commands_array, argv);
		return (0);
	}
	return (-1);
}
