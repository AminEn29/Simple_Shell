#include "main.h"

/**
* main - main function
* struct BuiltInCommand - struct
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

	BuiltInCmd built[] = {
		{"exit", exit_program},
		{"env", print_env},
		{NULL, NULL}
	};

	(void)ac;

	while (1)
	{
		line = cmd_line();
		if (line == NULL)
			return (status);

		index++;
		command = split_command(line);
		if (command == NULL)
			continue;

		if (ilakan_builtin(command[0], built))
			handel_builtin(command, &status, built);
		else
			status = _execute(command, argv, index);
	}

}
