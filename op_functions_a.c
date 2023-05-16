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
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
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
		dprintf(STDOUT_FILENO, "%d\n", aux->n);
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
	dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
	_exit_f(1);
	}
	dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
* op_pop - removes the top element of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		_exit_f(1);
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
	stack_t *a1 = NULL, *a2 = NULL, *a3 = NULL;

	if (!stack || !(*stack) || !(*stack)->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		_exit_f(1);
	}

	a1 = *stack;
	a2 = a1->prev;
	a3 = a2->prev;
	a1->next = a2;
	a1->prev = a3;
	a2->next = NULL;
	a2->prev = a1;
	if (a3)
		a3->next = a1;
	*stack = a2;
}
