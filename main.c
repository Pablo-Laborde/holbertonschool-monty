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
	init_info(&info);
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		_exit_f(1);
	}
	info.file = fopen(av[1], "r");
	if (!info.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		_exit_f(1);
	}
	exec_cmd();
	_exit_f(0);
}

/**
 * init_info- nulls info pointers
 * @info: structure to null data
 * Return: void
 */
void init_info(info_t *info)
{
	info->file = NULL;
	info->stack = NULL;
	info->line_number = 0;
	info->push_val = 0;
	info->str = NULL;
	info->str_len = 0;
	info->exit_mode = 0;
}
