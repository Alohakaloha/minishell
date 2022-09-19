/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:44:09 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/01 09:22:40 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *st1, const char *st2, size_t num)
{
	size_t	i;

	i = 0;
	if (!num)
		return (0);
	while (i < num - 1 && st1[i] == st2[i] && st1[i] != '\0' && st2[i] != '\0')
		i++;
	return ((unsigned char)st1[i] - (unsigned char)st2[i]);
}

/* return value 
<0 = first character that does not match has a lower value str1 than in str2
0 content for both strings are equal
>0 first character that does not match has a greater value in str1 than in str2
*/