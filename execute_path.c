#include "main.h"

/**
* _execute - execute command
* @cmd: command to be executed
* @argv: argument
* @index: int index
* Return: val of status
*/
int _execute(char **cmd, char **argv, int index)
{
	pid_t child;
	int status;
	char *full_cmd;

	full_cmd = handel_path(cmd[0]);
	if (full_cmd == NULL)
	{
		printerror(argv[0], cmd[0], index);
		freeBuff(cmd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			freeBuff(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freeBuff(cmd);
		free(full_cmd);
	}
	return (WEXITSTATUS(status));
}
