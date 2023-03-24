#include "monty.h"

/**
 * _sub - subtracts the top element from the second element
 * The result is stored in the second top element
 *  of the stack, and the top element is removed.
 *  In the end, the stack is one element shorter
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int i;
	int j;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = (*stack)->n;
		j = (*stack)->next->n - i;
		(*stack)->next->n = j;
		_pop(stack, line_number);
	}
}
