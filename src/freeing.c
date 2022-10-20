/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:59:23 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/20 17:19:19 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/minishell.h"


void	freeing_tokens(t_token *token)
{
	t_token *free_token;

	free_token = token;
	while (token != NULL)
	{
		free_token = token;
		printf("[%s] ---> ", free_token->token);
		token = token->next;
	//	free(free_token->token);
		free(free_token);
		printf("token freed succesfully!\n");
	}
}