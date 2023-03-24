#include "monty.h"

/**
 * _pint - prints the value on top of the stack
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		break;
	}
}
