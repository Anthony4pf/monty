#include "monty.h"

/**
*main - execute the opcode instructions of the monty bytecode
*@argc: argument counter
*@argv: argument vector
*Return: 0 if successful or Error if otherwise
*/

int main(int argc, char *argv[])
{
	FILE *file;
	unsigned int line_num = 1, i;
	char line[BUFSIZ];
	void (*f)(stack_t **, unsigned int);
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, BUFSIZ, file)) != NULL)
	{
		if (strspn(line, " \t\r\n") == strlen(line))
		{
			line_num++;
			continue;
		} toks = tokenize_string(line);
		f = get_instruction(toks[0]);
		if (f != NULL)
		{
			f(&stack, line_num);
		} else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, toks[0]);
			exit(EXIT_FAILURE);
		} for (i = 0; toks[i]; i++)
			free(toks[i]);
		free(toks);
		line_num++;
	}
	free_stack(&stack);
	fclose(file);
	return (0);
}
