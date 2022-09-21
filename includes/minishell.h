#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_info
{
	char	*readline;
	char	**commands;
	int		s_qoutes;
	int		d_qoutes;
	int		exit_status;
}	t_info;

int		parsing(t_info *info);

/*----utils.c------------------------*/
int		count_qoutes(t_info *info);

/*----initialize.c-------------------*/
void	initialize_info(t_info *info);

#endif