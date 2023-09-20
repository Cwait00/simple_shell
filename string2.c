#include "main_shell.h"
void share(void);

void share(void)
{
}
/**
 * _strcpy - Copies a string from the src to the dest
 * @dest: destination
 * @src: source
 * Return: pointer to the begining of the dest string
 */
/*char *_strcpy(char *dest, char *src)
{
	int h = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[h])
	{
		dest[h] = src[h];
		i++;
	}
	dest[h] = 0;
	return (dest);
}*/

/**
 * _strdup - duplicates a given string
 * @str: the string to duplicate as its argument
 * Return: pointer to the duplicated string 'ret'
 */
/*char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}*/

/**
 * _puts - prints a string to the standard output
 * @str: the string to be printed as its argument
 * Return: Nothing
 */
/*void _puts(char *str)
{
	int o = 0;

	if (!str)
		return;
	while (str[o] != '\0')
	{
		_putchar(str[o]);
		o++;
	}
}
*/
/**
 * _putchar - writes the character c to the std output
 * @c: The character to print as its argument
 * Return: if success 1.
 * if error, -1 is returned, and errno is set appropriately.
 */
/*int _putchar(char c)
{
	static int q;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || q >= WRITE_BUF_SIZE)
	{
		write(1, buf, q);
		q = 0;
	}
	if (c != BUF_FLUSH)
		buf[q++] = c;
	return (1);
}*/
