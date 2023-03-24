#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int i;
	int j;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = (*stack)->n;
		j = (*stack)->next->n + i;
		(*stack)->next->n = j;
		_pop(stack, line_number);
	}
}
