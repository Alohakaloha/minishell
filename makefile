CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = minishell

MAIN =	./src/main.c \
		./src/utils.c \
		./src/freeing.c \
		./src/initialize.c \
		./src/set_error_status.c\
		./src/register_tokens.c\
		./src/check_pipes.c \
		./src/check_quotes.c \
		./src/initializing_list.c \
		./src/lexer.c \


OBJS = ${SOURCES:.c=.o}

LIBFT = libft
LIBFT_NAME = libft.a

$(NAME)	:	$(SOURCES)
	@make  -sC ./libft
	@echo "Compiling minishell..."
	$(CC) $(CFLAGS) $(MAIN) $(SOURCES) -L$(LIBFT) -g -lft -lreadline -o $(NAME)
	@echo "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
oooooooooooooooooooooooooooooooddoooodddddoooooooooooooooooooooooooooooooooooooo\n\
ooooooooooooooooooooooooooolc:;,,''''',,,;;:ccloodoooooooooooooooooooooooooooooo\n\
ooooooooooooooooooooodoc;,,,,,;;:coolcc:;;;,,,,,,,:odooooooooooooooooooooooooooo\n\
oooooooooooooooooooc;,',;coddxxxddddddddddxxxddolc;,;codoooooooooooooooooooooooo\n\
oooooooooooooooo:,,,;cldddddddddollllllllllllooodddo:,,;cooooooooooooooooooooooo\n\
ooooooooooooool,'cdxxddddddollllllllllllooooolllloodddl:,,;coooooooooooooooooooo\n\
ooooooooooooo:',dxxxxxddollllooooooooooooooooooolllllooddl;,,;looooooooooooooooo\n\
oooooooooodl,'cdxxddddolloooooooooooooooooooooooooollllooddoc;',looooooooooooooo\n\
ooooooooooc',oxxdddodoooooooooooooooooooooooooooooooooooooooodc.'ldooooooooooooo\n\
oooooooood:.cxddoooooooooddoolllllllllllllllloooooooooooooooooo:.,oooooooooooooo\n\
oooooooood:.;xdooooolccc::cccccccccccccc::::::::::;coooooooooooo;.;ooooooooooooo\n\
oooooooood:.;xdoc;:ccloodxkOOOOOOOOOOOOOOkkOkkkxxdc,cdoodoooooooo;.;oooooooooooo\n\
oooooooood:.,do:,cx00000OOOOOOOOOOOOOOOOOOOOOOOOOkx:,ododooooooooo,.:doooooooooo\n\
oooooooood,.:d:ck00K00000OOOOOOOOOOOOOOOOOOOOO0000k:;oddddooooooool'.cdooooooooo\n\
oooooooooo'.c::0XKKK000OOOOOOOOOOOOOOOOOOOOOOOO000koodddddddooooood:.,oooooooooo\n\
oooooooooo'.;:xNKKKK0000OOOOOOOOOOOOOOOOOOOOOOOOOOxddxdddddddoooood:.,oooooooooo\n\
oooooooooo, .lKXXKKKK000OOOO00000OOOOOOOOOOOOOOOOkxdddddddddddoooodc.'oooooooooo\n\
oooooooooo, 'kKXKKKK00OOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkddddddddddooodl..ldoooooooo\n\
oooooooood;.:OK0kxxddxkkkkkkkkkkxoccccccccldkkOOOOOOOOkxdddddddddodl..ldoooooooo\n\
oooooooood:.:0Oo:;,,,;:oxxxkkxxo:,',;,;;;;:lddxxkOOOOOOOkooddddddddl.'odoooooooo\n\
oooooooood:.,c::c::;,'';oxxkkxxl'';:c;,''..';;:loxkOOOOOOxodddddddd;.;dooooooooo\n\
ooooooooodl..cdo::c,.  .;:clll:''looc:,    .;;.':::ccllodoloddddddl.'odooooooooo\n\
oooooooooxl'lOkocoo'   ,''lddo;.cxddddc.. ..:o;,dxddoolllc:;:;;::c' .coooooooooo\n\
oooooooooo,;kOOkkkdc:;co;'x0OOc'lxdddddoooodxxc'oOkOOOOO00xooolc,.''..ldoooooooo\n\
oooooooooo';OK00OOkxxxxk;.o0OOx:,cxxxxxxxxxxko,:kOOOOOOOOOxloddxddxx:.;doooooooo\n\
ooooooooool,;kK0000OO0Ol.:O0OOOko,;oxkOOOOOkl,ckOOO0OOOOOOxdxkkddxkko..ldooooooo\n\
oooooooooodl..ldxkOkdl:''xKOOOkkkd::::cccccccokOO0O0OOOOOkkkkOOxddkkc.,ooooooooo\n\
oooooooooooo'.:ollllclo:dK0OOOOkkkddddolcldkkkkOOOOOOOOkkkkkOkxxxxko.'ldoooooooo\n\
oooooooooood;.oK000OOkl;oxkkxdolokl;oxxxxxxxxkkkkkkkkkkkkxxxkdlkOOx'.ldooooooooo\n\
ooooooooooodc.l00OOOOkxdlldddl::ldddxkxxxxxxxxxxxkkkkkkkxxxkxldOOk;.cdoooooooooo\n\
ooooooooooodo,:O0OOOOkkOkkxddddddxxxxxxxxxxxxxxxxxxxxxxxxxxo:,:dd;.:oooooooooooo\n\
ooooooooooood:,dOOOOkxxxxxxdddddddddxddddddxxxxxxxxxxxxxxxxllo'.':looooooooooooo\n\
oooooooooooodl';kOOkxdddddddddddoollc:;::lodxxxxxxxxxxxxxxxxxd'.ldoooooooooooooo\n\
oooooooooooood:.lkkkxo:cllc:::::;;;::ccccldddxxddddxxxxxxdxxxc.;oooooooooooooooo\n\
ooooooooooooooo;,lxkkddkOOkkxxxdddxxxxxxxxxddxxddddddddddddxkc.;oooooooooooooooo\n\
ooooooooooooooooc;;lxxxkOOkxxxddddxxxxxxxxdddddddddddddddddxkx,.cdoooooooooooooo\n\
oooooooooooooooooo:',oxxkOOOkkxxxxxxxkxxxdddddddoccoddddddxkkko.'ooooooooooooooo\n\
oooooooooooooooooool;';okOOOkkxxxxxxxxxdddddddl;,;codddddxxkkkk:.:dooooooooooooo\n\
oooooooooooooooooooool,':oxkxxxdddddddddddoc;;,;coddddddxxxkkkOx,.cooooooooooooo\n\
oooooooooooooooooooooooc'..,,;::;;;;;::;;,;;:codddddddxxxxxkkkkko;:ooooooooooooo\n\
ooooooooooooooooooooooodo'.:c;;;;;;;::cccloddodddddddxxxxxxkkxxxxdoooooooooooooo\n\
oooooooooooooooooooooooodc.,kOkxddooooooooodddddddddxxxxxxxxxdddoooooooooooooooo\n\
oooooooooooooooooooooooooo,.lOOOkddddddddddddddddddxxxxxxxdddooooooooooooooooooo\n\
ooooooooooooooooooooooooool.'xOkkkxxdddddddddddddddxxxxdddoooooooooooooooooooooo\n\
ooooooooooooooooooooooooooo;.cOkkkkxdddddddddddddddddddooooooooooooooooooooooooo"

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