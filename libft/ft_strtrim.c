/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:12:26 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/04 02:06:47 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.*/
#include "libft.h"

static int	ft_is_set(char const *set, char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;
	size_t	len;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && ft_is_set(set, *start))
		start++;
	while (start < end && ft_is_set(set, *(end - 1)))
		end--;
	len = end - start + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, start, len);
	return (ret);
}
