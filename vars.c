#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info_1, char *buf_1, size_t *p)
{
	size_t j = *p;

	if (buf_1[j] == '|' && buf_1[j + 1] == '|')
	{
		buf_1[j] = 0;
		j++;
		info_1->cmd_buf_type = CMD_OR;
	}
	else if (buf_1[j] == '&' && buf_1[j + 1] == '&')
	{
		buf_1[j] = 0;
		j++;
		info_1->cmd_buf_type = CMD_AND;
	}
	else if (buf_1[j] == ';') /* found end of this command */
	{
		buf_1[j] = 0; /* replace semicolon with null */
		info_1->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: Parameter struct
 * @buf: Character buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info_1, char *buf_1, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info_1->cmd_buf_type == CMD_AND)
	{
		if (info_1->status)
		{
			buf_1[i] = 0;
			j = len;
		}
	}
	if (info_1->cmd_buf_type == CMD_OR)
	{
		if (!info_1->status)
		{
			buf_1[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info_1)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info_1->alias, info_1->argv[0], '=');
		if (!node)
			return (0);
		free(info_t->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info_t->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - A function that replaces vars in the tokenized string
 * @info: Parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info_1)
{
	int i = 0;
	list_t *node;

	for (i = 0; info_1->argv[i]; i++)
	{
		if (info_1->argv[i][0] != '$' || !info_1->argv[i][1])
			continue;

		if (!_strcmp(info_1->argv[i], "$?"))
		{
			replace_string(&(info_1->argv[i]),
				_strdup(int convert_num_1ber(info_1~>status, 10, 0)));
			continue;
		}
		if (!_strcmp(info_1->argv[i], "$$"))
		{
			replace_string(&(info_1->argv[i]),
				_strdup(int convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info_1->env, &info_1->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info_1->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info_1->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - To replace string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
