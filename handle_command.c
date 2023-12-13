#include "main.h"

/**
 * handle_command - Handles executing commands.
 * @commands_array: Array of command strings.
 * @argv: argument to the program.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_command(char *commands_array[], char *argv)
{
	int result;

	if (commands_array[0] == NULL)
	{
		return (-1);
	}

	result = builtin(commands_array, argv);
	if (result == -2)
	{
		return (-2);
	}
	else if (result != 0)
	{
		execute_cmd(commands_array, argv);
	}
	return (0);
}
