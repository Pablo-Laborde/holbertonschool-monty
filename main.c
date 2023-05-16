#include "monty.h"

/**
 * main - Short description
 * @ac: first member
 * @av: second member
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	init_info();
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		_exit_f(1);
	}
	info.file = fopen(av[1], "r");
	if (!info.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		_exit_f(1);
	}
	exec_cmd();
	_exit_f(0);
}

/**
 * init_info- nulls info pointers
 * Return: void
 */
void init_info(void)
{
	info.file = NULL;
	info.stack = NULL;
	info.line_number = 0;
	info.push_val = 0;
	info.str = NULL;
	info.str_len = 0;
	info.exit_mode = 0;
}
