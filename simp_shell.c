#include "main_shell.h"
/**
 * main - function for beginning of simple shell
 * Return: 0 upon success
 */
int main(void)
{
	/*ssize_t getline(char **lineptr, size_t *n, FILE *stream)*/
	char *shell_lineptr;
	char interpreter[] = "simple_shell:";
	size_t n = 0;

	printf("%s ", interpreter);
	getline(&shell_lineptr, &n, stdin);
	printf("%s\n", shell_lineptr);

	/*because getline allocates memory, it must be freed*/

	free(shell_lineptr);

	return (0);
}
