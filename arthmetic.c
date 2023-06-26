#include "monty.h"

/**
 * add_ - function to add at top of the stack
 * @stack: pointer to stack
 * @l_num: opcode numbers
 */
void add_(stack_t **stack, unsigned int l_num)
{
	stack_t *temp = *stack;
	int sum = 0;
	int i = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	pop_(stack, l_num);
	(*stack)->n = sum;
}

/**
 * sub_ - function to add at top of the stack
 * @stack: pointer to stack
 * @l_num: opcode numbers
 */
void sub_(stack_t **stack, unsigned int l_num)
{
	stack_t *temp = *stack;
	int sub = 0;
	int i = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n + (*stack)->n;
	pop_(stack, l_num);
	(*stack)->n = sub;
}

/**
 * div_ - function to divide at top of the stack
 * @stack: pointer to stack
 * @l_num: opcode numbers
 */
void div_(stack_t **stack, unsigned int l_num)
{
	int division = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: cant div, stack too short \n", l_num);
		free(globalVars.buffers);
		fclose(globalVars.myFile);
		freeList(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", l_num);
		free(globalVars.buffers);
		fclose(globalVars.myFile);
		freeList(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		division = (*stack)->n;
		pop_(stack, l_num);
		(*stack)->n /= division;
	}
}

/**
 * mul_ - function to divide at top of the stack
 * @stack: pointer to stack
 * @l_num: opcode numbers
 */
void mul_(stack_t **stack, unsigned int l_num)
{
	int num = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: cant mul, stack too short \n", l_num);
		free(globalVars.buffers);
		fclose(globalVars.myFile);
		freeList(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		num = (*stack)->n;
		pop_(stack, l_num);
		(*stack)->n *= num;
	}
}

/**
 * mod_ - function to find remainder
 * @stack: pointer to stack
 * @l_num: opcode numbers
 */
void mod_(stack_t **stack, unsigned int l_num)
{
	int mod;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: cant mod, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}
	mod = ((*stack)->next->n) % ((*stack)->n);
	pop_(stack, l_num);
	(*stack)->n = mod;
}
