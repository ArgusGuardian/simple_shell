#include "shell.h"

int main(void)
{
	char *input = NULL, **args;
	size_t len = 0;
	ssize_t input_len;
	int count = 0, index;

	while (1)
	{
		count++;
		index = 0;
		while ((input_len = _getline(&input, &len)) != -1)
		{
			index++;
			if (input_len == 0)
				continue;
			if (check_empty(input))
				continue;

			args = parse_arguments(input);
			if (!args)
				continue;

			check_exit(&args, &input, index);

			if (check_cd(&args, &input, index) != -1)
				continue;

			if (!check_path(args))
				exit_message(&args, &input, &count);

			execution(args, input);
		}
	}
	return (0);
}
