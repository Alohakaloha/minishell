/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:10:21 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/20 20:12:44 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//	pipe = 1
//	input file_name = 2
//	command = 3
//	redirection_input = 4
//	redirection_output = 5
//	redirect_append_input = 6
//	redirect_append_output = 7
//	text = 8
//	flags = 9
//	arguments = 10
//	built-in = 11
//	space = 0
static void	check_specials(t_token	**token)
{
	if ((*token)->token[0] == '|')
		(*token)->indentifier = 1;
	else if ((*token)->token[0] == '<' && (*token)->token[1] != '<')
		(*token)->indentifier = 4;
	else if ((*token)->token[0] == '<' && (*token)->token[1] == '<')
		(*token)->indentifier = 6;
	else if ((*token)->token[0] == '>' && (*token)->token[1] != '>')
		(*token)->indentifier = 5;
	else if ((*token)->token[0] == '>' && (*token)->token[1] == '>')
		(*token)->indentifier = 7;
	else if ((*token)->token[0] == '-' && ft_isalpha((*token)->token[1]) == 1)
		(*token)->indentifier = 9;
	else
		(*token)->indentifier = -1;
}

//Possible built_ins:
//	--echo
//	--cd
//	--pwd
//	--export
//	--unset
//	--env
//	--exit
static	void recognise_builtins(t_token **token)
{
	int	check;

	check = 0;
	if (ft_strcmp((*token)->token, "echo") == 0)
		check = 11;
	else if (ft_strcmp((*token)->token, "cd") == 0)
		check = 11;
	else if (ft_strcmp((*token)->token, "pwd") == 0)
		check = 11;
	else if (ft_strcmp((*token)->token, "export") == 0)
		check = 11;
	else if (ft_strcmp((*token)->token, "unset") == 0)
		check = 11;
	else if (ft_strcmp((*token)->token, "env") == 0)
		check = 11;
	else if (ft_strcmp((*token)->token, "exit") == 0)
		check = 11;
	if (check == 11)
		(*token)->indentifier = 11;
}

static void	assign_indexes(t_token **token)
{
	t_token	*temp;
	int		i;

	temp = (*token);
	i = 0;
	while ((*token) != NULL && (*token)->next != NULL)
	{
		check_specials(token);
		recognise_builtins(token);
		(*token)->index = i;
		(*token) = (*token)->next;
		i++;
	}
	(*token)->index = i;
	check_specials(token);
	recognise_builtins(token);
	(*token) = temp;
}


static	void assign_the_rest(t_info *info, t_token **token)
{
	t_token	*temp;

	temp = (*token);
	while ((*token) != NULL)
	{
		
		if ((*token)->indentifier == -1 && (*token)->indentifier != 1)
		{
			if (ft_isalpha((*token)->token[0]) == 1)
				(*token)->indentifier = 3;
		}
		else if ((*token)->indentifier == 4)
		{
			if ((*token)->next != NULL)
			{
				(*token) = (*token)->next;
				if (ft_isalpha((*token)->token[0]) == 1)
					(*token)->indentifier = 2;
			}
		}
		(*token) = (*token)->next;
	}
	printf("info->hey: %d\n", info->d_quotes);
	(*token) = temp;
}

void	register_tokens(t_info *info, t_token **token)
{
	t_token	*temp_token;

	printf("info-> %d\n", info->dollar_sign);
	temp_token = (*token);
	printf("IN\n");
	assign_indexes(token);
	assign_the_rest(info, token);
	printf("failed!\n");
	(*token) = temp_token;
}