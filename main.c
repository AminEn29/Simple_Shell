#include "main.h"

/**
* main - main function
* @ac: number of argument
* @argv: program arguments
* Return: 0
*/
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	int index = 0;
	(void) ac;


	while (1)
	{
		line = cmd_line();
		if (line == NULL)
			return (status);

		command = split_command(line);
		if (command == NULL)
			continue;

		status = _execute(command, argv, index);
	}

}
