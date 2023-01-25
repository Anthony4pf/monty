#include "monty.h"

/**
*_mod - rest of the division of the second top elem by the top elem
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

/**
*_pchar - prints the char at the top of the stack, followed by a new line
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*Return: void
*/

void _pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;

	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", num);
}

/**
*_pstr - print the string starting at the top of the stack
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*Return: void
*/

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	ptr = *stack;
	while (ptr != NULL)
	{
		if (ptr->n <= 0 || ptr->n > 127)
		{
			break;
		}

		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
	ptr = NULL;
}

/**
*_rotl -  rotates the tail to the top
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*Return: void
*/

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		;
	}
	else
	{
		first = last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		*stack = first->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}
/**
*_rotr - rotates the stack to the bottom
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*/

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;
	(void)line_number;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
