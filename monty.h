#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int pushVals;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;


/**
 * struct globals - struct to store global values
 * @myFile: files or opcode
 * @pushVals: values to be pushed
 * @buffer: pointer to the buffer value
 */
typedef struct globals
{
	FILE *myFile;
	int pushVals;
	char *buffers;
}globalVals;

globalVals globalVars;

void readFiles(char *file_name, stack_t **stack);
char *parseLines(char *ln, stack_t **stack, unsigned int l_num);
typedef void (*instruct_func)(stack_t **stack, unsigned int l_num);
instruct_func get_op_func(char *s);


void pall_(stack_t **stack, unsigned int l_num);
void push_(stack_t **stack, unsigned int l_num);
void pint_(stack_t **stack, unsigned int l_num);
void pop_(stack_t **stack, unsigned int l_num);
void swap_(stack_t **stack, unsigned int l_num);
void add_(stack_t **stack, unsigned int l_num);
void nop_(stack_t **stack, unsigned int l_num);
void sub_(stack_t **stack, unsigned int l_num);
void div_(stack_t **stack, unsigned int l_num);
void mul_(stack_t **stack, unsigned int l_num);
void mod_(stack_t **stack, unsigned int l_num);
void rotl_(stack_t **stack, unsigned int l_num);
void rotr_(stack_t **stack, unsigned int l_num);
void pchar_(stack_t **stack, unsigned int l_num);
void pstr_(stack_t **stack, unsigned int l_num);

void freeList(stack_t *h);
void dob_free(stack_t **stack);
void dobfree_2(stack_t **stack);
int isalpha_(int ch);

#endif 
