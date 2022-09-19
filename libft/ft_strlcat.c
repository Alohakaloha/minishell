/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:35:57 by dnguyen           #+#    #+#             */
/*   Updated: 2021/10/26 09:58:30 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returns lenght of combined strings*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst && i < dstsize)
	{
		i++;
		dst++;
	}
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < dstsize)
		*dst = 0;
	while (*src++)
		i++;
	return (i);
}

/*int    main()
{
    char first[] = "Twenty";
    char last [] = "More than 5";
    int characters;
    int size = 5;
    char buffer[size];
    strcpy(buffer,first);
    characters = ft_strlcat(buffer,last,size);
    puts(buffer);

    printf("String first = %s \n", first);
    printf("String last = %s \n", last);
    printf("String size = %d \n", characters);
    return(0);
}
*/