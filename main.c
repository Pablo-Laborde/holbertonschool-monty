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
	FILE	*fd;
	l_node	*l = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		_exit(EXIT_FAILURE);
	}

	/* open file ... or relocate code for open file: */
	fd = fopen(av[1], O_RDONLY);
	/*
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		_exit(EXIT_FAILURE);
	}
	*/
	l = cmds_inter(fd);
	print_list(l);

  /* code for strcmp: (sin terminar) */
	/*
	if (!(op_codes[index].opcode))
	{
		fprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, token[0]);
		_exit(EXIT_FAILURE);
	}
	*/
	fclose(fd);
	return (0);
}

#define buffsize 1024

/**
 * cmds_inter - reads input andtrans forms it into a list
 * @fd: stream to read
 * Return: list of commands
 */
l_node *cmds_inter(int fd)
{
	int     i;
	char	buf[buffsize];
	ssize_t bs;
	l_node  *l = NULL;

	bs = read(fd, buf, buffsize);
	buf[bs] = '\0';
	if (bs == -1)
		return (NULL);
	l = str_to_ll(buf, '\n');
	return (l);
}
