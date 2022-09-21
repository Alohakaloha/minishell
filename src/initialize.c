/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:44:03 by lkavalia          #+#    #+#             */
/*   Updated: 2022/09/21 11:46:54 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	initialize_info(t_info *info)
{
	info->exit_status = 0;
	info->s_qoutes = 0;
	info->d_qoutes = 0;
}