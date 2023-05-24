#include "shell.h"

/**
 * parse_line - Parses a command line into tokens
 * @line: The command line to parse
 *
 * Return: An array of tokens extracted from the command line
 */
char **parse_line(char *line)
{
	int buffer_size = BUFFER_SIZE;
	int position = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
		panic("parse_line failed: allocation error");

	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;

		tokens[position] = token;
		position++;

		if (position >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
				panic("parse_line failed: allocation error");
		}

		token = strtok(NULL, TOKEN_DELIM);
	}

	tokens[position] = NULL;
	return (tokens);
}

