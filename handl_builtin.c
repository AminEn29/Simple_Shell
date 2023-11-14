#include "main.h"

/**
* ilakan_builtin - handel builtin command
* @cmd: command
* @built: struct
* Return: status
*/
int ilakan_builtin(char *cmd, struct BuiltInCmd built[])
{
	int i;

	for (i = 0; built[i].cmd != NULL; i++)
	{
		if (_strcmp(cmd, built[i].cmd) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
* handel_builtin - handel builtin command
* @cmd: command
* @status: value
* @built: struct
* Return: void
*/
void handel_builtin(char **cmd, int *status, struct BuiltInCmd built[])
{
	int i;

	for (i = 0; built[i].cmd != NULL; i++)
	{
		if (_strcmp(cmd[0], built[i].cmd) == 0)
		{
			built[i].fun(cmd, status);
			return;
		}
	}
}

/**
 * exit_program - exit program
 * @cmd: command
 * @status: the status
 * Return:void
*/
void exit_program(char **cmd, int *status)
{
	freeBuff(cmd);
	exit(*status);
}


/**
 * print_env - exit program
 * @cmd: command
 * @status: the status
 * Return:void
*/
void print_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freeBuff(cmd);
	(*status) = 0;
}
