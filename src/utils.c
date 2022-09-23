/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:56:04 by lkavalia          #+#    #+#             */
/*   Updated: 2022/09/23 15:50:04 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// -1 for success
// -2 for not success
void	count_qoutes(t_info *info)
{
	int i;
	int	double_qoutes;
	int single_qoutes;
	
	i = 0;
	double_qoutes = 0;
	single_qoutes = 0;
	while (info->readline[i] != '\0')
	{
		if (info->readline[i] == 34)
			double_qoutes++;
		else if (info->readline[i] == 39)
			single_qoutes++;
		i++;
	}
	info->d_qoutes = double_qoutes;
	info->s_qoutes = single_qoutes;
//	if (info->d_qoutes % 2 == 0 || info->s_qoutes % 2 == 0)
//		return (-1);
//	return (-2);
}
