#include "monty.h"

/**
 * _exit_f- exits the program
 * @mode: contains all the info to exit successfully
 * Return: void
 */
void _exit_f(int mode)
{
	info.exit_mode = mode;
	free_stack();
	free(info.str);
	if (info.file)
		fclose(info.file);
	if (!info.exit_mode)
		_exit(EXIT_SUCCESS);
	else
		_exit(EXIT_FAILURE);
}

/**
 * free_stack- frees a stack
 * Return: void
 */
void free_stack(void)
{
	stack_t	*a1 = info.stack, *a2 = a1;

	if (a1)
	{
		while (a2)
		{
			a1 = a1->prev;
			free(a2);
			a2 = a1;
		}
	}
}
