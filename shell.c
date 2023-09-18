#include "main_shell.h"

/**
 * main - Function for simple shell
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	int shell_printing = 0;

	while (!shell_printing)
	{
		shell_printing = prompt_nexit(argc, argv);

		if (!shell_printing)
		{
			parsing_strtok();
			cmd_execute(argv);
		}
	}

	return (0);
}
