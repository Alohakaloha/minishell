/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:56:50 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/04 00:32:11 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copies n bytes from src to dst handles overlapping regions
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
