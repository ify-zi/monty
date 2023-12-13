#include "monty.h"

/**
 * cget - command getter
 * @f_rep: char representation pointer
 * @l_int: line number
 * @list: stack
 * Return: Void
 */

void (*cget(char *f_rep, unsigned int l_int, stack_t **list))(stack_t**, unsigned int)
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
		if (strcmp(command[num].opcode, f_rep) == 0)
		{
			return (command[num].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l_int, f_rep);
	fclose(file);
	f_free(*list);
	exit(EXIT_FAILURE);
}
