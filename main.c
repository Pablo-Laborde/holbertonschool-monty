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
	if (ac != 2)
	{
		fprintf(STDERR_FILENO, "USAGE: monty file");
		_exit(EXIT_FAILURE);
	}

	/* open file ... or relocate code for open file: */
	if (fp == NULL)
	{
		fprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		_exit(EXIT_FAILURE);
	}

  /* code for strcmp: (sin terminar) */
	if (!(op_codes[index].opcode))
	{
		fprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, token[0]);
		_exit(EXIT_FAILURE);
	}
	return (0);
}
