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

	char	**split_qoutes;
	char	**commands;
	int		s_qoutes;
	int		d_qoutes;
	int		exit_status;
}	t_info;

int		parsing(t_info *info);
char 	**bananasplit(t_info *info);
int 	which_quote(const char *s1, int index);
int 	if_quotes_closed(t_info *info, char quote);

	/*----utils.c------------------------*/
void	count_qoutes(t_info *info);
int 	set_error_str(t_info *info, char *message, int error);

		/*----initialize.c-------------------*/
		void initialize_info(t_info *info);

#endif