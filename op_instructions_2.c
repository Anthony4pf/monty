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

	if (*stack == NULL || (*stack)->next == NULL)
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

/**
*_add - adds the top two elements of the stack
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*Return: void
*/

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL, *temp = NULL;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	ptr = (*stack)->next;

	sum = temp->n + ptr->n;
	ptr->n = sum;

	*stack = ptr;
	(*stack)->prev = NULL;
	free(temp);
	temp = NULL;
}

/**
*_sub - subtracts the top element of the stack from the second top element
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*Return: void
*/

void _sub(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	temp = top->n;

	*stack = top->next;
	(*stack)->prev = NULL;
	free(top);
	(*stack)->n -= temp;
}




















