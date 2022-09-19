#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	char	*history;

	if (argc != 1)
	{
		printf("%s doesn't need more arguments.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		history = readline("\uE528 ");
		add_history(history);
		free(history);
	}
}