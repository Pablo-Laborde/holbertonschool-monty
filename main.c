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
	info_t	info;

	init_info(&info);
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		_exit_f(&info);
	}
	info.file = fopen(av[1], "r");
	if (!info.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		_exit_f(&info);
	}
	exec_cmd(&info);
	fclose(info.file);
	return (0);
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
	info->str = NULL;
	info->str_len = 0;
}
