#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
 #include <fcntl.h>
 
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
 * struct word_list- a list of words
 *
 * @str: the string
 * @next: next node
 */
typedef struct word_list
{
	char *str;
	struct word_list *next;
} l_node;

/**
* struct function_array_element- elemnt of a function array
*
* @func: name of function
* @f: pointer to function
*/
typedef struct function_array_element
{
	char *func;
	void *f;
} fae_t;


								/* variables */


								/* prototypes */
/* get_commands.c */
void (*get_op_func(char *str));

/* op_functions.c */
stack_t *op_push(stack_t *s, int val);
void op_pal(stack_t *s);

/* lists.c */
l_node *cmds_inter(int fd);
l_node *str_to_ll(char *buf, char dem);
void add_end(l_node *l, l_node *a);
void *free_list(l_node *l, int flag);
int node_count(l_node *l);
void print_list(l_node *l);

#endif
