#include "monty.h"

/**
 * _opcode - get the required opcode
 * @stack: pointer to the stack
 * @line_n: number of lines
 * @file: file to be read
 * @line: line to read from
 */
void _opcode(stack_t **stack, unsigned int line_n, FILE *file, char *line)
{
	instruction_t opc[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};
	unsigned int i = 0;

	if (*line == '#')
		return;

	while (opc[i].opcode != NULL)
	{
		if (strcmp(opc[i].opcode, line) == 0)
		{
			opc[i].f(stack, line_n);
			return;
		}
		i++;
	}
	if (opc[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, line);
		fclose(file);
		free(line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
