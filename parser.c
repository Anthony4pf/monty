#include "monty.h"

/**
*tokenize_string - separate a string into different tokens
*@str: string to be tokenized from the terminal
*Return: array of tokens
*/

char **tokenize_string(char *str)
{
	char *str_copy, *token;
	char **tokens;
	const char *delim = " \n";
	int num_tokens = 0, i = 0;

	str_copy = malloc(sizeof(char) * strlen(str));
	if (str_copy == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(str_copy, str);
	token = strtok(str, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	tokens = malloc(sizeof(char *) * num_tokens + 1);
	if (tokens == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		free(str_copy);
		exit(EXIT_FAILURE);
	}
	token = strtok(str_copy, delim);
	while (token != NULL)
	{
		tokens[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (tokens[i] == NULL)
		{
			fprintf(stderr, "malloc failed\n");
			for (i = i - 1; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			free(str_copy);
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[i], token);

		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	free(str_copy);
	return (tokens);
}
