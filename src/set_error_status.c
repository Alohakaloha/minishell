#include "../includes/minishell.h"

int	set_error_str(t_info *info, char *message, int error)
{
	info->exit_status = error;
	printf("%s", message);
	return (0);
}