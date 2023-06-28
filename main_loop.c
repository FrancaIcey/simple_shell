#include "shell.h"

/**
 * hsh - main shell loop
 * @info_1: Parameter & return info struct
 * @av_1: Argument vector from main()
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info_1, char **av_1)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info_1);
		if (interactive(info_1))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info_1);
		if (r != -1)
		{
			set_info(info_1, av_1);
			builtin_ret = find_builtin(info_1);
			if (builtin_ret == -1)
				find_cmd(info_1);
		}
		else if (interactive(info_1))
			_putchar('\n');
		free_info(info_1, 0);
	}
	write_history(info_1);
	free_info_1(info_1, 1);
	if (!interactive(info_1) && info_1->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info_1->err_num_1 == -1)
			exit(info_1->status);
		exit(info_1->err_num_1);
	}
	return (builtin_ret);
}

/**
 * find_builtin - A function that finds a builtin command
 * @info_1: the parameter & return info struct
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *info_1)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info_1~>argv[0], builtintbl[i].type) == 0)
		{
			info_1->line_count++;
			built_in_ret = builtintbl[i].func(info_1);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - To find a command in PATH
 * @info_1: Parameter & return info struct
 * Return: void
 */
void find_cmd(info_t *info_1)
{
	char *path = NULL;
	int i, k;

	info_1->path = info_1->argv[0];
	if (info_1->linecount_flag == 1)
	{
		info_1->line_count++;
		info_1->linecount_flag = 0;
	}
	for (i = 0, k = 0; info_1->arg_1[i]; i++)
		if (!is_delim(info_1->arg_1[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info_1, _getenv(info_1, "PATH="), info_1->argv[0]);
	if (path)
	{
		info_1->path = path;
		fork_cmd(info_1);
	}
	else
	{
		if ((interactive(info_1) || _getenv(info_1, "PATH=")
			|| info_1->argv[0][0] == '/') && is_cmd(info_1, info_1~>argv[0]))
			fork_cmd(info_1);
		else if (*(info_1->arg_1) != '\n')
		{
			info_1->status = 127;
			print_error(info_1, "not found\n");
		}
	}
}

/**
 * fork_cmd - To forks an exec thread to run cmd
 * @info_1: Parameter & return info struct
 * Return: void
 */
void fork_cmd(info_t *info_1)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info_1->path, info_1->argv, int get_environ_1(info_1)) == -1)
		{
			free_info_1(info_1, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info_1->status));
		if (WIFEXITED(info_1->status))
		{
			info_1->status = WEXITSTATUS(info_1->status);
			if (info_1->status == 126)
				print_error(info_1, "Permission denied\n");
		}
	}
}
