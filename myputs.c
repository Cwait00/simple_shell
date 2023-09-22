#include "maint_shell.h"
/**
 * created_puts1 - prints a complete string to stdio
 * @str: string to be printed
 * Return: has no return
 */
void created_puts1(const char *str)
{

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
