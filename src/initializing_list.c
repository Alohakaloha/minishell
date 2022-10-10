/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:08:13 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/10 16:24:49 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_items(char **splitted_text)
{
	int	total;

	total = 0;
	while (splitted_text[total] != NULL)
		total++;
	return (total);
}

static	t_token *attach_the_last(char *token)
{
	t_token	*temp;

	temp = malloc(sizeof(t_token));
	if (!temp)
	{
		printf("allocation failed!\n");
		exit(1);
	}
	temp->token = token;
	temp->next = NULL;
	return (temp);
}

static t_token  *attach_the_rest(t_token *token, char **text,int items)
{
	t_token *temp;
	int		i;

	temp = token; 
	i = 1;

	while (i != items)
	{
		temp->next = attach_the_last(text[i]);
		temp = temp->next;
		i++;
	}
	return (token);
}

void print_stack_a(t_token *head)
{
	t_token *temp;

	temp = head;
	printf("----startof tokens----\n");
	if (!head)
		printf("        Empty        \n");
	while (temp != NULL)
	{
		printf("element: %s\n", temp->token);
		temp = temp->next;
	}
	printf("end of tokens\n\n");
}

t_token	 *create_linked_list(t_info *info, t_token *token)
{
//	int	i;
	int	items;

//	i = 0;
	items = 0;
	if (info->split_text == NULL)
		return (NULL);
	items = count_items(info->split_text);
	token->token = info->split_text[0];
	token->next = NULL;
	token = attach_the_rest(token, info->split_text, items);
	printf("total: %d\n", items);
	print_stack_a(token);
	return (token);
}