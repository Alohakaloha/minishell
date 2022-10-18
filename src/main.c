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
	t_token	*free_token;

	token = NULL;
	if (argc != 1)
	{
		printf("%s doesn't need more arguments.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		initialize_info(&info);
		token = malloc(sizeof(t_token));
		free_token = token;
		info.readline = readline("Mini_hell\U0001F34C\U0001F412 ");
		if (check_pipes(&info) == 0) // Checks if there are pipes and there are no problems with them.
		{
			if (pipe_cases(&info) == 1)
			{
				info.error = true;
				printf("Syntax error | \n");
			}
		}
		count_redirections(&info);
		count_dollar_signs(&info);
		count_quotes(&info); // COUNTS THE QUOTES
		if (info.d_quotes != 0 || info.s_quotes != 0)
		{
			if (check_quotes(&info) == 1)
			{
				info.error = true;
				printf("Quotes are not closed!\n");
			}
		}
		printf("double_quotes: %d single qoutes: %d\n", info.d_quotes, info.s_quotes);
		if (info.error == false)
		{
			lexer(&info, &token);
			while (token != NULL)
			{
				printf("full list: %s ", token->token);
				if (token->double_quotes == true)
					printf("%d\n", token->double_quotes);
				else if (token->single_quotes == true)
					printf("%d\n", token->single_quotes);
				else
					printf("\n");
				token = token->next;
			}
			token = free_token;
			freeing_tokens(&info, token);
		}
		printf("after the !register_the_information!\n");
//		freeing_split_text(&info);
		if (ft_strlen(info.readline) != 0)
		{
			add_history(info.readline);
			free(info.readline);
		}
	}
	return (0);
}