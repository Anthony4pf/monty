#include "monty.h"

/**
*_mod - rest of the division of the second top elem of the stack by the top elem
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*Return: void
*/

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int divisor;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	divisor = temp->n;

	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
	(*stack)->n %= divisor;
}
