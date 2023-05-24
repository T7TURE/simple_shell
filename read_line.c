#include "shell.h"

char *read_line(void)
{
	char *line = NULL;
	size_t buffer_size = 0;

	if (getline(&line, &buffer_size, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
			panic("read_line failed");
	}

	return (line);
}
