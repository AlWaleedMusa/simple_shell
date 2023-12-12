#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}

/**
 * _memcpy - function to copy memory
 * @src: source to copy from
 * @dest: destination to copy to
 * @n: num of chars to copy
 *
 * Return: Copied memory
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int lol;

	for (lol = 0; lol < n; lol++)
	{
		dest[lol] = src[lol];
	}
	return (dest);
}
