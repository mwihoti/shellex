#include "shell.h"

/**
 * _myenviron - prints  current environment
 * @info: Structure containing potential arguments. 
 * Return: Always 0
 */
int _myenviron(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenviron - gets the value of environ 
 * @info: Structure containing potential arguments.
 * @name: environ variable name
 *
 * Return: the value
 */
char *_getenviron(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ps;

	while (node)
	{
		ps = starts_with(node->str, name);
		if (ps && *ps)
			return (ps);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenviron - Initialize a new environment variable
 *             and also modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenviron(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenviron(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_environ_list - populates env linked list
 * @info: Structure containing potential arguments and Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_environ_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
