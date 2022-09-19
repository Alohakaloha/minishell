/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:05:15 by dnguyen           #+#    #+#             */
/*   Updated: 2022/03/20 17:30:45 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* converts string str into an integer if not valid returns zero */
/* skipping white space */
/* to add a new value to the digit we multiply the value by 10 */
int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	if (!str)
		return (0);
	i = 0;
	neg = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	if (neg == 1)
		return (-res);
	return (res);
}
