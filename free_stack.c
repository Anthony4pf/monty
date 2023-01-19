#include "monty.h"

/**
*free_stack - free the stack frames
*@stack: head pointer of the stack
*Return: void
*/

void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (*stack  == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		*stack = temp->next;
		free(temp);
		temp = *stack;
	}
	*stack = NULL;
}
