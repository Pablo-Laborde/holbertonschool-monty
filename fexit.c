#include "monty.h"

/**
 * _exit_f- exits the program
 * @info: contains all the info to exit successfully
 * Return: void
 */
void _exit_f(info_t *info)
{
	free_stack(info->stack);
	free(info->str);
	if (info->file)
		fclose(info->file);
	if (!info->exit_mode)
		_exit(EXIT_SUCCESS);
	else
		_exit(EXIT_FAILURE);
}

/**
 * free_stack- frees a stack
 * @stack: stack to be freed
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t	*a1 = stack, *a2 = a1;

	if (stack)
	{
		while (a2)
		{
			a1 = a1->prev;
			free(a2);
			a2 = a1;
		}
	}
}
