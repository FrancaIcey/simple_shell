#include "main.h"

/**
 * main - entry point
 * @a_count: The argument count
 * @a_vector: The argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int a_count, char **a_vector)
{
	infor_t infor[] = { infor_INIT };
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
			if (errno_1 == Ea_countCES)
				exit(126);
			if (errno_1 == ENOENT)
			{
				_eputs_1(a_vector[0]);
				_eputs_1(": 0: Can't open ");
				_eputs_1(a_vector[1]);
				_eputchar_1('\n');
				_eputchar_1(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		infor->readfd_1 = fd_1;
	}
	populate_env_list_1(infor);
	read_history_1(infor);
	hsh(infor, a_vector);
	return (EXIT_SUCCESS);
}
