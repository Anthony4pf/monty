#include "monty.h"

/**
*_push - push an element to the top of the stack
*@stack: address of the top element of the stack
*@line_number: line number of the monty bytecode opcode
*Return: void
*/

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (toks[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!check_if_integer(toks[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(toks[1]);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		*stack = new_node;
	}
}
/**
*_pall - prints all the values of a stack
*@stack: address of stack
*@line_number: line number of opcode
*Return: void
*/

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;
	ptr = *stack;

	while (ptr != NULL)
	{
		printf("%u\n", ptr->n);
		ptr = ptr->next;
	}
}



































