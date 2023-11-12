#include "main.h"

/**
* dir_path - search if path exist
* @cmd: the command
* @dir: env path
* Return: command
*/
char *dir_path(char *cmd, char *dir)
{
	char *full_cmd;

	struct stat st;

	full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
	if (full_cmd)
	{
		_strcpy(full_cmd, dir);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, cmd);

		if (stat(full_cmd, &st) == 0)
			return (full_cmd);

		free(full_cmd);
	}

	return (NULL);
}

/**
* wach_kayn - search if path exist
* @cmd: the command
* Return: command
*/
char *wach_kayn(char *cmd)
{
	struct stat s;

	if (stat(cmd, &s) == 0)
		return (_strdup(cmd));

	return (NULL);
}


/**
* find_in_path - search if path exist
* @cmd: the command
* @path_env: path
* Return: command
*/
char *find_in_path(char *cmd, char *path_env)
{
	char *dir;

	dir = strtok(path_env, ":");
	while (dir)
	{
		char *full_cmd = dir_path(cmd, dir);

		if (full_cmd)
			return (full_cmd);

		dir = strtok(NULL, ":");
	}

	return (NULL);
}

/**
* handel_env - function that  return env
* @var: var type char
* Return: char
*/

char *handel_env(char *var)
{
	char *tmp, *key, *value, *env;

	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
	}
	return (NULL);
}
