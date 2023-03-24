#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: points to the head of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;
	stack_t *current;

	if (stack != NULL)
	{
		current = *stack;
	}
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
