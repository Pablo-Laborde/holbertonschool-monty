#include "monty.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        fprintf(STDERR_FILENO, "USAGE: monty file");
        _exit(EXIT_FAILURE);
    }
    
}