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
 * FUCNTION: (pipe_cases) checks for the specific error cases on the pipes.
 * 				There are specific five cases that we are checking for:
 * case 1: // | = syntax error
 * case 2: // | echo = syntax error
 * case 3: // "|" = handled as a normal char value
 * case 4: // '|' = handles as normal char value.
 * case 5: // echo | = syntax error
 * 
 * RETURN VALUE---------
 *	0	-In case the pipes that are currently in the input does not
 *			match these specific error cases.
 *	1	-In case in the given input the current pipe match any requirements
 *			function fails.
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
			pipe = 1;
		if ((info->readline[i] != ' ' && info->readline[i] != '|') && pipe  == 1)
			pipe = 0;
		i++;
	}
	if (pipe == 1)
		return (1);
	return (0);
}

/**
 * FUNCTION: (check_pipes) checks if there are
 * 				any pipes in the input.
 * RETURN VALUE------
 * 	0 -if it has succesfully found a pipe no matter if it is
 * 		sintaxicly possible or not.
 *	1 -if there are no pipes in a given input.
 */
int	check_pipes(t_info *info)
{
	int	i;

	i = 0;
	while(info->readline[i])
	{
		if (info->readline[i] == '|')
			info->pipes++;
		i++;
	}
	if (info->pipes != 0)
		return (0);
	return (1);
}