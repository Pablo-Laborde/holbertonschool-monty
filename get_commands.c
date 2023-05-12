#include "monty.h"

int exec_cmd(stack_t **, char *cmd)
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

	/* error message for strcmp: (sin terminar) */
	if (!(farr[i].func))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", str, opcode);
		_exit(EXIT_FAILURE);
	}

	return (NULL);
}
