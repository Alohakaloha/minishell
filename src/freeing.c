/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:59:23 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/08 15:50:39 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/minishell.h"

void	freeing_split_text(t_info *info)
{
	int z;

	z = 0;
	while (z <= info->word_count)
	{
		printf("invalid: %s\n", info->split_text[z]);
		printf("i: %d cleared out suscesfully!\n", z);
		free(info->split_text[z]);
		z++;
	}
	free(info->split_text);
	info->split_text = NULL;
}

void	freeing_tokens(t_info *info, t_token *token)
{
	t_token *free_token;
	printf("info->word_count: %d\n", info->word_count);

	free_token = token;
	while (token != NULL)
	{
		free_token = token;
		token = token->next;
	//	free(free_token->token);
		free(free_token);
		printf("token freed succesfully!\n");
	}
}