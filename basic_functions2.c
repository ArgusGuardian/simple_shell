#include "shell.h"

/**
 * _strcat - concat src to dest string
 * @dest: destination to copy to
 * @src: source string
 */
void _strcat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	dest[i + j] = '\0';
}

/**
 * _strcmp - compare two strings
 * @str1: first string
 * @str2: second string
 * Return: difference between 2 strings
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
