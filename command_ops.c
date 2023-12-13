#include "monty.h"

/**
 * cget - command getter
 * @f_r: char representation pointer
 * @t: line number
 * @lt: stack
 * Return: Void
 */

void (*cget(char *f_r, unsigned int t, stack_t **lt))(stack_t**, unsigned int)
{
	int num;

	instruction_t command[] = {
		{"pint", f_pint},
		{"pall", f_pall},
		{"pop", f_pop},
		{NULL, NULL}
	};
	for (num = 0; command[num].opcode != NULL; num++)
	{
		if (strcmp(command[num].opcode, f_r) == 0)
		{
			return (command[num].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", t, f_r);
	fclose(file);
	f_free(*lt);
	exit(EXIT_FAILURE);
}
