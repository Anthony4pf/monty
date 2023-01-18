#include "monty.h"

/**
*get_instruction - find the instruction for the opcode specified
*@opc - opcode for the instruction
*Return: NULL or the instruction
*/

void (*get_instruction(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t funcs[] = {
	{"push", push},
	{"pall", print_all},
	{NULL, NULL}
	};

	unsigned int i = 0;

	while (funcs[i].opcode)
	{
		if (funcs[i].opcode[0] == (*opc))
		{
			return (funcs[i].f);
		}
		i++;
	}
	return (NULL);
}
