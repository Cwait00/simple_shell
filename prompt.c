#include "maint_shell.h"
/**
 * prompt_nexit - prints the prommpt and handles CTRL+D
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 upon success
 */
int prompt_nexit(int argc, char **argv)
{
	/*ssize_t getline(char **lineptr, size_t *n, FILE *stream)*/
	char *shell_lineptr = NULL;
	char interpreter[] = "simple_shell: ";
	size_t n = 0;
	size_t user_input = getline(&shell_lineptr, &n, stdin);
	char *program_name = argv[0];

	(void)argc;

	while (1)
	{
		_puts(interpreter);

		if (user_input == (size_t)-1)
		{
			/*if (feof(stdin))*/
			if (feof(stdin))
			{handling the ctrl + D
				break;
			}
			perror(program_name);
			return (-1);
		}
		_puts(shell_lineptr);
		/*because getline allocates memory, it must be freed*/
		shell_lineptr = NULL;
		free(shell_lineptr);
	}
	/*free again for any memory not freed before*/
	if (shell_lineptr != NULL)
	{
		free(shell_lineptr);
	}
	return (0);
}
