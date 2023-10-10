#include "shell.h"
/**
 * execution - exucuting the valid commands
 * @args: parsed arguments
 * @input: input from the user
 * Return: status
 */
int execution(char **args, char *input)
{
	pid_t child_pid;
	int status;

	(void)input;
	child_pid = fork();

	if (child_pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			free2DArray(args);
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free2DArray(args);
	}
	return (status);
}
