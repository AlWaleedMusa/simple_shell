#include "main.h"

/**
 * tokenize - Tokenize the given string into an array of tokenized strings.
 * @str: The string to tokenize.
 *
 * Return: An array of tokenized strings, or NULL on failure.
 */
char **tokenize(char *str)
{
	char *word;
	char *breaker = " \n\t";
	char **str_array;
	int i = 0;

	str_array = malloc(sizeof(char) * 256);
	if (!str_array)
	{
		free(str_array);
		printf("Error allocating memory");
		return (NULL);
	}

	word = strtok(str, breaker);

	while (word != NULL)
	{
		str_array[i] = malloc(sizeof(char) * (_strlen(word) + 1));
		if (!str_array[i])
		{
			free(str_array);
			printf("Error allocating memory");
			return (NULL);
		}
		_strcpy(str_array[i], word);
		word = strtok(NULL, breaker);
		i++;
	}
	str_array[i] = '\0';
	return (str_array);
}
