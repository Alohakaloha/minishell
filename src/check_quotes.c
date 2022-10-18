/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:05:11 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/14 19:28:21 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_quotes(t_info *info)
{
	size_t i;
	char	quote;
	
	i = 0;
	quote = '1';
	while (info->readline[i] != '\0')
	{
		if (info->readline[i] == '"')
		{
			quote = '"';
			i++;
			while (info->readline[i] != quote && info->readline[i] != '\0')
				i++;
			if (info->readline[i] != quote)
				return (1);
		}
		else if (info->readline[i] == 39)
		{
			quote = 39;
			i++;
			while (info->readline[i] != quote && info->readline[i] != '\0')
				i++;
			if (info->readline[i] != quote)
				return (1);
		}
		i++;
	}
	return (0);
}