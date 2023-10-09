#include "shell.h"

/**
 * free2DArray - function that frees 2D array
 * @array: 2D arrays
 */
void free2DArray(char **array)
{
	int i = 0, rows = 0;

	if (array == NULL)
		return;
	while (array[rows])
		rows++;

	for (i = 0; i < rows; i++)
		free(array[i]);

	free(array);
}

/**
 * free_combo - free arguments + new dir combo
 * @args: parsed arguments
 * @input: input from the user
 * @new_dir: new directory
 * @alert: alert
 */
void free_combo(char ***args, char **input, char *new_dir, int alert)
{
	(void)input;
	if (alert)
		free(new_dir);

	free2DArray(*args);
}

/**
 * _strlen - calculates the lenght of a string
 * @str: parsed arguments
 * Return: return the lenght of the string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * _strcpy - copy string from src to dest
 * @dest: destination to copy to
 * @src: source string
 */
void _strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

/**
 * _strdup - duplicate a string with allocating the memory
 * @str: parsed arguments
 * Return: return new string
 */
char *_strdup(const char *str)
{
	size_t len;
	char *new_str;

	len = _strlen(str) + 1;
	new_str = (char *)malloc(len);
	if (new_str == NULL)
		return (NULL);

	_strcpy(new_str, str);
	return (new_str);
}
