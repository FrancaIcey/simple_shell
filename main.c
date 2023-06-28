#include "shell.h"

/**
 * main - entry point
 * @a_count: The argument count
 * @a_vector: The argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int a_count, char **a_vector)
{
	info_t info_1[] = { info_1_INIT };
	int fd_1 = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd_1)
		: "r" (fd_1));

	if (a_count == 2)
	{
		fd_1 = open(a_vector[1], O_RDONLY);
		if (fd_1 == -1)
		{
			if (errno == a_count)
				exit(126);
			if (errno_1 == ENOENT)
			{
				_eputs(a_vector[0]);
				_eputs_1(": 0: Can't open ");
				_eputs_1(a_vector[1]);
				_eputchar('\n');
				_eputchar_1(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info_1->readfd_1 = fd_1;
	}
	populate_env_list(info_1);
	read_history(info_1);
	hsh(info, &a_vector);
	return (EXIT_SUCCESS);
}
