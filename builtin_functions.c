#include "main.h"

/**
 * exit_func - Exits the shell with exit code 0.
 * @commands_array: Array of command line arguments.
 * @argv: argument to the program.
 *
 * Return: nothing. Exits the program with exit code 0.
 */
int exit_func(char *commands_array[], char *argv)
{
	(void)commands_array;
	(void)argv;

	exit(0);
}
