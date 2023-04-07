#include "monty.h"

/**
 * _push - push an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of lines
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	int number;
	stack_t *new;

	if (num == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	for (i = 0; num[i] != '\0'; i++)
	{
		if (!(num[i] >= 48 || num[i] <= 57))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	number = atoi(num);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = number;
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		new->prev = NULL;
		*stack = new;
	}
}
