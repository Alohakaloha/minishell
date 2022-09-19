/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:32:23 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/04 01:56:03 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*searches for a character in a string and returns the pointer*/
char	*ft_strchr(const char *string, int ch)
{
	while (*string != (unsigned char)ch)
	{
		if (*string == 0)
			return (0);
		string++;
	}
	return ((char *)string);
}
