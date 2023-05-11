#include "monty.h"

void (*get_op_func(char *str))
{
	int			i = 0;
	fae_t		farr[] = {
		{"push", op_push},
		{"pal", op_pal},
		{NULL, NULL}
	};

	while (farr[i].func)
	{
		if (strcmp(farr[i].func, str) == 0)
			return (farr[i].f);
			i++;
	}
	/* code for strcmp: (sin terminar) */
	/*
	if (!(op_codes[index].opcode))
	{
		fprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, token[0]);
		_exit(EXIT_FAILURE);
	}
	*/
	return (NULL);
}
