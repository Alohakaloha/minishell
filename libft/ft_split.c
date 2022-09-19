/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:48:17 by dnguyen           #+#    #+#             */
/*   Updated: 2021/11/05 19:26:27 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter.  The array must be
ended by a NULL pointer.*/
static char	**to_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static int	ft_countword(char const *str, char c)
{
	int	i;
	int	nbr_words;

	i = 0;
	nbr_words = 1;
	while (str[i] != '\0')
	{
		if ((str[i] == c && str[i + 1] != c))
			nbr_words++;
		i++;
	}
	if (str[ft_strlen(str) - 1] == c)
		nbr_words--;
	if (str[0] == c)
		nbr_words--;
	return (nbr_words);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	ptr = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			ptr[j] = ft_substr(s, i, ft_wordlen(&s[i], c));
			if (!ptr[j])
				return (to_free(ptr));
			i = i + ft_strlen(ptr[j]) - 1;
			j++;
		}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}
