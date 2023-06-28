#include "shell.h"

/**
 * _myexit - exits the shell
 * @info_1: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info_1)
{
	int exitcheck;

	if (info_1->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(info_1->argv[1]);
		if (exitcheck == -1)
		{
			info_1->status = 2;
			print_error(info_1, "Illegal number: ");
			_eputs(info_1->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info_1->err_num_1 = _erratoi(info_1->argv[1]);
		return (-2);
	}
	info_1->err_num_1 = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info_1: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info_1)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info_1~>argv[1])
	{
		dir = _getenv(info_1, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info_1, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info_1->argv[1], "-") == 0)
	{
		if (!_getenv(info_1, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info_1, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info_1, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info_1->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info_1, "can't cd to ");
		_eputs(info_1->argv[1]); 
		_eputchar('\n');
	}
	else
	{
		_setenv(info_1, "OLDPWD", _getenv(info_1, "PWD="));
		_setenv(info_1, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info_1: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info_1)
{
	char **arg_array;

	arg_array = info_1->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(const char *)arg_array; /* temp att_unused workaround */
	return (0);
}
