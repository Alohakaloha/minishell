/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:00:43 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/04 09:50:43 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*returns a pointer to the last occurence of character in string*/
char	*ft_strrchr(const char *s, int a)
{
	char	*ret;

	ret = 0;
	while (1)
	{
		if (*s == (unsigned char)a)
			ret = (char *)s;
		if (*s == 0)
			break ;
		s++;
	}
	return (ret);
}
