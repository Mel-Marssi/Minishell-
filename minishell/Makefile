NAME= minishell
LIBFT= libft/libft.a
CC= gcc
CFLAGS= -Wall -Wextra #-Werror
FILE= workshop.c	\
	pars/initia.c	\
	pars/treat_cmd.c	\
	pars/get_var.c	\
	pars/outils_count.c	\
	pars/outils_count2.c	\
	pars/outils_fill.c	\
	pars/outils_fill2.c	\
	pars/outils_var.c	\
	pars/fill_list.c	\
	pars/strim_All.c	\
	pars/get_var_her.c	\
	pars/split_var.c	\
	pars/get_var2.c	\
	pars/fill_out.c	\
	pars/count_norm.c	\
	pars/strim.c	\
	pars/signal.c	\
	pars/ambig.c	\
	pars/get_var_h_norm.c	\
	exec/builtins.c	\
	exec/builtins1.c	\
	exec/builtins2.c	\
	exec/builtins3.c	\
	exec/builtins4.c	\
	exec/builtins5.c	\
	exec/builtins6.c	\
	exec/builtins7.c	\
	exec/outils1.c	\
	exec/outils2.c	\
	exec/outils3.c	\
	exec/execution1.c	\
	exec/execution2.c	\
	exec/outils_execution1.c	\
	exec/norm1.c	\
	exec/norm2.c	\
	exec/norm3.c	\
	exec/norm4.c	\
	exec/norm5.c	\
	exec/norm6.c	\

FILEO=$(FILE:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME):$(FILEO) $(LIBFT)
	$(CC) $(CFLAGS)  $(FILEO) $(LIBFT) -lreadline -lhistory -I/home/kaniki/homebrew/include/readline -L/home/kaniki/homebrew/opt/readline/lib -o $(NAME)

$(LIBFT):
	make all -C ./libft

clean:
	rm -rf $(FILEO)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all