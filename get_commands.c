#include "monty.h"

/**
* exec_cmd- executes the commands in the file
* @stack: stack
* @fd: file to read from
* Return: void
*/
void exec_cmd(stack_t **stack, FILE *file)
{
	int						i;
	//unsigned int	line_number = 0;
	char					*str = NULL,
								*token = NULL;
	size_t				len = 0;
	void (*f)(stack_t **, unsigned int) = NULL;
	(void)f;
	(void)stack;

	value = 0;
	while (getline(&str, &len, file) != -1)
	{
		token = str;
		i = 0;
		while (token[i] <= 32)
			i++;
		strtok(&token[i], " \t\n");
		printf("%s\n", token);
	}
}

/**
* get_func- looks for the correct function
* @name: name of the function tobe loked
* Return: function pointer if succesfull, NULL otherwise
*/
void (*get_func(char *name))(stack_t **, unsigned int)
{
	int			i = 0;
	instruction_t	arr[] = {
		{"push", op_push},
		{"pal", op_pal},
		{NULL, NULL}
	};

	while (arr[i].opcode)
	{
		if (strcmp(arr[i].opcode, name))
			return (arr[i].f);
		i++;
	}
	return (NULL);
}
