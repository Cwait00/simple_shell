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
	char *cpy_lineptr = NULL, *shell_lineptr = NULL, *strtoken;
	size_t n = 0, read_bytes;
	const char *delim = " \n\t\r";

	read_bytes = getline(&shell_lineptr, &n, stdin);

	while (1)
	{
		if (read_bytes == (size_t)EOF)
		{
			if (shell_lineptr != NULL)
			{
				break;
			}
			perror("error reading user input");
			return (EOF);
		}
	}

	cpy_lineptr = malloc((read_bytes + 1) * sizeof(char));

	if (cpy_lineptr == NULL)
	{
		perror("Memory allocation not successful");
		free(shell_lineptr);/*always free original*/
		return (-1);
	}
	_strncpy(cpy_lineptr, shell_lineptr, read_bytes);
	cpy_lineptr[read_bytes] = '\0';

	for (strtoken = strtok(cpy_lineptr, delim); strtoken != NULL;
			strtoken = strtok(NULL, delim))
	{
		created_puts1(strtoken);
	}
	free(cpy_lineptr);
	free(shell_lineptr);
	return (0);
}

/**
 * cmd_execute - created to execute commands
 * @argv: argument vector, used to identify commands
 * Return: str of command
 */
int cmd_execute(char **argv)
{
	pid_t pid_child = fork();
	char *cmd = argv[0];
	int wait_status;

	if (pid_child == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error: Command not found");
			return (1);
		}
	}
	else if (pid_child == -1)
	{
		perror("Error: Inability to fork");
		return (1);
	}

	if (pid_child != 0)
	{
		wait(&wait_status);
	}
	return (0);
}
