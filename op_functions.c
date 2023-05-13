#include "monty.h"

/**
* op_push- adds an elemnt to hte stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *nn = NULL;

	nn = malloc(sizeof(stack_t));
	if (nn)
	{
		if (*stack)
			(*stack)->next = nn;
		nn->n = value;
		nn->prev = *stack;
		nn->next = NULL;
		*stack = nn;
	}
}

/**
* op_pal- prints all the elements in a stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_pal(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->prev;
	}
}

/**
* op_pint - prints the value at the top of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
/*
void op_pint(stack_t **stack, unsigned int line_number)
{
	if(!stack || !(*stack))
	{
	fprintf(stderr, "L<line_number>: can't pint, stack empty\n", n);
	_exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d", stack->n);
}
*/