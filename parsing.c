#include "main_shell.h"
/**
 * parsing_strtok - function created to help
 * parse through commands typed in the shell by
 * the user
 * Return: 0 if succesful
 */
int parsing_strtok(void)
{
	/*char *strtok(char *str, const char *delim);*/
	char *cpy_lineptr = NULL, *lineptr = NULL, *strtoken;
	size_t n = 0, read_bytes;
	const char *delim = " \n";

	read_bytes = getline(&lineptr, &n, stdin);

	if (read_bytes == (size_t)-1)
	{
		perror("Error reading input from user");
		return (-1);
	}

	cpy_lineptr = malloc(getline(&lineptr, &n, stdin) * sizeof(char));

	if (cpy_lineptr == NULL)
	{
		perror("Memory allocation not successful");
		free(lineptr);/*always free original*/
		return (-1);
	}
	_strncpy(cpy_lineptr, lineptr, read_bytes);

	for (strtoken = strtok(cpy_lineptr, delim); strtoken != NULL;
			strtoken = strtok(NULL, delim))
	{
		created_puts1(strtoken);
	}
	return (0);
}

/**
 * cmd_execute - created to execute commands
 * @argv: argument vector, used to identify commands
 * Return: str of command
 */
int cmd_execute(char **argv)
{
	char *cmd = argv[0];

	if (execve(cmd, argv, NULL) == -1)
	{
		perror("Error: Command not found");
		return (99);
	}
	return (0);
}
