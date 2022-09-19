/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:47:11 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/04 09:15:48 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*strlcpy used to copy contents of one string into another*/
size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	if (length < size)
	{
		while (src[length] && length < (size - 1))
		{
			dst[length] = src[length];
			length++;
		}
	}
	if (size != '\0')
		dst[length] = '\0';
	while (src[length])
		length++;
	return (length);
}

/*int	main()
{
	const char src[30] = "This string won't change";
	char dest [30];
	ft_strlcpy(dest,src,5);
}
*/