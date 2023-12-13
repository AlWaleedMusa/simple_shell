#include "main.h"

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
	int status = -1;

	(void)argv;

	if (commands_array[1] == NULL)
	{
		status = chdir(my_getenv("HOME"));
	}
	else if (_strcmp(commands_array[1], "-") == 0)
	{
		status = chdir(my_getenv("OLDPWD"));
	}
	else
	{
		status = chdir(commands_array[1]);
	}

	if (status == -1)
	{
		perror("Error");
		return (-1);
	}
	else
	{
		getcwd(curr_cwd, sizeof(curr_cwd));
		setenv("OLDPWD", my_getenv("PWD"), 1);
		setenv("PWD", curr_cwd, 1);
	}
	return (0);
}
