#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

								/* structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s- structure of data
 * @file: file to read
 * @stack: stack
 * @line_number: as name says
 * @push_val: value to push into the stack
 * @str: line red
 * @str_len: length of the line red
 * @exit_mode: status of exit
 */
typedef struct info_s
{
	FILE					*file;
	stack_t				*stack;
	unsigned int	line_number;
	int						push_val;
	char					*str;
	size_t				str_len;
	int						exit_mode;
} info_t;

								/* variables */

info_t info;

								/* prototypes */

/* main.c */
void init_info(void);

/* fexit.c */
void _exit_f(int mode);
void free_stack(void);

/* get_commands.c */
void exec_cmd(void);
void (*get_func(char *name))(stack_t **, unsigned int);
int check_number(char *str);

/* op_functions.c */
/* a */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
/* b */
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
/* c */
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);
/* d */
void op_queue(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);

#endif
