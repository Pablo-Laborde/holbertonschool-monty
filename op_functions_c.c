#include "monty.h"

/**
* op_mod -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !(*stack) || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		_exit_f(1);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_exit_f(1);
	}
	aux = *stack;
	aux->prev->n %= aux->n;
	*stack = aux->prev;
	(*stack)->next = NULL;
	free(aux);
}
