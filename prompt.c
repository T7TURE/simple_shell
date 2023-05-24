#include "shell.h"

/**
 * prompt - Displays a prompt message if input is from a terminal.
 */

void prompt(void)
{
	char *msg = "$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, msg, strlen(msg));
		fflush(stdout);
	}
}
