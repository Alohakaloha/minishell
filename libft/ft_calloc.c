/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:23:13 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/05 19:19:49 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*malloc is used to dynamically allocate memory,
returns a pointer of type void which can be cast into any form*/
/* allocates memory for an array num objects and initializes all bytes
in the allocated storage to zero*/
void	*ft_calloc(size_t num, size_t size)
{
	void	*ret;

	ret = malloc(size * num);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * num);
	return (ret);
}
