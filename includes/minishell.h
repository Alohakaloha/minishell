#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdbool.h>

//	pipe = 1
//	file_name = 2
//	command = 3
//	redirection_input = 4
//	redirection_output = 5
//	redirect_append_input = 6
//	redirect_append_output = 7
//	text = 8
//	space = 0
typedef struct s_token
{
	char		*token;
	
//	int			pipe;
//	int			single_quotes;
//	int			double_quotes;
	bool		single_quotes;
	bool		double_quotes;
	unsigned int 	indentifier;
	struct 		s_token *next;
}	t_token;

typedef struct s_info
{
	char	*readline;
	int		word_count;
	char	**banana_split;
	char	**split_text;
	int		*splitting_positions;
	char	**commands;
	int		s_quotes;
	int		d_quotes;
	int		important_quotes;
	int		redirect_input;
	int		redirect_output;
	int		redirect_input_append;
	int		redirect_output_append;
	int		dollar_sign;
	int		dollar_question_sign;
	int		pipes;
	bool	error;
	int		trigger;
	int		start;
	int		exit_status;
	t_token *token;
}	t_info;

void lexer(t_info *info, t_token **token);
int check_quotes(t_info *info);

/*----edited_split.c---------------------*/
char **ft_edited_split(char const *s1, char c, t_info *info);

/*----freeing.c----------------------*/
void freeing_split_text(t_info *info);
void	freeing_tokens(t_info *info, t_token *token);

int		parsing(t_info *info);
int		check_pipes(t_info *info);
int 	pipe_cases(t_info *info);
int 	quotes_in_pipe(t_info *info, char quote, int position); 
char 	**bananasplit(t_info *info);
int 	which_quote(const char *s1, int index);
int 	if_quotes_closed(t_info *info, char quote);

/*----utils.c------------------------*/
void	count_quotes(t_info *info);
int		ft_strcmp(const char *s1, const char *s2);
int 	set_error_str(t_info *info, char *message, int error);
void	count_redirections(t_info *info);
void	count_dollar_signs(t_info *info);

/*----initialize.c-------------------*/
void	initialize_info(t_info *info);

/*----initializing_list.c-------------------*/
t_token	*attach_the_last(t_token *token);
//t_token	*create_linked_list(t_info *info, t_token *token);

/*----register_the_information.c-------------*/
void	register_the_information(t_token *token, t_info *info);

#endif