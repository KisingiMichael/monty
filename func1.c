#include "monty.h"

/**
 * swap_ - function to swap stack elements
 * @stack: pointer to the stack
 * @l_num: opcode number
 */
void swap_(stack_t **stack, unsigned int l_num)
{
	stack_t *swapper = *stack;
	int temp;

	if (swapper == NULL || swapper->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	temp = swapper->n;
	swapper->n = swapper->next->n;
	swapper->next->n = temp;
}

/**
 * nop_ - function does nothing
 * * @stack: pointer to the stack
 * @l_num: opcode number
 */
void nop_(stack_t **stack, unsigned int l_num)
{
	(void) stack;
	(void) l_num;
}


/**
 * pchar_ - function does nothing
 * * @stack: pointer to the stack
 * @l_num: opcode number
 */
void pchar_(stack_t **stack, unsigned int l_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * isalpha
 * _ - function to check if number is alphabet
 * @ch: number to be checked
 * Return: 1 or 0
 */
int isalpha_(int ch)
{
	if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
		return (1);
	else
		return (0);
}
