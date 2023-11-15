#include "main.h"

/**
* split_command - function to split command
* @line: cammand to be split
* Return: split command
*/
char **split_command(char *line)
{
	char *token = NULL, **command = NULL, *cpline = NULL;
	int i = 0;
	int size = 0;

	size = count_tokens(line);
	if (size == 0)
	{
		free(line);
		return (NULL);
	}

	command = malloc(sizeof(char *) * (size + 1));
	if (!command)
	{
		perror("malloc");
		free(line);
		return (NULL);
	}

	cpline = _strdup(line);
	token = strtok(cpline, " \t\n");
	while (token != NULL)
	{
		command[i] = _strdup(token);
		if (!command[i])
		{
			perror("strdup");
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
		i++;
	}

	command[i] = NULL;
	free(cpline);
	free(line);

	return (command);
}
