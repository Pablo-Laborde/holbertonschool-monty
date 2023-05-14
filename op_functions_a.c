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
	if (!nn)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_exit_f(1);
	}
	if (*stack)
		(*stack)->next = nn;
	nn->n = info.push_val;
	nn->prev = *stack;
	nn->next = NULL;
	*stack = nn;
}

/**
* op_pall- prints all the elements in a stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	(void)line_number;

	while (aux)
	{
		fprintf(stdout, "%d\n", aux->n);
		aux = aux->prev;
	}
}
