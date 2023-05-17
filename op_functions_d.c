#include "monty.h"

/**
* op_queue -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_queue(stack_t **stack, unsigned int line_number)
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
				*stack = a1;
				a1 = a1->next;
			}
		}
	}
}

/**
* op_stack -  adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: as name says
* Return: void
*/
void op_stack(stack_t **stack, unsigned int line_number)
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
				*stack = a1;
				a1 = a1->next;
			}
		}
	}
}