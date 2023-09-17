#include "main_shell.h"
/**
 * main - Function for simple shell
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	while (prompt_nexit(argc, argv))
	{
		parsing_strtok();
	}

	return (0);
}
