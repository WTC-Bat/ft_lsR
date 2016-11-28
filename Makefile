NAME = ft_ls
SRC = "./src/"
HEAD = "./includes/"
HEADLFT = "./libft/"
FLAGS = -Wall -Werror -Wextra
SRCS = $(SRC)ft_ls.c $(SRC)arg_funcs.c $(SRC)lsargs_funcs.c $(SRC)ls_funcs.c \
		$(SRC)ls_set_permissions.c $(SRC)format_time.c $(SRC)ls_format.c \
		$(SRC)get_longest.c $(SRC)ls_print.c $(SRC)ls_print_members.c \
		$(SRC)ls_sort.c $(SRC)do_sort.c $(SRC)ls_recursion.c

all:$(NAME)

$(NAME):
	cd libft && $(MAKE) && $(MAKE) clean
	mv libft/libft.a ./
	gcc $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft.a -o ft_ls
	# gcc -I$(HEAD) -I$(HEADLFT) $(SRCS) libft.a -o ft_ls

dbg:
	cd libft && $(MAKE) && $(MAKE) clean
	mv libft/libft.a ./
	gcc -g -o0 $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft.a -o ft_ls

clean:
	rm -f libft.a

fclean: clean
	rm -f $(NAME)

re: fclean all
