/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:46:55 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/03 21:43:50 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copies n characters from memory area src to dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	size;
	char	*p;
	char	*s;

	p = (char *)dest;
	s = (char *)src;
	size = 0;
	if (!dest && !src)
		return (NULL);
	while (size < n)
	{
		*p++ = *s++;
		size++;
	}
	return (dest);
}
