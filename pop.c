#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else if ((*stack)->next != NULL)
	{
		temp = (*stack)->next;
		temp->prev = NULL;
		free(*stack);
		*stack = temp;
	}
}
