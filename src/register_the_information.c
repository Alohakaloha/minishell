/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_the_information.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:04:35 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/10 21:40:28 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	initialize_bool(t_token *token)
{
	token->single_quotes = false;
	token->double_quotes = false;
	token->redirect_input = false;
	token->redirect_input_append = false;
	token->redirect_output = false;
	token->redirect_output_append = false;
	token->dollar_sign = false;
	token->dollar_question_sign = false;
	token->pipe = false;
}

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
	t_token *temp;
	
	quote = '0';
	inside_quotes = NULL;
	next_index = 0;
	i = 0;
	temp = token;
	while (token != NULL)
	{
		initialize_bool(token);
		token = token->next;
	}
	token = temp;
	if (info->s_quotes != 0 || info->d_quotes !=  0)
	{
		for (int i = 0; info->splitting_positions[i] != -1; i++)
			printf("split_positions: %d\n", info->splitting_positions[i]);
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
	//		printf("quote: %c\n", quote);
			free(inside_quotes);
			i += 2;
	//		printf("info->splitting_positions[%d] %d next_index %d\n", i, info->splitting_positions[i], next_index);
		}
	}
	if (info->pipes != 0)
	{
		while (token != NULL)
		{
			if (ft_strchr(token->token, '|'))
			{
				printf("token has a pipe %s\n", token->token);
				token->pipe = true;
				printf("%d\n", token->pipe);
			}
			else
			{
				printf("no pipe! %s\n", token->token);
				token->pipe = false;
			}
			token = token->next;
		}
		token = temp;
	}
/* 	printf("redirections_input %d\n redirections_ouput: %d\n", info->redirect_input, info->redirect_output);
	printf("redirections_i_append %d\n redirections_o_append: %d\n", info->redirect_input_append, info->redirect_output_append);
	while (token != NULL)
	{
		printf("------before_token->token! %s\n", token->token);
		printf("before_redirecting_input %d\nbefore_redirecting_output %d\n", token->redirect_input, token->redirect_input);
		printf("before_redirecting_input_append %d\nbefore_redirecting_output_append %d\n", token->redirect_input_append, token->redirect_input_append);
		token = token->next;
	}
	token = temp; */
//	printf("check the amount of redirections: %d\n %d\n %d\n %d\n", info->redirect_input, info->redirect_output, info->redirect_input_append, info->redirect_output);
	if (info->redirect_input != 0 || info->redirect_output != 0)
	{
		while (token != NULL)
		{
			i = 0;
			printf("------token->token! %s\n", token->token);
			if (ft_strlen(token->token) < 3)
			{
				printf("its less than 3!\n");
				if (ft_strcmp(token->token, "<<") == 0)
					token->redirect_input_append = true;
				if	(ft_strcmp(token->token, "<") == 0)
					token->redirect_input = true;
				if (ft_strcmp(token->token, ">>") == 0)
					token->redirect_output_append = true;
				if (ft_strcmp(token->token, ">") == 0)
					token->redirect_output = true;
			}
			else
			{
				while (token->token[i] != '\0')
				{
					if (token->token[i] == '>' && token->token[i + 1] != '>' && token->token[i - 1] != '>')
						token->redirect_output = true;
					else if (token->token[i] == '>' && token->token[i + 1] == '>')
						token->redirect_output_append = true;
					if (token->token[i] == '<' && token->token[i + 1] != '<' && token->token[i - 1] != '<')
						token->redirect_input = true;
					else if (token->token[i] == '<' && token->token[i + 1] == '<')
						token->redirect_input_append = true;
					i++;
				}
			}
			printf("check_redirecting_input %d\ncheck_redirecting_output %d\n", token->redirect_input, token->redirect_output);
			printf("check_redirecting_input_append %d\ncheck_redirecting_output_append %d\n", token->redirect_input_append, token->redirect_output_append);
			token = token->next;
		}
		token = temp;
	}
	if (info->dollar_question_sign != 0 || info->dollar_sign != 0)
	{
		while (token != NULL)
		{
			i = 0;
			while (token->token[i] != '\0')
			{
				if (token->token[i] == '$' && token->token[i + 1] == '?')
				i++;
			}
			token = token->next;
		}
		token = temp;
	}
	printf("$: %d $? %d\n", info->dollar_sign, info->dollar_question_sign);
	printf("outside\n");
}