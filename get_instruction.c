#include "monty.h"

/**
*get_instruction - find the instruction for the opcode specified
*@opc: opcode for the instruction
*Return: NULL or the instruction
*/

void (*get_instruction(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t funcs[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{"swap", _swap},
	{"add", _add},
	{"nop", _nop},
	{"sub", _sub},
	{NULL, NULL}
	};

	unsigned int i = 0;

	while (funcs[i].opcode)
	{
		if (strcmp(funcs[i].opcode, opc) == 0)
		{
			return (funcs[i].f);
		}
		i++;
	}
	return (NULL);
}
