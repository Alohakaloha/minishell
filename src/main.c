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
	initialize_info(&info);
	while(1)
	{
		info.readline = readline("Mini_hell\U0001F34C\U0001F412 ");
		count_qoutes(&info);
//		printf("check the quotes!\n");
		printf("double_quotes: %d single qoutes: %d\n", info.d_qoutes, info.s_qoutes);
		if (info.d_qoutes != 0 || info.s_qoutes != 0)
		{
			info.split_qoutes = bananasplit(&info);
			if (info.split_qoutes == NULL)
				return (1);
			printf("split_qoutes: %s\n", info.split_qoutes[0]);
			printf("split_qoutes: %s\n", info.split_qoutes[1]);
			printf("split_qoutes: %s\n", info.split_qoutes[2]);
			free(info.split_qoutes);
		}
/* 		else
		{
			info.commands = ft_split(info.readline, ' ');
			printf("first_command: %s\n", info.commands[0]);
			printf("first_command: %s\n", info.commands[1]);
			free(info.commands);
		} */
		if (ft_strlen(info.readline) != 0)
		{
			add_history(info.readline);
			free(info.readline);
		}
	}
	return (0);
}
