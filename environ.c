#include "main.h"

/**
 * _myenv - prints the current environment
 * @info_1: Structure containing potential arguments. Used to maintain
 * constant function prototype
 * Return: Always 0
 */
int _myenv(info_t *info_1)
{
	print_list_str(info_1->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info_1: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info_1, const char *name)
{
	list_t *node = info_1->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info_1: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info_1)
{
	if (info_1->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info_1, info_1->argv[1], info_1->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info_1: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info_1)
{
	int i;

	if (info_1->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info_1->argc; i++)
		_unsetenv(info_1, info_1->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info_1: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info_1)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
