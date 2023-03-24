#include "monty.h"

char *num;

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: nothing
 */
int main(int ac, char *av[])
{
	char *line = NULL;
	size_t len = 0;
	FILE *file;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *tok;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		tok = strtok(line, " \n\t");
		num = strtok(NULL, " \n\t");
		_opcode(&stack, line_number, file, tok);
	}
	fclose(file);
	free(tok);
	free_stack(&stack);
	return (0);
}
