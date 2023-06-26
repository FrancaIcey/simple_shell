#include "main.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info_1: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhistory(info_t *info_1)
{
	print_list(info_1->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info_1: parameter struct
 * @str_1: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info_1, char *str_1)
{
	char *p, c;
	int ret;

	p = _strchr(str_1, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info_1->alias),
		get_node_index(info_1->alias, node_starts_with(info_1->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info_1: parameter struct
 * @str_1: the string alias
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info_1, char *str_1)
{
	char *p;

	p = _strchr(str_1, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info_1, str_1));

	unset_alias(info_1, str_1);
	return (add_node_end(&(info_1->alias), str_1, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str_1, '=');
		for (a = node->str_1; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info_1: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info_1)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info_1->argc == 1)
	{
		node = info_1->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info_1->argv[i]; i++)
	{
		p = _strchr(info_1->argv[i], '=');
		if (p)
			set_alias(info_1, info_1->argv[i]);
		else
			print_alias(node_starts_with(info_1->alias, info_1->argv[i], '='));
	}

	return (0);
}
