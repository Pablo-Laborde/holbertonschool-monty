#include "monty.h"

/**
* exec_cmd- executes the commands in the file
* @stack: stack
* @file: file to read from
* Return: void
*/
void exec_cmd(stack_t **stack, FILE *file)
{
	int						i;
	unsigned int	line_number = 0;
	char					*str = NULL,
								*token = NULL;
	size_t				len = 0;
	void (*f)(stack_t **, unsigned int) = NULL;
	stack_t *aux;

	value = 0;
	while (getline(&str, &len, file) != -1)
	{
		line_number++;
		token = str;
		i = 0;
		while (token[i] && token[i] <= 32)
			token = &token[i + 1];
		f = get_func(token, line_number);
		free(str);
		str = NULL;
		if (f)
			f(stack, line_number);
		f = NULL;
	}
	free(str);
}

/**
* get_func- looks for the correct function
* @name: name of the function tobe loked
* @n: as name says
* Return: function pointer if succesfull, NULL otherwise
*/
void (*get_func(char *name, unsigned int n))(stack_t **, unsigned int)
{
	int			i = 0;
	char		*val = NULL;
	instruction_t	arr[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};

	if (name)
	{
		val = strtok(name, " \t\n");
		while (arr[i].opcode)
		{
			if (!strcmp(arr[i].opcode, val))
			{
				if (i == 0)
				{
					val = strtok(NULL, " \t\n");
					if (check_number(val))
					{
						fprintf(stderr, "L%u: usage: push integer\n", n);
						_exit(EXIT_FAILURE);
					}
					value = atoi(val);
				}
				return (arr[i].f);
			}
			i++;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", n, val);
	_exit(EXIT_FAILURE);
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
