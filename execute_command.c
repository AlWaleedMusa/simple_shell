#include "main.h"

/**
 * execute_cmd - Executes a command by forking a new process
 * @commands_array: Array of command and arguments to execute
 * @argv: argument to the program
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_cmd(char *commands_array[], char *argv)
{
	pid_t fork_id;
	char *cmd;

	fork_id = fork();
	if (fork_id == 0)
	{
		if (strncmp(commands_array[0], "/", 1) == 0)
		{
			if (execve(commands_array[0], commands_array, environ) == -1)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv, commands_array[0]);
			}
		}
		else
		{
			cmd = handle_path(commands_array);
		}

		if (cmd != NULL)
		{
			if (execve(cmd, commands_array, environ) == -1)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv, cmd);
			}
		}
		else
		{
			return (-1);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
