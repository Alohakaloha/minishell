/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:15:35 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/05 19:20:09 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation of ’s1’ and ’s2’*/
char	*ft_strjoin(char const *s, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s || !s2)
		return (0);
	i = 0;
	str = malloc((ft_strlen(s) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (*s)
		str[i++] = *s++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
