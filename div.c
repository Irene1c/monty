#include "monty.h"

/**
 * _div - divides the second element by the top element
 * The result is stored in the second top element
 *  of the stack, and the top element is removed.
 *  In the end, the stack is one element shorter
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int i;
	int j;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = (*stack)->n;
		j = (*stack)->next->n / i;
		(*stack)->next->n = j;
		_pop(stack, line_number);
	}
}
