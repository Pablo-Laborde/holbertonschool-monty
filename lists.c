#include "monty.h"

#define buffsize 1024

/**
 * cmds_inter- reads input andtrans forms it into a list
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

/**
 * str_to_ll- makes a linked list of the substring
 * @buf: buffer where is the input
 * @dem: delimeter
 * Return: a linked list of the string passed
 */
l_node *str_to_ll(char *buf, char dem)
{
	int	i = 0, f, k = 0, len;
	l_node	*l = NULL, *aux = NULL;

	if (!buf)
		return (NULL);
	while (buf[i] != '\0')
	{
		if (buf[i] > 32 && buf[i] != dem)
		{
			f = i;
			while (buf[f] != '\0' && buf[f] != dem)
				f++;
			len = f - i;
			aux = malloc(sizeof(l_node));
			if (!aux)
				return (free_list(l, 1));
			aux->next = NULL;
			aux->str = NULL;
			aux->str = malloc(sizeof(char) * (len + 1));
			if (!aux->str)
			{
				free(aux);
				return (free_list(l, 1));
			}
			for (k = 0; i < f; i++, k++)
				aux->str[k] = buf[i];
			aux->str[k] = '\0';
			if (!l)
				l = aux;
			else
				add_end(l, aux);
		}
		else
			i++;
	}
	return (l);
}

/**
 * add_end- adds a node at the end of the list
 * @l: original list
 * @a: node to be added
 * Return: void
 */
void add_end(l_node *l, l_node *a)
{
	l_node	*aux = NULL;

	if (l)
	{
		aux = l;
		while (aux->next)
			aux = aux->next;
		aux->next = a;
	}
}

/**
 * free_list- frees a words list
 * @l: words list
 * @flag: if 0 does't free words, frees otherwise
 * Return: NULL
 */
void *free_list(l_node *l, int flag)
{
	if (l)
	{
		free_list(l->next, flag);
		if (flag)
			free(l->str);
		free(l);
	}
	return (NULL);
}

/**
 * node_count- counts the amount of words
 * @l: list of words
 * Return: the amount of words
 */
int node_count(l_node *l)
{
	if (!l)
		return (0);
	else
		return (1 + node_count(l->next));
}

/**
 * print_list- prints a list of words
 * @l: list of words
 * Return: void
 */
void print_list(l_node *l)
{
	if (l)
	{
		printf("%s\n", l->str);
		print_list(l->next);
	}
}
