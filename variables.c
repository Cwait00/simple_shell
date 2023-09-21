#include "maint_shell.h"

/**
 * is_chain - detects chain delimeters in a command buffer.
 * @info: the parameter structure
 * @buf: the char buffer
 * @p: updates the position to the next character after
 * the detected delimeter.
 * Return: 1 if no valid chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t v = *p;

	if (buf[v] == '|' && buf[v + 1] == '|')
	{
		buf[v] = 0;
		v++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[v] == '&' && buf[v + 1] == '&')
	{
		buf[v] = 0;
		v++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[v] == ';') /* found end of this command */
	{
		buf[v] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = v;
	return (1);
}

/**
 * check_chain - checks whether command chaining
 * should continue based on last status
 * @info: The parameter structure
 * @buf: The charecter buffer
 * @p: Updates the position to the end of the buffer.
 * @i: Begining position in buffer
 * @len: The length of buf
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces the first argument in the array
 * with its corresponding alias.
 * @info: the parameter structure
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int v;
	list_t *node;
	char *p;

	for (v = 0; v < 10; v++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces variables and special vars
 * in the command argument.
 * @info: the parameter structure
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces an old string with a new one.
 * @old: old string
 * @new: new string
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
