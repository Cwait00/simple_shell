#include "main_shell.h"
/**
 * main - function for beginning of simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 upon success
 */
int main(int argc, char **argv)
{
	/*ssize_t getline(char **lineptr, size_t *n, FILE *stream)*/
	char *shell_lineptr = NULL;
	char interpreter[] = "simple_shell:";
	size_t n = 0;
	char *program_name = argv[0];

	(void)argc;

	while (1)
	{
		printf("%s ", interpreter);
		
		if (getline(&shell_lineptr, &n, stdin) == -1)
		{
			if (shell_lineptr != NULL)
			{/*handling the ctrl + D*/
				break;
			}
			perror(program_name);
			return (1);
		}
		printf("%s\n", shell_lineptr);
		/*because getline allocates memory, it must be freed*/
		free(shell_lineptr);
		shell_lineptr = NULL;
	}
	/*free again for any memory not freed before*/
	free(shell_lineptr);

	return (0);
}
