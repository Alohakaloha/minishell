/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:44:03 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/20 17:38:41 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	initialize_info(t_info *info)
{
	info->exit_status = 0;
	info->s_quotes = 0;
	info->d_quotes = 0;
	info->pipes = 0;
	info->redirect_input = 0;
	info->redirect_output = 0;
	info->redirect_input_append = 0;
	info->redirect_output_append = 0;
	info->dollar_question_sign = 0;
	info->dollar_sign = 0;
	info->start = 0;
	info->trigger = 0;
	printf("info->triger: %d\n", info->trigger);
	info->error = false;
}