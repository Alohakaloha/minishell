#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct s_env
{
	char			*env_str;
	char			*var;
	char			*value;
	int				check;
	int				index;
	struct s_env	*next;
	struct s_env	*prev;
} t_env;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_env *new_node(char *string)
{
	t_env *new;
	size_t len;

	len = strlen(string) + 1;
	new = (t_env *)malloc(sizeof(*new));
	new->env_str = malloc(sizeof(char) + len);
	memcpy(new->env_str, string, len);
	new->check = 0;
	new->next = NULL;
	return (new);
}

t_env	*last_node(t_env *head)
{
	t_env	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	add_to_end(t_env **list, t_env *new)
{
	t_env	*n;

	if (*list)
	{
		n = last_node(*list);
		n->next = new;
		n->next->prev = n;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
		(*list)->prev = NULL;
	}
}

void copy_environment(t_env **environment, char **envv)
{
	int i;
	t_env *new;

	i = 0;
	while (envv[i])
	{
		new = new_node(envv[i]);
		add_to_end(environment, new);
		i++;
	}
}


void printlist(t_env *head)
{
	t_env *tmp;

	tmp = head;
	printf("\n\n\nHere is my passed list\n\n\n");
	while (tmp)
	{
		printf("??? = %s\n", tmp->env_str);
		tmp = tmp->next;
	}
}

/*
@compare string returns 1 if the first string is smaller than the second one
	else 0 in case of same string or -1 if it is smaller
 */
int	compare_str(const char *st1, const char *st2)
{
	size_t	i;

	i = 0;
	while(st1[i])
	{
		if(st1[i] > st2[i])
		{
//			printf("\nWe compare %c with %c \n", st1[i], st2[i]);
//			printf("From %s\nand \n %s",st1, st2);
			return(1);
		}
		else if(st1[i] < st2[i])
			return (-1);
		else
			i++;
	}
	if (!st1[i] && st2[i])
		return (-1);
	return (0);
}

int	check_size(t_env *list)
{
	t_env	*current;
	int		nbr_elements;

	current = list;
	nbr_elements = 0;
	while(current)
	{
		nbr_elements++;
		current = current->next;
	}
	return (nbr_elements);

}


char *unchecked_str(t_env *env, char	*biggest)
{
	t_env	*current;

	current = env;
	while(current->check != 0 && current)
			current = current->next;
		if (current)
		{
			biggest = current->env_str;
		}
	while(current)
	{
		if(compare_str(biggest, current->env_str) < 0 && current->check == 0)
			biggest = current->env_str;
		else
			current = current->next;

	}
	return (biggest);
}

void add_index(t_env *env)
{
	int		list_size;
	char	*biggest;
	t_env	*current;

	biggest = NULL;
	list_size = check_size(env);
	while(list_size > 0)
	{
	current = env;
	biggest = unchecked_str(env, biggest);
	if (biggest == NULL)
		return;
	current = env;
 	while(compare_str(current->env_str, biggest) != 0)
	{
		current = current->next;
	}
	current->index = list_size;
	list_size--;
	current->check = 1;
	}
}

void	print_by_index(t_env *env)
{
	int		nbr;
	int		list_size;
 	t_env	*current;

	nbr = 1;
	list_size = check_size(env);
	printf("The list size is %i\n",list_size);
	printf("The nbr = %i\n", nbr);
 	while(nbr < list_size)
	{
		current = env;
		while(current->index != nbr)
			current = current->next;
		printf("declare -x %s\n", current->env_str );
		nbr++;
	}
}

int main(int argc, char **argv, char **envv)
{
	t_env *env;

	if(argc > 1)
		printf("%s doens't need arguments!\n", argv[0]);
	copy_environment(&env, envv);
	add_index(env);
	print_by_index(env);
//	printlist(env);
	return(0);
}