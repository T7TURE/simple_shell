#include "shell.h"

void prompt(void)
{
	char *msg = "$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, msg, strlen(msg));
		fflush(stdout);
	}
}
