/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:38:53 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/20 19:31:48 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token *attach_token_end(t_token *token)
{
	t_token *temp;

	temp = malloc(sizeof(t_token));
	if (!temp)
	{
		printf("allocation failed!\n");
		exit(1);
	}
	temp->double_quotes = false;
	temp->single_quotes = false;
	temp->index = 0;
	temp->next = NULL;
	token->next = temp;
	return (token);
}

static int	space(t_info *info, int i, t_token **token)
{
	printf("case 1\n");
	(*token)->token = ft_substr(info->readline, info->start, i - info->start);
	while (info->readline[i] == ' ')
		i++;
	i--;
	//printf("token->token: %s\n", (*token)->token);
	(*token)->next = NULL;
	info->start = i + 1;
	//		printf("temp: %s\n", temp);
	info->trigger = 1;
	return (i);
}

static int quotes(t_info *info, int i, t_token **token)
{
	if (info->readline[i] == 34)
	{
		printf("case: 0\n");
		if (info->readline[i - 1] == ' ')
			info->start++;
		else	// before the quote
		{
			if (i != 0)
			{
				(*token)->token = ft_substr(info->readline, info->start, i - info->start);
				(*token) = attach_token_end(*token);
				(*token) = (*token)->next;
			}
			info->start = i + 1;
			if (info->readline[info->start] == ' ')
			{
				printf("in\n");
				while (info->readline[info->start] == ' ' && info->readline[info->start] == '\0')
					info->start++;
				info->start++;
				printf("check: %c\n", info->readline[info->start]);
			}
		}
		i++;
		while (info->readline[i] != 34)
			i++;
		(*token)->double_quotes = true;
		(*token)->token = ft_substr(info->readline, info->start, i - info->start);
		printf("token->token: %s\n", (*token)->token);
		(*token)->next = NULL;
		info->start = i + 1;
		printf("info->start_34: %c\n", info->readline[info->start]);
		//		printf("temp: %s\n", temp);
		info->trigger = 1;
	}
	else if (info->readline[i] == 39)
	{
		printf("case: 0_1\n");
		if (info->readline[i - 1] == ' ')
			info->start++;
		else // before the quote
		{
			if (i != 0)
			{
				(*token)->token = ft_substr(info->readline, info->start, i - info->start);
				(*token) = attach_token_end(*token);
				(*token) = (*token)->next;
			}
			info->start = i + 1;
			if (info->readline[info->start] == ' ')
			{
				printf("in\n"); //check changed the line underneath from == '\0' to != '\0'
				while (info->readline[info->start] == ' ' && info->readline[info->start] != '\0')
					info->start++;
				info->start++;
				printf("check: %c\n", info->readline[info->start]);
			}
		}
		i++;
		while (info->readline[i] != 39)
			i++;
		(*token)->single_quotes = true;
		(*token)->token = ft_substr(info->readline, info->start, i - info->start);
		printf("token->token: %s\n", (*token)->token);
		(*token)->next = NULL;
		info->start = i + 1;
		printf("info->start_39: %c\n", info->readline[info->start]);
		//		printf("temp: %s\n", temp);
		info->trigger = 1;
	}
	return (i);
}

static int	redirect_append(t_info *info, int i, t_token **token)
{
	printf("case: redirect_append\n");
	char	sign;
	
	sign = info->readline[i];
	if (i != 0)
	{
		(*token)->token = ft_substr(info->readline, info->start, i - info->start);
		(*token) = attach_token_end(*token);
		(*token) = (*token)->next;
	}
	(*token)->token = malloc(sizeof(char) * 3);
	(*token)->token[0] = sign;
	(*token)->token[1] = sign;
	(*token)->token[2] = '\0';
	i++;
	info->start = i + 1;
	info->trigger = 1;

	return (i);
}

static	int rest_of_the_cases(t_info *info, int i, t_token **token)
{
	char	sign;

	sign = info->readline[i];
	printf("i: %d\n", i);
	if (info->readline[i - 1] != ' ' && i != 0)
	{
		(*token)->token = ft_substr(info->readline, info->start, i - info->start);
		(*token) = attach_token_end(*token);
		(*token) = (*token)->next;
	}
	(*token)->token = malloc(sizeof(char) * 2);
	(*token)->token[0] = sign;
	(*token)->token[1] = '\0';
	if (info->readline[i + 1] == ' ')
	{
		i++;
		while (info->readline[i] == ' ' && info->readline[i] != '\0')
			i++;
		i--;
	}
	info->start = i + 1;
	info->trigger = 1;

	return (i);
}

static	t_token *triggered(t_info *info, t_token *token)
{
	token = attach_token_end(token);
	token = token->next;
	info->trigger = 0;
	return (token);
}

t_token	 *lexer(t_info *info, t_token *token)
{
	int i;
	t_token *temp_token;

	i = 0;
	token = malloc(sizeof(t_token));
	token->next = NULL;
	token->single_quotes = false;
	token->double_quotes = false;
	temp_token = token;
	info->trigger = 0;
	while (info->readline[i] != '\0')
	{
		if (info->readline[i] == 34 || info->readline[i] == 39)
			i = quotes(info, i, &token);
		else if (info->readline[i] == ' ')
			i = space(info, i, &token);
		else if ((info->readline[i] == '<' && info->readline[i + 1] == '<') || (info->readline[i] == '>' && info->readline[i + 1] == '>'))
			i = redirect_append(info, i, &token);
		else if (info->readline[i] == '<' || info->readline[i] == '>' || info->readline[i] == '|')
			i = rest_of_the_cases(info, i, &token);
		if (info->trigger == 1)
			token = triggered(info, token);
		i++;
	}
	token->token = ft_substr(info->readline, info->start, i - info->start);
	printf("goes through\n");
	token = temp_token;
	return (token);
}
