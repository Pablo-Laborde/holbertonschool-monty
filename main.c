#include "monty.h"

/**
 * main - Short description
 * @ac: first member
 * @av: second member
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	int		fd;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		_exit(EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		_exit(EXIT_FAILURE);
	}
	exec_cmd(&stack, fd);
	close(fd);
	return (0);
}
