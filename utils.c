#include "monty.h"

/**
 * isnumber - function to check if string is a number
 * @s: pointer to a string to be checked
 * Return: 1 or 0
 */
int isnumber(char *s)
{
	unsigned int n = 0;

	if (!s)
		return (0);
	while (s[n])
	{
		if (s[0] == '-')
		{
			++n;
			continue;
		}
		if (s[n] < 48 && s[n] > 58)
			return (0);
		++n;
	}
	return (1);
}

/**
 * parse_line - function to parse a ine to command
 * @ln: line to be parsed
 * @stack: pointer to stack
 * @l_num: opcode number
 *
 * Return: 1 or 0
 */
char *parseLines(char *ln, stack_t **stack, unsigned int l_num)
{
	char *opcode, *arg, *push = "push";
	(void)stack;

	opcode = strtok(ln, "\n ");
	if (opcode == NULL)
		return (NULL);
	if (strcmp(opcode, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1)
			globalVars.pushVals = atoi(arg);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", l_num);
			exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}


/**
 * get_op_func - function to get the function based on the opcodes
 * @s: pointer to the opcode
 *
 * Return: NULL or function
 */
instruct_func get_op_func(char *s)
{
	int n = 0;
	instruction_t instructions[] = {
		{"push", push_},
		{"pall", pall_},
		{"pint", pint_},
		{"pop", pop_},
		{"swap", swap_},
		{"add", add_},
		{"nop", nop_},
		{"sub", sub_},
		{"mul", mul_},
		{"div", div_},
		{"mod", mod_},
		{"pstr", pstr_},
		{"pchar", pchar_},
		{"rotl", rotl_},
		{"rotr", rotr_},
		{NULL, NULL},
	};
	while (instructions[n].f != NULL && strcmp(instructions[n].opcode, s) != 0)
		++n;
	return (instructions[n].f);
}


/**
 * read_file - reads files bycode and commnads
 * @file_name: file name
 * @stack: pointer to stack
 */
void readFiles(char *file_name, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int check, read, line_count = 1;
	instruct_func s;

	globalVars.myFile = fopen(file_name, "r");

	if (globalVars.myFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&globalVars.buffers, &i, globalVars.myFile)) != -1)
	{
		line = parseLines(globalVars.buffers, stack, line_count);

		if (line == NULL || line[0] == '#')
		{
			++line_count;
			continue;
		}

		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}

		s(stack, line_count);
		++line_count;
	}
	free(globalVars.buffers);
	check = fclose(globalVars.myFile);
	if (check == -1)
		exit(-1);
}
