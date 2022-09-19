/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:04:30 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/04 09:47:45 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr, const void *ptr2, size_t num)
{
	while (num--)
	{
		if (*(char *)ptr != *(char *)ptr2)
			return ((unsigned char)*(char *)ptr - (unsigned char)*(char *)ptr2);
		ptr++;
		ptr2++;
	}
	return (0);
}
