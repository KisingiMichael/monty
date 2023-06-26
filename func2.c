#include "monty.h"

/**
 * pstr_ - print content of stack
 * @stack: pointer to stack
 * @l_num: opcode number
 */
void pstr_(stack_t **stack, __attribute__ ((unused))unsigned int l_num)
{
	stack_t *temp = *stack;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar((char) temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * rotl_ - function to rotate the stack
 * @stack: pointer to stack
 * @l_num: opcode number
 */
void rotl_(stack_t **stack, unsigned int l_num)
{
	stack_t *rot = *stack;
	int runner = 0;

	if (!l_num || !stack || !(*stack) || !(*stack)->next)
		return;
	runner = rot->n;
	while (rot->next)
	{
		rot = rot->next;
		rot->prev->n = rot->n;
	}
	rot->n = runner;
}

/**
 * rotr_ - function to rotate stack to the bottom
 * @stack: pointer to stack
 * @l_num: opcode number
 */
void rotr_(stack_t **stack, __attribute__ ((unused))unsigned int l_num)
{
	stack_t *btm = *stack;
	stack_t *prev;

	(void) l_num;
	if (!stack || !(*stack) || !(*stack)->next)
		return;
	while (btm->next)
		btm = btm->next;
	prev = btm->prev;
	btm->next = *stack;
	btm->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = btm;
	*stack = btm;
}
