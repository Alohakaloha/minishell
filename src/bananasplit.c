#include "../includes/minishell.h"

static int ft_word_count(const char *s1, char c)
{
	int w_count;
	int i;

	i = 0;
	w_count = 0;
	while (s1[i] != '\0')
	{
		if (c == s1[i])
			i++;
		else
		{
			w_count++;
			while (s1[i] && s1[i] != c)
				i++;
		}
	}
	return (w_count);
}

static char *ft_insert(char *word, char const *s1, size_t i, size_t w_len)
{
	int x;

	x = 0;
	while (w_len > 0)
	{
		word[x] = s1[i - w_len];
		w_len--;
		x++;
	}
	word[x] = '\0';
	return (word);
}

static char **s_words(size_t w_count, char const *s1, char c, char **splitted)
{
	size_t x;
	size_t i;
	size_t w_len;

	x = 0;
	i = 0;
	w_len = 0;
	while (x < w_count)
	{
		while (s1[i] == c && s1[i] != '\0')
			i++;
		while (s1[i] != c && s1[i] != '\0')
		{
			i++;
			w_len++;
		}
		splitted[x] = malloc(sizeof(char) * (w_len + 1));
		if (!splitted)
			return (NULL);
		ft_insert(splitted[x], s1, i, w_len);
		w_len = 0;
		x++;
	}
	splitted[x] = 0;
	return (splitted);
}

char	which_quote(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == 39 || s1[i] == 34)
			return (s1[i]);
		i++;
	}
	return (1);

}

char **bananasplit(t_info *info)
{
	size_t 	w_count;
	char 	**splitted;
	char	quote;

	if (!info->readline)
		return (NULL);
	quote = which_quote(info->readline);
	if (quote == 34)
	{
		if (info->d_qoutes % 2 != 0)	//Undefined behaviour
			return (NULL);
	}
	else
	{
		if (info->s_qoutes % 2 != 0) //Undefined behaviour
			return (NULL);
	}

	w_count = ft_word_count(info->readline, quote);
	splitted = malloc(sizeof(char *) * (w_count + 1));
	if (!splitted)
		return (NULL);
	s_words(w_count, info->readline, quote, splitted);
	return (splitted);
}
