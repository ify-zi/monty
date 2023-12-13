#include "monty.h"

/**
 *  main - main function
 *  @argc: args count
 *  @argv: args vector
 *  Return: Void
 */

int main(int argc, char *argv[])
{
	stack_t *top = NULL;
	char  *str = NULL, *tmp, *command_args[2];
	size_t bufsize = 1024, line_num = 0;
	ssize_t read_line;
	void (*command_func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		read_line = getline(&str, &bufsize, file);
		if (read_line ==  -1)
			break;
		line_num++;
		command_args[0] = strtok(str, "\n ");
			if (command_args[0] == NULL)
				f_empty(&top, line_num);
			else if (strcmp("push", command_args[0]) == 0)
			{
				tmp = strtok(NULL, "\n ");
				f_push(&top, line_num, tmp);
			}
			else if (command_args[0] != NULL && command_args[0][0] != '#')
			{
				command_func = cget(command_args[0], line_num, &top);
					if (command_func == NULL && line_num == 0)
					{
						fprintf(stderr, "L%ld: unknown instruction %s\n",
								line_num, command_args[0]), exit(EXIT_FAILURE);
					}
				command_func(&top, line_num);
			}
	}
	fclose(file), free(str), f_free(top);
	return (0);
}
