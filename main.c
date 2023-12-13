#include "main.h"

/**
 * main - Entry point for the shell
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *BUFFER = NULL;
	char **commands_array;
	size_t BUF_size = 0;
	int i = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "($) ", 4);
		}
		if (getline(&BUFFER, &BUF_size, stdin) == -1)
		{
			free(BUFFER);
			return (0);
		}

		commands_array = tokenize(BUFFER);
		handle_command(commands_array, argv[0]);
		while (commands_array[i] != NULL)
		{
			free(commands_array[i]);
			i++;
		}
		free(commands_array);
	}
	return (0);
}
