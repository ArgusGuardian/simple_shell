#include "shell.h"

/**
 * check_exit - check for the exit command
 * @args: parsed arguments
 * @input: input from the user
 * @index: index
 */
void check_exit(char ***args, char **input, int index)
{
	int status = 128;

	if (args && *args)
	{
		if (_strcmp((*args)[0], "exit") == 0)
		{
			if (index > 1)
				status = 130;

			if (!(*args)[1])
			{
				free(*input);
				free2DArray(*args);
				exit(status % 128);
			}
			if (check_letter((*args)[1]) || atoi((*args)[1]) < 0)
			{
				status = 130;
				fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", (*args)[1]);
			}
			if ((*args)[1] && check_digit((*args)[1]))
			{
				status = atoi((*args)[1]);
				if (status == 1000)
				{
					free(*input);
					free2DArray(*args);
					exit(232);
				}
			}
			free(*input);
			free2DArray(*args);
			exit(status % 128);
		}
	}
}
/**
 * exit_message - exit message function
 * @args: parsed arguments
 * @input: input from the user
 * @index: index
 */
void exit_message(char ***args, char **input, int *index)
{
	if (*args != NULL)
		fprintf(stderr, "./hsh: %d: %s: not found\n", *index, *args[0]);
	free(*input);
	free2DArray(*args);
	exit(127);
}

/**
 * check_digit - check if string is digits
 * @string: string
 * Return: return 1 or 0 if not
 */
int check_digit(char *string)
{
	int i;

	if (string == NULL)
		return (0);

	for (i = 0; string[i] != '\0'; i++)
	{
		if (!(string[i] >= '0' && string[i] <= '9'))
			return (0);
	}

	return (1);
}
/**
 * check_letter - check if string is letters
 * @string: string
 * Return: return 1 or 0 if not
 */
int check_letter(char *string)
{
	int i;

	if (string == NULL)
		return (0);

	for (i = 0; string[i] != '\0'; i++)
		if ((string[i] < '0' || string[i] > '9'))
			return (1);

	return (0);
}
