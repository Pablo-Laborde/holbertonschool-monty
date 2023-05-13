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
	(void)line_number;

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
	(void)line_number;

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
void op_pint(stack_t **stack, unsigned int n)
{
	if(!stack || !(*stack))
	{
	fprintf(stderr, "L%d: can't pint, stack empty\n", n);
	_exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d", (*stack)->n);
}

/**
* op_pint - prints the value at the top of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_pop(stack_t **stack, unsigned int n)
{
	(void)n;

	if(!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack", n);
		_exit(EXIT_FAILURE);
	}
	top = *stack;

	if((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	free(top);
}
