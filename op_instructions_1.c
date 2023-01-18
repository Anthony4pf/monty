#include "monty.h"
	
/**
*push - push an element to the top of the stack
*@stack: address of the top element of the stack
*@line_number: line number of the monty bytecode opcode
*Return: void
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (check_if_integer(toks[1]) == 0 || toks[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(toks[1]);
	node->prev = NULL;
	node->next = NULL;

	if (*stack == NULL)
	{
		*stack = node;
		top = *stack;
		return;
	}
	node->next = *stack;
	*stack = node;
	top = *stack;
}

/**
*pall - prints all the values of a stack
*@stack: address of stack
*line_number: line number of opcode
*Return: void
*/

void pall(stack_t **stack, unsigned int line_number)
{

}











































