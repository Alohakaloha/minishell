/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_the_information.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:04:35 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/08 19:09:41 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*save_inside_quotes(char *readline, char quote, int next_index)
{
	int i;
	int start_position;
	int	lenght;
	char *inside_quotes;

	i = next_index;
	while (readline[i] != quote)
		i++;
	i++;
	printf("readline: %c\n", readline[i]);
	start_position = i;
	lenght = 0;
	while (readline[i] != quote)
	{
		lenght++;
		i++;
	}
	printf("lenght: %d ending char: %c\n", lenght, readline[i]);
	inside_quotes = malloc(sizeof(char) * (lenght + 1));
	
	i = 0;
	while (readline[start_position] != quote)
	{
		inside_quotes[i] = readline[start_position];
		printf("inside_quotes[%d] %c\n", i, inside_quotes[i]);
		start_position++;
		i++;
	}
	inside_quotes[i] = '\0';
	printf("inside_quotes: %s\n", inside_quotes);
	return (inside_quotes);
}

static void set_quotes(char *inside_quotes, t_token *token, char quote)
{
	t_token *temp;
	
	temp = token;
	while (ft_strcmp(token->token, inside_quotes) != 0)
		token = token->next;
	printf("token->token: %s\n", token->token);
	if (quote == 34)
	{
		token->single_quotes = false;
		token->double_quotes = true;
	}
	else
	{
		token->double_quotes = false;
		token->single_quotes = true;
	}
	printf("quote: %c\n", quote);
	printf("double_quotes: %d single_quotes: %d\n", token->double_quotes, token->single_quotes);
	token = temp;
}

int	next_index_finder(char *str, int next_index, char quote)
{
	//Going till the quote
	while (str[next_index] != quote)
		next_index++;
	printf("next_index: %d %c\n", next_index, str[next_index]);
	next_index++;
	while(str[next_index] != '\0')
	{
		if (str[next_index] == quote)
		{
			next_index++;
			break ;
		}
		next_index++;
	}
	printf("next_index_before: %d %c\n", next_index - 1, str[next_index - 1]);
	printf("next_index_last: %d %c\n", next_index, str[next_index]);
	return (next_index);
}

void register_the_information(t_token *token, t_info *info)
{
	char	quote;
	char 	*inside_quotes;
	int		next_index;
	int		i;
	
	quote = '0';
	inside_quotes = NULL;
	next_index = 0;
	i = 0;
	for (int i = 0; info->splitting_positions[i] != -1; i++)
		printf("split_positions: %d\n", info->splitting_positions[i]);
	if (info->s_quotes != 0 || info->d_quotes !=  0)
	{
		while (info->splitting_positions[i] != -1)
		{
			if (info->readline[next_index] == '\0')
			{
				printf("WTF\n");
				break ;
			}
			quote = which_quote(info->readline, next_index);
			inside_quotes = save_inside_quotes(info->readline, quote, next_index);
			printf("inside_quotes: %s\n", inside_quotes);
			//setting where the quotes are
			set_quotes(inside_quotes, token, quote);
			next_index = next_index_finder(info->readline, next_index, quote);
			printf("quote: %c\n", quote);
			free(inside_quotes);
			i += 2;
			printf("info->splitting_positions[%d] %d next_index %d\n", i, info->splitting_positions[i], next_index);
		}
	}
	else 
	{
		printf("hey hey! %s\n", token->token);
	}
	printf("outside\n");
}