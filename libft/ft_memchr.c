/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:24:34 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/04 08:35:02 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int value, size_t n)
{
	const char	*ptr;
	size_t		i;

	ptr = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == value)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
int main() {

   const char str[] = "The string ends with u";
   const char ch = 'u';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
*/