#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int fml, g, o;

	fml = 0;
	g = 0;

	for (o = 0; s[o] != '\0'; o++)
	{
		if (s[o] == ' ')
			fml = 0;
		else if (fml == 0)
		{
			fml = 1;
			g++;
		}
	}

	return (g);
}
