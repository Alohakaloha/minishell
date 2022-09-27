/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:56:04 by lkavalia          #+#    #+#             */
/*   Updated: 2022/09/24 14:06:43 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


/**
 * FUNCTION (count_quotes) counts the quotes that are in the
 * 				input.
 */
void	count_quotes(t_info *info)
{
	int i;
	int	double_quotes;
	int single_quotes;
	
	i = 0;
	double_quotes = 0;
	single_quotes = 0;
	while (info->readline[i] != '\0')
	{
		if (info->readline[i] == 34)
			double_quotes++;
		else if (info->readline[i] == 39)
			single_quotes++;
		i++;
	}
	info->d_quotes = double_quotes;
	info->s_quotes = single_quotes;
}
