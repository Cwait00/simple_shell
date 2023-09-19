#include "main_shell.h"

/**
 * main - entry point of the program.
 * @ac: argument count
 * @av: argument vector
 * Return: 0 (Success), 1 if error
 */
int ls(int ac, char **av)
{
	(void)ac;
	(void)av;
	return (0);
}
	/*info_t info[] = { INFO_INIT };
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
		info->readd = d;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}*/
