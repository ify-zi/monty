#include "monty.h"

/**
 * f_pint -prints top
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appear
 * Return: nothing upon success,else  EXIT_FAILURE 
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		f_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
