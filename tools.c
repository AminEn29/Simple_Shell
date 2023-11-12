#include "main.h"

/**
* freeBuff - free array
* @buf: array to be free
* Return: void
*/
void freeBuff(char **buf)
{
	int i;

	if (!buf)
		return;

	for (i = 0; buf[i] != NULL; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}
	free(buf);
	buf = NULL;
}


/**
 * printerror - print an error
 * @name: name of file
 * @cmd: command
 * @idx: indes
 * Return: message
*/
void printerror(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = int_convert(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));

	free(index);
}

/**
 * reverse_string - reverse a string
 * @str: the string
 * @length: length of string
 * Return: reverse string
*/
void reverse_string(char *str, int length)
{
	char tmp;
	int lawl = 0;
	int tali = length - 1;

	while (lawl < tali)
	{
		tmp = str[lawl];
		str[lawl] = str[tali];
		str[tali] = tmp;
		lawl++;
		tali--;
	}

}

/**
 * int_convert - int to ASCCI
 * @num: the number
 * Return: ASCCI
*/
char *int_convert(int num)
{
	char buffer[15];
	int i = 0;

	if (num == 0)
		buffer[i++] = '\0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}
