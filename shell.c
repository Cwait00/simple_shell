#include "maint_shell.h"

/**
 * main - Function for simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	ssize_t read_bytes;
	int shell_printing = 1;
	char buffer[1024];

	while (shell_printing)
	{
		shell_printing = prompt_nexit(argc, argv);

		if (shell_printing)
		{/*reading user input*/
			read_bytes = read(STDIN_FILENO, buffer, sizeof(buffer));

			if (read_bytes == -1)
			{
				perror("Error reading input");
				return (1);
			}
			else if (read_bytes == 0)
			{/*takes care of ctrl + d*/
				break;
			}
			/*re-infroduce the null terminator*/
			buffer[read_bytes] = '\0';
		}
	}

	return (0);
}
