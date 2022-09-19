CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = minishell

MAIN =	./src/main.c

OBJS = ${SOURCES:.c=.o}

LIBFT = libft
LIBFT_NAME = libft.a

$(NAME)	:	$(SOURCES)
	@make  -sC ./libft
	@echo "Compiling minishell..."
	$(CC) $(CFLAGS) $(MAIN) $(SOURCES) -L$(LIBFT) -lft -lreadline -g -o $(NAME)

all: $(NAME)

clean:
	@make clean -sC ./libft
	@echo "Removing object files..."
	@rm -f ${OBJS}

fclean:	clean
	@make fclean -sC ./libft
	@echo "Removing minishell..."
	@rm -f ${NAME}

re:	fclean all

re_bonus:	fclean bonus

.PHONY:	clean fclean re re_bonus