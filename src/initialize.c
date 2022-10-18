/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:44:03 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/17 16:52:33 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	initialize_info(t_info *info)
{
	info->exit_status = 0;
	info->s_quotes = 0;
	info->d_quotes = 0;
	info->pipes = 0;
	info->word_count = 0;
	info->important_quotes = 0;
	info->redirect_input = 0;
	info->redirect_output = 0;
	info->redirect_input_append = 0;
	info->redirect_output_append = 0;
	info->dollar_question_sign = 0;
	info->dollar_sign = 0;
	info->start = 0;
	info->trigger = 0;
}