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
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
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

/**
* op_sub -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !(*stack) || !(*stack)->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		_exit_f(1);
	}
	aux = *stack;
	aux->prev->n -= aux->n;
	*stack = aux->prev;
	(*stack)->next = NULL;
	free(aux);
}

/**
* op_div -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !(*stack) || !(*stack)->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		_exit_f(1);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		_exit_f(1);
	}
	aux = *stack;
	aux->prev->n /= aux->n;
	*stack = aux->prev;
	(*stack)->next = NULL;
	free(aux);
}

/**
* op_mul -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !(*stack) || !(*stack)->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		_exit_f(1);
	}
	aux = *stack;
	aux->prev->n *= aux->n;
	*stack = aux->prev;
	(*stack)->next = NULL;
	free(aux);
}
