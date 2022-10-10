/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bananasplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:38:49 by lkavalia          #+#    #+#             */
/*   Updated: 2022/10/08 18:18:40 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

/**
 * FUNCTION: (which_quote)  matches and returns the type of quote it finds
 * 				otherwise it returns (1).
 */
int	which_quote(const char *s1, int index)
{

	while (s1[index])
	{
		if (s1[index] == 39 || s1[index] == 34)
			return (s1[index]);
		index++;
	}
	return (1);
}

/**
 * FUNCTION: (if_quotes_closed) checks for unclosed quotes
 * 				in the line has read.
 */
int	if_quotes_closed(t_info *info, char quote)
{
	int	i;
	int status; // opened == 1 | closed == 0
	char q;

	i = 0;
	status = 0;
	q = quote;
	info->important_quotes = 0;
	printf("q %c\n", q);
	while (info->readline[i] != '\0')
	{
		if (info->readline[i] == q)
		{
			info->important_quotes++;
			status++;
			if (status == 2)
			{
				status = 0;
				q = which_quote(info->readline, i + 1);
			}
		}
		i++;
	}
	printf("status1 %d\n", status);
	if (status == 1)
	{
		info->exit_status = 2;
		return (1);
	}
	return (0);
}

/**
 * FUNCTION: (save_important_positions) fills up the int array splitting_positions
 * 				with the positions where the splitting should occur.
 */
int	 *save_important_positions(t_info *info)
{
	int	i;
	int	x;
	int	status;
	int *splitting_positions;
	char quote;

	i = 0;
	x = 0;
	status = 0; // opened == 1 | closed == 0
	quote = which_quote(info->readline, 0);
	splitting_positions = malloc(sizeof(int) * (info->important_quotes + 1));
	if (!splitting_positions)
	{
		printf("Error(save_important_positions): malloc has failed!\n");
		return (NULL);
	}
	splitting_positions[info->important_quotes] = -1;
	while (info->readline[i] != '\0')
	{
		if (info->readline[i] == quote)
		{
			splitting_positions[x] = i;
			x++;
			status++;
			if (status == 2)
			{
				status = 0;
				quote = which_quote(info->readline, i +1);
			}
		}
		i++;
	}
	//We can uses line 104-110 for debugging purposes.
/* 	x = 0;
	while (splitting_positions[x] != -1)
	{
		printf("spliting positions: %d\n", splitting_positions[x]);
		x++;
	} */
	return (splitting_positions);
}

/**
 * FUNCTION: (count_words) counts the amount of words it should be splitted to.
 * 				This function is useful for later on mallocing of the double
 * 				pointer.
 */
int	count_words(char *text, int *positions)
{
	int	i;
	int	x;
	int w_count;

	i = 0;
	x = 0;
	w_count = 0;
	while (text[x] != '\0')
	{
		if (positions[i] == -1 && text[x + 1] != '\0')
		{
			w_count++;
			break ;
		}
		while (x < positions[i])
			x++;
		w_count++;
		x++;
		i++;
	}
	return (w_count);
}

/**
 * FUNCTION: (word_lenght) is used to find the lenght of each individual block.
 * 				it is needed for the later on mallocing. First if is for the cases
 * 				when the line is continuing even after the double or single quotes.
 * 				ex: echo "hello" 'hey' today.
 */
static int	word_lenght(char *text, int *position, int word)
{
	int	i;
	int lenght;
	
	i = 0;
	lenght = 0;
	if (position[word] == -1)
	{
		while (text[i] == ' ' && text[i] != '\0')
			i++;
		while (text[i] != '\0')
		{
			i++;
			lenght++;
		}
	}
	else
	{
		while (lenght < position[word])
			lenght++;
	}
	if (word != 0)
		return ((lenght - position[word - 1]) - 1);
	return (lenght - 1);
}

char	**split_at_positions(int word_count, char *text, char **splitted, int *position)
{
	int		word;
	int		word_len;
	int		letter;
	int		x;

	word =  0;
	word_len = 0;
	letter = 0;
	x = 0;
	while (word < word_count)
	{
		word_len = word_lenght(text, position, word);
		splitted[word] = ft_calloc(sizeof(char), (word_len + 1));
		printf("word_len: %d\n", word_len);
		if (position[word] != -1 && text[x] == text[position[word]])
			x++;
		while (letter < word_len)
		{
			splitted[word][letter] = text[x];
			letter++;
			x++;
		}
		splitted[word][letter] = '\0';
		letter = 0;
		x++;
		word++;
	}
	splitted[word_count] = 0;

	return (splitted);
}

char **bananasplit(t_info *info)
{
	char	**splitted_at_positions;
	char	quote;
//	int 	*positions;

	quote = which_quote(info->readline , 0);
	if (quote == 1)
		return (NULL);
	if (if_quotes_closed(info, quote) == 1)
	{
		set_error_str(info, "Syntax Error\n", 2);
		return (NULL);	//errormessage and set last_exit status
	}
	printf("info->important_quotes: %d\n", info->important_quotes);
	info->splitting_positions = save_important_positions(info);
	if (info->d_quotes % 2 != 0) // Undefined behaviour
		return (NULL);
	else
	{
		if (info->s_quotes % 2 != 0) //Undefined behaviour
			return (NULL);
	}
	info->word_count = count_words(info->readline, info->splitting_positions);
	printf("word_count: %d\n", info->word_count);
	splitted_at_positions = ft_calloc((info->word_count + 1), sizeof(char *));
	splitted_at_positions = split_at_positions(info->word_count, info->readline, splitted_at_positions, info->splitting_positions);
	printf("first position: %s\n", splitted_at_positions[0]);
	printf("first position: %s\n", splitted_at_positions[1]);
	for (int g = 0; splitted_at_positions[g] != NULL; g++)
		printf("splitted_at_positions: %s\n", splitted_at_positions[g]);
//	free(positions);
	return (splitted_at_positions);
}
