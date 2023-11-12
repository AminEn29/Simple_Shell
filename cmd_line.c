#include "main.h"

/**
* cmd_line - read command
* Return: command line
*/

char *cmd_line(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t val;

	if (isatty(STDIN_FILENO) != 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}

	val = getline(&line, &length, stdin);

	if (val == -1)
	{
		free(line);
		return (NULL);
	}

	if (val > 0 && line[val - 1] == '\n')
	{
		line[val - 1] = '\0';
	}

	return (line);
}
