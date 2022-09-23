#include "../includes/minishell.h"

/*
returns position if successful otherwise 0 (start of string if failed)
*/
int quotes_in_pipe(t_info *info, char quote, int position)
{
	printf("quote we are looking for %c\n", quote);
	while (info->readline[position] != quote)
	{
		position++;
		if (info->readline[position] == '\0')
			return (0);
	}
	return (position);
}

/**
 * case 1: // | = syntax error
 * case 2: // | echo = syntax error
 * case 3: // "|" = handled as a normal char value
 * case 4: // '|' = handles as normal char value.
 * case 5: // echo | = syntax error
 */
int pipe_cases(t_info *info)
{
	int		i;
	int		pipe;

	i = 0;
	pipe = 0;
	while(info->readline[i] == ' ')
		i++;
	if (info->readline[i] == '|')
		return (1);
	while (info->readline[i])
	{
		if (info->readline[i] == '"' || info->readline[i] == 39)
		{

			if (quotes_in_pipe(info, info->readline[i], i + 1) == 0)
				return (1);
			else
				i = quotes_in_pipe(info, info->readline[i], i + 1);
		}
		if (info->readline[i] == '|' && info->readline[i + 1] == '|')
			return (1);
		if (info->readline[i] == '|')
		{
			printf("pipe engaged\n");
			pipe = 1;
		}
		if ((info->readline[i] != ' ' && info->readline[i] != '|') && pipe  == 1)
			pipe = 0;
		i++;
	}
	printf("pipe: %d\n", pipe);
	if (pipe == 1)
		return (1);
	return (0);
}

int	check_pipes(t_info *info)
{
	int	i;

	i = 0;
	while(info->readline[i])
	{
		if (info->readline[i] == '|')
			return (0);
		i++;
	}
		return (1);
}