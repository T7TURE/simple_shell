#include "shell.h"

/**
 * panic - Displays an error message and exits the program with failure status
 * @message: The error message to display
 *
 * Description: This function displays the error message using perror()
 * and terminates the program with an EXIT_FAILURE status.
 */

void panic(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}


