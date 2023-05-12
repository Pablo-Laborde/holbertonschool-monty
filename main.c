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
	FILE		*file = NULL;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		_exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		_exit(EXIT_FAILURE);
	}
	exec_cmd(&stack, file);
	fclose(file);
	return (0);
}
