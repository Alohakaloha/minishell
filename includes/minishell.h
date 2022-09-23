#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"


typedef struct s_token
{
	char	*token;
	int		pipe;
	int		single_quotes;
	int		double_quotes;
	struct 	s_token *next;
}	t_token;

typedef struct s_info
{
	char	*readline;

	char		**split_qoutes;
	char		**commands;
	int 		s_qoutes;
	int			d_qoutes;
	int			exit_status;
	t_token 	*token;
}	t_info;

int		parsing(t_info *info);
int		check_pipes(t_info *info);
int 	pipe_cases(t_info *info);
int 	quotes_in_pipe(t_info *info, char quote, int position); 
char **bananasplit(t_info *info);
int 	which_quote(const char *s1, int index);
int 	if_quotes_closed(t_info *info, char quote);

	/*----utils.c------------------------*/
void	count_qoutes(t_info *info);
int 	set_error_str(t_info *info, char *message, int error);

		/*----initialize.c-------------------*/
		void initialize_info(t_info *info);

#endif