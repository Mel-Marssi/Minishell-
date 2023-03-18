NAME=	libft.a
cc=	cc 
CFLAGS=	-Wall -Wextra -Werror
PRINTF = echo
AF=	ft_isalpha.c	\
ft_isdigit.c	\
ft_isalnum.c	\
ft_isascii.c	\
ft_toupper.c	\
ft_tolower.c	\
ft_isprint.c	\
ft_atoi.c	\
ft_strncmp.c	\
ft_strcmp.c	\
ft_bzero.c	\
ft_memset.c	\
ft_memcpy.c	\
ft_memmove.c	\
ft_memchr.c	\
ft_memcmp.c	\
ft_strlcpy.c	\
ft_strlcat.c	\
ft_strlen.c	\
ft_strchr.c	\
ft_strrchr.c	\
ft_calloc.c	\
ft_strnstr.c	\
ft_strdup.c	\
ft_substr.c	\
ft_strjoin.c	\
ft_strtrim.c	\
ft_split.c	\
ft_itoa.c	\
ft_strmapi.c	\
ft_striteri.c	\
ft_putchar_fd.c	\
ft_putstr_fd.c	\
ft_putendl_fd.c	\
ft_putnbr_fd.c	\
ft_printf.c	\
ft_printnum.c	\
ft_printstr.c	\
ft_unsigned.c	\
get_next_line.c	\
get_next_line_utils.c	\
get_next_line_multi.c	\
ft_lstnew_bonus.c	\
ft_lstadd_front_bonus.c	\
ft_lstsize_bonus.c	\
ft_lstlast_bonus.c	\
ft_lstadd_back_bonus.c	\
ft_lstdelone_bonus.c	\
ft_lstclear_bonus.c	\
ft_lstiter_bonus.c	\

HLB=	$(AF:.c=.o)

%.o : %.c
	@$(cc) $(CFLAGS) -c  $?
	@$(PRINTF) "Compiling Libft ..."

all:	$(NAME)
	
$(NAME):	$(HLB)
	@ar rc $(NAME) $(HLB)
	


clean:
	@rm -f $(HLB) $(BONUSO)
	@$(PRINTF) "Cleaning Libft ...\n"

fclean:	clean
	@rm -f $(NAME)
	@$(PRINTF) "Deleting libft.a\n"

re: fclean all
