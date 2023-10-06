#include "shell.h"

/**
 * check_exit - check for the exit command
 * @args: parsed arguments
 * @input: input from the user
 * @index: index
 */
void check_exit(char ***args, char **input, int index)
{
	int status;

	status = index;
	if (args && *args)
	{
		if (_strcmp((*args)[0], "exit") == 0)
		{
			if (index == 1)
				status = 0;

			if (args[1] && (*args)[1])
			{
				if (_strcmp((*args)[1], "1000") == 0)
					status = 232;
				else if ((*args)[1][0] < '0' || (*args)[1][0] > '9')
				{
					fprintf(stderr, "./hsh: %d: %s: Illegal number: %s\n",
							index, (*args)[0], (*args)[1]);
					status = 2;
				}
			}
			free(*input);
			free2DArray(*args);
			exit(status);
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
