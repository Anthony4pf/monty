#include "monty.h"

/**
*_swap - swaps the top elements of the stack
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*Return: void
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr, *temp;
	int count = 0;

	ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	ptr = NULL;

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	ptr = (*stack)->next;

	temp->next = ptr->next;
	temp->prev = ptr;
	ptr->next = temp;
	ptr->prev = NULL;
	*stack = ptr;
}
