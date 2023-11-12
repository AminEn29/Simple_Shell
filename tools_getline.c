#include "main.h"

/**
* count_tokens - function to count tokens in a command
* @line: command to be split
* Return: number of tokens
*/
int count_tokens(char *line)
{
	char *token = NULL;

	char *cpline = NULL;

	int size = 0;

	cpline = _strdup(line);
	token = strtok(cpline, " \t\n");
	while (token != NULL)
	{
		size++;
		token = strtok(NULL, " \t\n");
	}

	free(cpline);
	return (size);
}
