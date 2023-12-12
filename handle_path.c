#include "main.h"

/**
 * handle_path - Searches the PATH env variable to find the full path
 * for the executable file specified in commands_array[0].
 * @commands_array: Array containing command and arguments.
 *
 * Return: Pointer to full path string on success,
 * commands_array[0] if not found,
 * NULL on failure.
 */
char *handle_path(char *commands_array[])
{
	char *path_env = my_getenv("PATH");
	char *path = _strdup(path_env);
	char *token = strtok(path, ":");
	int cmd_length = _strlen(commands_array[0]);

	if (!path_env || !*path_env)
	{
		return (NULL);
	}

	while (token != NULL)
	{
		int token_len = _strlen(token);
		char *cmd_path = malloc(token_len + 1 + cmd_length + 1);

		if (!cmd_path)
		{
			return (NULL);
		}

		_memcpy(cmd_path, token, token_len);
		cmd_path[token_len] = '/';
		_memcpy(cmd_path + token_len + 1, commands_array[0], cmd_length);
		cmd_path[token_len + 1 + cmd_length] = '\0';

		if (access(cmd_path, X_OK) == 0)
		{
			free(path);
			return (cmd_path);
		}

		free(cmd_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (commands_array[0]);
}
