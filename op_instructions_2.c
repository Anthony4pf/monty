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
	int num;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	num = top->n;

	*stack = top->next;
	(*stack)->prev = NULL;
	free(top);
	(*stack)->n -= num;
}

/**
*_div - divides the second top element of the stack by the top element
*@stack: address of the top element of the stack;
*@line_number: line number of the opcode
*Return: void
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int divisor;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
	(*stack)->n /= divisor;
}


/**
*_mul - multiplies the second top element of the stack with the top element
*@stack: address of the top element of the stack
*@line_number: line number of the opcode
*Return: void
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	num = top->n;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(top);
	(*stack)->n *= num;
}















