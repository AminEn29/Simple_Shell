#include "main.h"

/**
* handel_path - handel path
* @cmd: command
* Return: commad
*/
char *handel_path(char *cmd)
{
	char *path_env, *full_cmd;
	int i;

	for (i = 0; cmd[i]; i++)

	{
		if (cmd[i] == '/')
		{
			return (wach_kayn(cmd));
		}
	}

	path_env = handel_env("PATH");
	if (!path_env)
		return (NULL);

	full_cmd = find_in_path(cmd, path_env);

	free(path_env);
	return (full_cmd);
}
