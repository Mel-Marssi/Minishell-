/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:53:10 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/14 17:01:28 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <termios.h>
# include <limits.h>

void	rl_replace_line(const char *text, int clear_undo);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
char	*ft_tolower(char *c);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *need, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
long	count_num(long nbr, int base);
int		ft_hexadecimal(unsigned int nb, char c);
int		ft_hex_adress(size_t nb, char c);
int		ft_ip(size_t ip);
int		ft_putuns(unsigned int nb);
size_t	ft_check_line(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
char	*get_next_line_multi(int fd);
int		ft_strchr_int(const char *s, int c);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
typedef struct s_data
{
	int		max;
	char	**infile;
	char	**outfile;
	char	**cmd;
}			t_data;
typedef struct s_inf
{
	t_data			data;
	struct s_inf	*next;
}					t_inf;
typedef struct s_env
{
	char			*content;
	int				option;
	int				old;
	struct s_env	*next;
}	t_env;
typedef struct s_her
{
	int				i;
	struct s_her	*next;
}			t_her;
typedef struct s_global
{
	t_inf			*x;
	t_her			*h;
	t_env			*env;
	char			*str;
	int				**f;
	int				*proc;
	int				count;
	struct termios	old;
	struct termios	new;
}			t_global;

t_env	*ft_lstnew(char *content, int c, int old);
void	ft_lstadd_front(t_env **lst, t_env *new);
int		ft_lstsize(t_inf *lst);
t_env	*ft_lstlast(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize1(t_env *lst);
#endif
