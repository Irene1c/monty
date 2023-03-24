#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next = *stack;
		(*stack)->prev = temp;
		temp->prev = NULL;
		(*stack)->next->prev = *stack;
		*stack = temp;
	}
}
