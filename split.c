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

/**
 * **strtow - Entry point
 *
 * @str: string
 *
 * Return: pointer to an array (Success)
 */

char **strtow(char *str)
{
	char **lmao, *lol;
	int w, q = 0, length = 0, words, s = 0, start, end;

	while (*(str + length))
		length++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	lmao = (char **)malloc(sizeof(char *) * (words + 1));
	if (lmao == NULL)
		return (NULL);

	for (w = 0; w <= length; w++)
	{
		if (str[w] == ' ' || str[w] == '\0')
		{
			if (s)
			{
				end = w;
				lol = (char *)malloc(sizeof(char) * (s + 1));
				if (lol == NULL)
					return (NULL);
				while (start < end)
					*lol++ = str[start++];
				*lol = '\0';
				lmao[q] = lol - s;
				q++;
				s = 0;
			}
		}
		else if (s++ == 0)
			start = w;
	}
	lmao[q] = NULL;

	return (lmao);
}
