#include "monty.h"

/**
 * push_ - function to push an element into stack
 * @stack: a stack
 * @l_num: opcode number in a stack
 */
void push_(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *atop;
	(void)l_num;

	atop = malloc(sizeof(stack_t));
	if (atop == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed \n");
		exit(EXIT_FAILURE);
	}
	atop->n = globalVars.pushVals;
	atop->next = *stack;
	atop->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = atop;
	*stack = atop;
}

/**
 * pall_ - function to print functions
 * @stack: a stack
 * @l_num: opcode number in a stack
 */
void pall_(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *printer;

	printer = *stack;

	while (printer != NULL)
	{
		printf("%d\n", printer->n);
		printer = printer->next;
	}
}

/**
 * pint_ - print top of stack
 * @stack: a stack
 * @l_num: opcode number in a stack
 */
void pint_(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *printer;

	printer = *stack;

	if (printer == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", printer->n);
}

/**
 * pop_ - function to pop out elements fom a stack
 * @stack: a stack
 * @l_num: opcode number in a stack
 */
void pop_(stack_t **stack, unsigned int l_num)
{
	stack_t *node;

	node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't POP an empty stack\n", l_num);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}

/**
 * freeList - frees a stack list
 * @h: pointer to head of the list
 */
void freeList(stack_t *h)
{
	stack_t *temp;

	while (h != NULL)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}
