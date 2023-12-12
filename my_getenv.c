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
	char **environment_var = environ;

	while (*environment_var != NULL)
	{
		equal = _strchr(*environment_var, '=');
		if (equal == NULL)
		{
			continue;
		}
		length = equal - *environment_var;
		if (strncmp(*environment_var, name, length) == 0 && name[length] == '\0')
		{
			return (equal + 1);
		}
		environment_var++;
	}
	return (NULL);
}
