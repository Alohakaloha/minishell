#include "../includes/minishell.h"

/*
Whitespace is being skipped in bash and not added to the history,
even tho there is a working command working after it.
That is being noted but we decided not to implement because of
undefined behaviour.
*/

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 1)
	{
		printf("%s doesn't need more arguments.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		info.readline = readline("Mini_hell\U0001F34C\U0001F412 ");
		info.commands = ft_split(info.readline, ' ');
		printf("first_command: %s\n", info.commands[1]);
		if (ft_strlen(info.readline) != 0)
		{
			add_history(info.readline);
			free(info.readline);
		}
		free(info.commands);
	}
	return (0);
}
