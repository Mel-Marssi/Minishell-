/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:45:50 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/17 16:57:12 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include "libft/libft.h"

typedef struct s_boucle
{
	size_t	i;
	size_t	j;
}			t_boucle;
typedef struct s_var
{
	char	*left;
	char	*right;
	char	*var;
}			t_var;

typedef struct s_path
{
	char	**str;
	char	*com_total;
	char	*com;
	char	*pts;
}			t_path;
typedef struct s_doc
{
	char	*l;
	char	*p;
	int		fd[2];
	int		t;
	int		id;
}			t_doc;
int	g_exit_status;
t_inf	*last_inf(t_inf	*dst);
t_inf	*ft_inf(t_env *en, char **arr, int i);
void	add_back_cmd(t_inf	**old, t_inf *new);
void	boucle_init(t_boucle *x);
char	*ft_lost_var_r(char *arr, int i);
int		check_herdoc(char *arr);
char	*ft_lost_var_l(char *arr, int i);
char	*ft_get_var(char *arr, int i, int j);
char	**get_v_variable(t_env *en, char **arr, int i);
int		ft_dbl_len(char **arr);
void	ft_free_dbl(char **arr);
int		ft_lenght(char *cmd);
char	**cmd_trim(char **arr, int i);
int		ft_count_strings(char *cmd, int i, int count);
int		count_plus(char *arr, char c, int i, int j);
char	**fill_array(char *cmd, int i, int j, int x);
char	*put_space(char *arr, char c, int i, int j);
char	**final_str(char *str);
int		count_s_quote(char *arr);
char	**split_var_exp(char *cmd, int i, int j);
char	**fill_infil(t_env *en, char **arr, int i, int j);
char	**fill_cmd(t_env *en, char **arr, int i, int j);
char	**fill_outfil(t_env *en, char **arr, int i, int j);
char	**fix_her(char **arr, int i, int j);
int		cnt_fill_cmd(char **arr, int i, int j);
t_inf	*lst(t_env *en, char **arr, int i);
int		count_outfil(char **arr, int i, int j);
int		count_infil(char **arr, int i, int j);
t_var	fill_x(char **arr, int i);
int		ft_lenght0(char *cmd);
t_inf	*hold_str(t_env *en, char *str);
int		check_str(char *str, int i, int type_err);
char	**leave_trash(char **arr, int i);
void	free_list(t_inf **x);
void	del_nod(t_inf *x);
int		ft_add(char **str, int i, char *com_total, char *com);
int		ft_count_f(char **arr, int i);
char	**cast_env(t_env *env);
void	rl_replace_line(const char *text, int clear_undo);
int		ft_dbl_strchr(char **arr);
void	norm_plus(int *i, int *j);
void	norm_pipe(char arr, int *a);
void	norm_arr(char *arr2, char *arr, int *i, int *j);
char	*get_v_her(t_env *en, char *arr);
void	norm_cnt_cmd(int *i, int *j);
int		check_the_first(char *arr, int i);
int		count_valid(char **arr, int i, int count);
int		check_dbl_arr(char **arr);
char	*o_trim0(char *arr);
void	signal_handler(int sig);
void	disable_signal_handler(t_global **w);
char	*dbl_strjoin(char **arr);
char	**s_trim(char **arr, int i);
int		norm_get1(char *arr, int i);
int		norm_get0(char *arr, int i);
char	*check_ambiguous(t_env *en, char *outfile, int i);
char	*put_space(char *arr, char c, int i, int j);
char	*o_trim(char *arr);
void	add_h(char *str);
char	*put_space_pipe(char *arr, int i, int j);
int		check_all_am(t_env *en, char **outfile, int i);
void	set_tcg(struct termios *old, struct termios *new);
int		check_syn(char *str, int i);
t_env	*ft_replace_env(t_env *e, char **env);
int		ft_check_double(t_env *env, char *l);
int		check_alpha_num(char c);
int		ft_check_equal(char *str);
int		ft_check_variable_env(char *str, char *l);
int		ft_unset(t_env **env, char **l, int h, t_env *c);
int		ft_exit(char **param);
int		cd(char **str, t_env **en);
void	builtins(t_env **en, char **param, t_global *w);
int		check_bultins(char *str);
char	*get_path1(t_env *env, char *cmd, int i);
void	open_out_files(t_global **x, int j, int fi);
void	open_in_files(t_global **x, int i);
void	one_command(t_global **x);
void	second_proc(t_global **x, int a);
void	first_proc(t_global **x);
void	x_proc(t_global **x, int i);
void	ft_allocat_pipe(int i, int **f);
void	ft_close(t_global *w, int a);
void	multiple_pipe(t_global **x, int t);
int		count_herdoc(t_inf *x);
int		count_herdoc_2(t_inf *x);
int		ft_her_doc(t_env *en, char *argv);
void	ft_unset_e(t_env **env, char *l);
char	*my_getenv(t_env *env, char *str);
char	*my_getenv_her(t_env *env, char *str);
int		ft_export(t_env **env, char **l, int file);
char	*ft_pwd(int c, int file);
void	ft_echo(char **str, int file);
void	ft_env(t_env *env, int c, int file);
int		position_plus(char *str);
int		check_value(char *str, int c);
t_env	*sort_export(t_env *env, int (*cmp)(const char *, const char *));
int		check_plus(char *l);
char	*del_plus(char *str);
int		my_strcmp(const char *s1, const char *s2);
int		ft_check_param(char *s);
void	join_export(t_env **env, char *l, int k);
void	ft_pri_er(char *str1, char *variable, char *str2);
t_env	*copier_env(t_env *e);
void	ft_free_her(t_her *lst);
void	ft_free_int(int **arr, int j);
void	print_export(t_env *env, int file);
int		ft_condition(char *l);
void	ft_pri_er(char *str1, char *variable, char *str2);
void	ft_export2(t_env **env, char *l);
void	utils_echo(char **str, int *etat, int *i, int *j);
int		utils_cd2(t_env **en);
void	utils_cd(t_env **en);
void	del_env(t_env *x);
void	free_env(t_env **x);
int		norm_export(t_env *env, int file);
int		norm_cd(char *str, int c);
int		norm_unset(int *t);
void	norm_unset1(t_env **p, t_env **c);
int		norm_unset2(t_env **env, t_env **c);
void	utils_multiple_pipe(t_global **w, int t, int id, int i);
t_her	*ft_lstnew_her(int i);
t_her	*ft_lstlast_her(t_her *lst);
void	ft_lstadd_back_her(t_her **lst, t_her *new);
int		open_herdoc(t_env *en, t_her **h, t_inf *x);
void	ft_allocat(int i, int **f);
void	norm_get_path(char *cmd);
int		check_plus(char *l);
void	del_env0(t_env **x);
int		ft_condition(char *l);
void	ft_pri_er(char *str1, char *variable, char *str2);
char	**one_to_dbl(char *p);
void	handel_her(int sig);
int		count_herdoc(t_inf *x);
int		count_herdoc_2(t_inf *x);
void	ft_switch2(char **param, int fi, t_env **en);
void	ft_switch(char **param, int fi, t_env **en);
int		norm_herdoc1(int fd, int t, int id);
int		norm_herdoc2(char **p);
void	norm_herdoc3(t_doc *o, t_env *en);
void	norm_join_export(t_env **env, char *copier, char *s);
void	norm_unset3(t_env **p, int *t, int h);
int		norm_unset4(char **l, int *t);
void	norm_out_file(int fi, char *file);
char	*norm_return1(char *pts, char *cmd);
char	*norm_return2(char *pts);
#endif