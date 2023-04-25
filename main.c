#include "shell.h"
/**
 * main - entry
 * @ac: var
 * @av: var
 * Return: 0
 */
int main(int ac, char **av)
{
	inf_o inf[] = { INF_IN };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUFSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inf->readfd = fd;
	}
	penv_list(inf);
	r_hist(inf);
	arg_loop(inf, av);
	return (EXIT_SUCCESS);
}