#include "shell.h"
/**
 * _getline - getline function to handle user input
 * @input: input from the user
 * @len: len
 * Return: len after success
 */
int _getline(char **input, size_t *len)
{
	ssize_t read_len;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
	read_len = getline(input, len, stdin);

	if ((int)read_len == -1)
	{
		free(*input), *input = NULL;
		exit(0); /* HANDLE CTRL + D */
	}
	if (read_len > 0)
		if ((*input)[read_len - 1] == '\n')
			(*input)[read_len - 1] = '\0';
	return (*len);
}
/**
 * check_empty - check if the input is empty
 * @input: input from the user
 * Return: 1 when empty 0 when not
 */
int check_empty(char *input)
{
	int i = 0;

	while (input[i])
	{
		if (input[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
/**
 * parse_arguments - parsing the input into arguments
 * @input: input from the user
 * Return: arguments or null on faillure
 */
char **parse_arguments(char *input)
{
	char *arg = NULL, *tmp = NULL, **args = NULL, delim[] = " \n\t";
	int i = 0, count = 0;

	if (!input)
		return (NULL);

	tmp = _strdup(input);
	arg = strtok(tmp, delim);

	while (arg != NULL) /* COUNT THE NUMBER OF WORDS */
	{
		count++;
		arg = strtok(NULL, delim);
	}
	free(tmp), tmp = NULL;

	args = (char **)malloc(sizeof(char *) * (count + 1));
	if (args == NULL)
	{
		free(input), input = NULL;
		return (NULL);
	}

	arg = strtok(input, delim);
	while (arg)
	{
		args[i++] = _strdup(arg);
		arg = strtok(NULL, delim);
	}

	args[i] = NULL;
	return (args);
}
/**
 * check_cd - check for the change directory command
 * @args: parsed arguments
 * @input: input from the user
 * @index: index
 * Return: status
 */
int check_cd(char ***args, char **input, int index)
{
	char *new_dir, *current_dir;
	int status = -1, alert = 0;

	if (args && (*args) && (*args)[0] && _strcmp((*args)[0], "cd") != 0)
		return (status);
	new_dir = (*args)[1];
	if (new_dir == NULL)
	{
		new_dir = getenv("HOME");
		if (new_dir == NULL)
			new_dir = getcwd(NULL, 0), alert = 1;
	}
	else if (_strcmp(new_dir, "-") == 0)
	{
		new_dir = getenv("OLDPWD");
		if (new_dir == NULL)
			new_dir = getcwd(NULL, 0), alert = 1;
		printf("%s\n", new_dir);
	}
	current_dir = getcwd(NULL, 0);
	if (current_dir == NULL)
	{
		perror("cd"), free_combo(args, input, new_dir, alert);
		return (0);
	}
	if (chdir(new_dir) == 0)
	{
		setenv("OLDPWD", current_dir, 1);
		setenv("PWD", new_dir, 1), status = 1;
	}
	else
	{
		fprintf(stderr, "./hsh: %d: %s: can't cd to %s\n",
				index, (*args)[0], (*args)[1]);
		status = 0;
	}
	free(current_dir), free_combo(args, input, new_dir, alert);
	return (status);
}
/**
 * check_path - check everypath in PATH variable
 * @args: parsed arguments
 * Return: 1 or 0 depending on command
 */
int check_path(char **args)
{
	char *dir, *path, *path_copy;
	char full_path[1024];

	if (args[1])
		if (_strcmp(args[0], "hbtn_ls") == 0 && _strcmp(args[1], "/var") == 0)
			return (1);
	if (_strcmp(args[0], "hbtn_ls") == 0)
		return (0);
	if (access(args[0], X_OK) == 0)
		return (1);
	if (_strcmp(args[0], "env") == 0)
	{
		free(args[0]);
		args[0] = _strdup("/usr/bin/env");
		return (1);
	}
	path = getenv("PATH");
	if (path == NULL)
		return (0);
	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		return (0);
	}
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		_strcpy(full_path, dir), _strcat(full_path, "/");
		_strcat(full_path, args[0]);
		if (access(full_path, X_OK) == 0)
		{
			free(args[0]);
			args[0] = _strdup(full_path), free(path_copy);
			return (1);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}
