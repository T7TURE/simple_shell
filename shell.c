#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Exit status of the shell program
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		prompt();
		line = read_line();
		args = parse_line(line);

		if (args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}

		status = execute(args);

		free(line);
		free(args);

		if (status == 0 || strcmp(args[0], "exit") == 0)
			break;
	}

	return (EXIT_SUCCESS);
}
