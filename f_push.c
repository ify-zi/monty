#include "monty.h"

/**
 * f_push - function that adds element to top of stack
 * @stack: pointer to the top
 * @line_number: command line number
 * @tmp: Pointer to opcode
 * Return: nothing, but exit_failure if it fails
 */
void f_push(stack_t **stack, unsigned int line_number, char *tmp)
{
	stack_t *head;
	(void)line_number;

	if (tmp == NULL || _isdigit(tmp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		f_free(*stack);
		exit(EXIT_FAILURE);
		if (_isdigit(tmp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			f_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	head->n = atoi(tmp);
	head->next = NULL;
	head->prev = NULL;
	if (*stack)
	{
		head->next = *stack;
		(*stack)->prev = head;
		*stack = head;
	}
	*stack = head;
}
