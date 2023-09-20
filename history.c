#include "main_shell.h"

/**
 * get_history_file - gets history file
 * @info: parameter structure
 * Return: history file containing allocated string.
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - Appends to an existing file or creates a file
 * @info: the parameter structure
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
	ssize_t d;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	d = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (d == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, d);
		_putfd('\n', d);
	}
	_putfd(BUF_FLUSH, d);
	close(d);
	return (1);
}

/**
 * read_history - reads history.
 * @info: parameter structure
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int a, last = 0, linecount = 0;
	ssize_t d, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	d = open(filename, O_RDONLY);
	free(filename);
	if (d == -1)
		return (0);
	if (!fstat(d, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(d, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(d);
	for (a = 0; a < fsize; a++)
		if (buf[a] == '\n')
		{
			buf[a] = 0;
			build_history_list(info, buf + last, linecount++);
			last = a + 1;
		}
	if (last != a)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - history linked list
 * @info: contains potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: history linecount, histcount
 * Return: Always 0 (Success)
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history
 * @info: contains potential arguments. Used to maintain
 * Return: to the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int a = 0;

	while (node)
	{
		node->num = a++;
		node = node->next;
	}
	return (info->histcount = a);
}
