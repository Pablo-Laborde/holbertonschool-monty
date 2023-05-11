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
	return (NULL);
}
