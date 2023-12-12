#include "main.h"

/**
 * my_getenv - Gets the value of an environment variable
 * @name: The name of the environment variable to get
 *
 * Return: a pointer to the value of the environment variable
 * or NULL if it does not exist.
 */
char *my_getenv(char *name)
{
	char *equal;
	int length;
	char **environment_variable = environ;

	while (*environment_variable != NULL)
	{
		equal = _strchr(*environment_variable, '=');
		if (equal == NULL)
		{
			continue;
		}
		length = equal - *environment_variable;
		if (strncmp(*environment_variable, name, length) == 0 && name[length] == '\0')
		{
			return (equal + 1);
		}
		environment_variable++;
	}
	return (NULL);
}
