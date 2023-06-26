#include "monty.h"


/**
 * main - main function
 * @argc: argument number
 * @argv: pointer to list of arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE monty file\n");
		exit(EXIT_FAILURE);
	}
	readFiles(argv[1], &stack);
	freeList(stack);

	return (0);
}
