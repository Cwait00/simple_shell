<<<<<<< HEAD
#include "main_shell.h"
/**
 * today - empty function that temp
 * Return: has no return
 **/
void today(void)
{
}
=======
#include "maint_shell.h"


>>>>>>> 63fe436cd35645e6351e63238eb005f7839b9733
/**
 * interactive - Shell is interactive mode and returns if true
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
<<<<<<< HEAD
/*int interactive(info_t *info)*/
/*{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
*/
=======
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
>>>>>>> 63fe436cd35645e6351e63238eb005f7839b9733

/**
 * is_delim - checks if is a delimeter
 * @c: The charecter to check
 * @delim: The string of the delimeter
 * Return: 1 if true, 0 if false
 */
<<<<<<< HEAD
/*int is_delim(char c, char *delim)*/
/*{
=======
int is_delim(char c, char *delim)
{
>>>>>>> 63fe436cd35645e6351e63238eb005f7839b9733
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
<<<<<<< HEAD
*/
=======
>>>>>>> 63fe436cd35645e6351e63238eb005f7839b9733

/**
 * _isalpha - Alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

<<<<<<< HEAD
/*int _isalpha(int c)*/
/*{
=======
int _isalpha(int c)
{
>>>>>>> 63fe436cd35645e6351e63238eb005f7839b9733
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
<<<<<<< HEAD
*/
=======
>>>>>>> 63fe436cd35645e6351e63238eb005f7839b9733

/**
 * _atoi - A string to an integer
 * @s: String to be converted
 * Return: 0 if no num in string, converted number otherwise
 */

<<<<<<< HEAD
/*int _atoi(char *s)*/
/*{
=======
int _atoi(char *s)
{
>>>>>>> 63fe436cd35645e6351e63238eb005f7839b9733
	int i, sign = 1, flag = 0, output;
	unsigned int r = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			r *= 10;
			r += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -r;
	else
		output = r;

	return (output);
}
<<<<<<< HEAD
*/
=======
>>>>>>> 63fe436cd35645e6351e63238eb005f7839b9733
