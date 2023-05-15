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
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		_exit_f(1);
	}
	if ((*stack)->n > 127 || (*stack)->n < -128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		_exit_f(1);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
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
	aux = *stack;
	n = aux->n;
	while (aux && n != 0 && n <= 127 && n >= -128)
	{
		fprintf(stdout, "%c", n);
		aux = aux->prev;
		if (aux)
			n = aux->n;
	}
	fprintf(stdout, "\n");
}

/**
* op_rot1 -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_rot1(stack_t **stack, unsigned int line_number)
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
	stack_t *a1 = NULL, *a2 = NULL;

	(void)line_number;
	if (stack)
	{
		a1 = *stack;
		if (a1 && a1->prev)
		{
			while (a1)
			{
				a2 = a1->next;
				a1->next = a1->prev;
				a1->prev = a2;
				a1 = a1->next;
			}
		}
	}
}
