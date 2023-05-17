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
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		_exit_f(1);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		_exit_f(1);
	}
	aux = *stack;
	aux->prev->n %= aux->n;
	*stack = aux->prev;
	(*stack)->next = NULL;
	free(aux);
}

/**
* op_pchar -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		_exit_f(1);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		_exit_f(1);
	}
	dprintf(STDOUT_FILENO, "%c\n", (*stack)->n);
}

/**
* op_pstr -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	int n;

	(void)line_number;
	if (stack && *stack)
	{
		aux = *stack;
		n = aux->n;
		while (aux && n > 0 && n <= 127)
		{
			dprintf(STDOUT_FILENO, "%c", n);
			aux = aux->prev;
			if (aux)
				n = aux->n;
		}
	}
	dprintf(STDOUT_FILENO, "\n");
}

/**
* op_rotl -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *a0 = NULL, *a1 = NULL, *a2 = NULL;

	(void)line_number;
	if (stack)
	{
		a1 = *stack;
		if (a1 && a1->prev)
		{
			a2 = a1->prev;
			a0 = a2;
			while (a2->prev)
				a2 = a2->prev;
			a1->next = a2;
			a1->prev = NULL;
			a2->prev = a1;
			*stack = a0;
		}
	}
}

/**
* op_rotr -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *a0 = NULL, *a1 = NULL, *a2 = NULL;

	(void)line_number;
	if (stack)
	{
		a1 = *stack;
		if (a1 && a1->prev)
		{
			while (a1->prev)
				a1 = a1->prev;
			a2 = a1->next;
			a0 = *stack;
			a2->prev = NULL;
			a0->next = a1;
			a1->next = NULL;
			a1->prev = a0;
			*stack = a1;
		}
	}
}
