#include "monty.h"

/**
 * _nop - doesn't do anything
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void _nop(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	(void) line_number;
}
