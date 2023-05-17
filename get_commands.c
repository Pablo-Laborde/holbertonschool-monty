#include "monty.h"

/**
 * exec_cmd- executes the commands in the file
 * Return: void
 */
void exec_cmd(void)
{
	int						i;
	char					*token = NULL;
	void (*f)(stack_t **, unsigned int) = NULL;

	while (getline(&(info.str), &(info.str_len), info.file) != -1)
	{
		info.line_number++;
		token = info.str;
		i = 0;
		while (token[i] && token[i] <= 32)
			token = &token[i + 1];
		if (token[i] && token[i] != '#')
			f = get_func(token);
		free(info.str);
		info.str = NULL;
		if (f)
			f(&(info.stack), info.line_number);
		f = NULL;
	}
	free(info.str);
	info.str = NULL;
}

/**
 * get_func- looks for the correct function
 * @name: name of the function tobe loked
 * Return: function pointer if succesfull, NULL otherwise
 */
void (*get_func(char *name))(stack_t **, unsigned int)
{
	int			i = 0;
	char		*val = NULL;
	instruction_t	arr[] = {
		{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
		{"pop", op_pop}, {"swap", op_swap},	{"add", op_add},
		{"nop", op_nop}, {"sub", op_sub}, {"div", op_div},
		{"mul", op_mul}, {"mod", op_mod}, {"pchar", op_pchar},
		{"pstr", op_pstr}, {"rotl", op_rotl}, {"rotr", op_rotr},
		{"queue", op_queue}, {"stack", op_stack},
		{NULL, NULL}
	};

	if (name)
	{
		val = strtok(name, " \t\n$");
		while (arr[i].opcode)
		{
			if (!strcmp(arr[i].opcode, val))
			{
				if (i == 0)
				{
					val = strtok(NULL, " \n\t$");
					if (check_number(val))
					{
						dprintf(STDERR_FILENO, "L%u: usage: push integer\n", info.line_number);
						_exit_f(1);
					}
					info.push_val = atoi(val);
				}
				return (arr[i].f);
			}
			i++;
		}
	}
	dprintf(2, "L%u: unknown instruction %s\n", info.line_number, val);
	_exit_f(1);
	return (NULL);
}

/**
 * check_number- check if str is a number
 * @str: string to be checked
 * Return: 0 if true, 1 if false
 */
int check_number(char *str)
{
	int	i = 0, flag = 0;

	if (!str)
		return (1);
	if (str[0] == '-')
		i = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			flag = 1;
			break;
		}
		i++;
	}
	return (flag);
}
