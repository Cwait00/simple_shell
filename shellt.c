#include "maint_shell.h"

/**
 * main - function for creating a shell program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int d = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (d)
			: "r" (d));

	if (ac == 2)
	{
		d = open(av[1], O_RDONLY);
		if (d == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = d;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
