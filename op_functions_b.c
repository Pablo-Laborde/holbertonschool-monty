#include "monty.h"

/**
* op_add -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !(*stack) || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		_exit_f(1);
	}
	aux = *stack;
	aux->prev->n += aux->n;
	*stack = aux->prev;
	(*stack)->next = NULL;
	free(aux);
}

/**
* op_nop - doesn’t do anything
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
