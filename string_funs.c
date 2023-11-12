#include "main.h"

/**
 * _strdup - duplicate a string
 * @str: string to be duplicate
 * Return: duplicate string
*/
char *_strdup(const char *str)
{
	int len = 0;
	const char *temp;
	char *duplicate, *dup;

	temp = str;
	while (*temp != '\0')
	{
		len++;
		temp++;
	}

	duplicate = malloc(sizeof(char) * (len + 1));

	dup = duplicate;
	while (*str != '\0')
	{
		*dup = *str;
		dup++;
		str++;
	}
	*dup = '\0';

	return (duplicate);
}

/**
 * _strlen - funcrion to calculate the length of a string
 * @str: the string
 * Return: length of a string
*/
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _strcpy - copy a string
 * @dest: destination
 * @src: source
 * Return: copy of string
*/
char *_strcpy(char *dest, const char *src)
{
	char *cp = dest;

	while (*src != '\0')
	{
		*cp = *src;
		cp++;
		src++;
	}
	*cp = '\0';
	return (cp);
}

/**
 * _strcmp - compere two string
 * @str1: destination
 * @str2: source
 * Return: copy of string
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * _strcat - add a string to another string
 * @dest: destination string
 * @src: source string
 * Return: string
*/
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}
