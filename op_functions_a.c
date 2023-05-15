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

/**
* op_pint - prints the value at the top of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	_exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
* op_pop - removes the top element of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		_exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->prev;
	if (*stack)
		(*stack)->next = NULL;
	free(top);
}

/**
* op_swap - swaps the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	int temp = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		_exit(EXIT_FAILURE);
	}

	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}
