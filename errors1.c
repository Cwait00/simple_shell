#include "main_shell.h"

int *main(void)
{
	return (0);
}
/**
 * _eputs - Input string
 * @str: The string
 * Return: Nothing
 */
/*void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}*/

/**
 * _eputchar - Character c to stderr
 * @c: Character to print
 * Return: 1 On success.
 * On error, -1 is returned, and errno is set appropriately.
 */
/*int _eputchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}*/

/**
 * _putfd - Character c to given fd
 * @c: character to print
 * @fd: The filedescriptor to write to
 * Return: 1 On success
 * On error, -1 is returned, and errno is set appropriately.
 */
/*int _putfd(char c, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}*/

/**
 * _putsfd - Input string
 * @str: String to be printed
 * @fd: File descriptor to write to
 * Return: num of charectors put
 */
/*int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}*/
