#include "shell.h"

/**
 * execute - Execute a command with arguments
 * @args: The array of command arguments
 *
 * Return: Exit status of the executed command
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		panic("fork failed");
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUSstatus);
	}

	return (1);
}

