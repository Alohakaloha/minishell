#include "../includes/minishell.h"

/*
Whitespace is being skipped in bash and not added to the history,
even tho there is a working command working after it.
That is being noted but we decided not to implement because of
undefined behaviour.
*/

/* int	main(int argc, char **argv)
{
	t_info	info;
//	int i;

	if (argc != 1)
	{
		printf("%s doesn't need more arguments.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	initialize_info(&info);
	while(1)
	{
		info.readline = readline("Mini_hell\U0001F34C\U0001F412 ");
		parsing(&info);
		if (ft_strlen(info.readline) != 0)
		{
			add_history(info.readline);
			free(info.readline);
		}
	}
	return (0);
}
 */

int main(int argc, char **argv)
{
	t_info	info;
	t_token	*token;
//	t_token	*free_token;

	token = NULL;
	if (argc != 1)
	{
		printf("%s doesn't need more arguments.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	initialize_info(&info);
	while (1)
	{
		token = malloc(sizeof(t_token));
		info.readline = readline("Mini_hell\U0001F34C\U0001F412 ");
		if (check_pipes(&info) == 0) // Checks if there are pipes and there are no problems with them.
		{
			if (pipe_cases(&info) == 1)
				printf("Syntax error | ");
		}
		count_quotes(&info); // COUNTS THE QUOTES
		printf("double_quotes: %d single qoutes: %d\n", info.d_quotes, info.s_quotes);
		if (info.d_quotes != 0 || info.s_quotes != 0)
		{
			info.split_text = bananasplit(&info);
			if (info.split_text == NULL)
				printf("Banana split has failed!\n");
			for(int i = 0; info.split_text[i]; i++ )
				printf("split_quotes: %s\n", info.split_text[i]);
		}
		else
			info.split_text = ft_edited_split(info.readline, ' ', &info);
		token = create_linked_list(&info, token);
		register_the_information(token, &info);
		printf("after the !register_the_information!\n");
		freeing_split_text(&info);
		freeing_tokens(&info, token);
		if (ft_strlen(info.readline) != 0)
		{
			add_history(info.readline);
			free(info.readline);
		}
	}
	return (0);
}