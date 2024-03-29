/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_execution1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:32:52 by majmani           #+#    #+#             */
/*   Updated: 2023/03/25 15:08:11 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

char	*get_path1(t_env *env, char *cmd, int i)
{
	t_path	l;

	l.pts = my_getenv(env, "PATH");
	if (ft_strcmp(cmd, "") == 0)
		return (NULL);
	norm_get_path(cmd);
	if (access(cmd, X_OK) != -1)
		return (norm_return1(l.pts, cmd));
	l.str = ft_split(l.pts, ':');
	if (l.str == NULL)
		return (norm_return2(l.pts));
	l.com = ft_strjoin("/", cmd);
	l.com_total = ft_strjoin(l.str[i], l.com);
	while (l.str[i] && access(l.com_total, X_OK) == -1)
	{
		free(l.com_total);
		l.com_total = ft_strjoin(l.str[i++], l.com);
	}
	if (!l.str && access(cmd, X_OK) != -1)
		return (norm_return1(l.pts, cmd));
	if (ft_add(l.str, i, l.com_total, l.com) == 0)
		return (norm_return2(l.pts));
	free(l.pts);
	return (l.com_total);
}

char	*my_getenv_her(t_env *env, char *str)
{
	char		*s;
	t_boucle	o;
	t_env		*en;

	boucle_init(&o);
	en = env;
	s = NULL;
	if (ft_strcmp(str, "?") == 0)
		return (ft_itoa(g_exit_status));
	if (ft_strcmp(str, "$") == 0)
		return (ft_strdup("$"));
	if (ft_strlen(str) == 0)
		return (NULL);
	while (str && en != NULL && ft_strncmp(en->content, str,
			ft_strchr_int(en->content, '=')) != 0)
		en = en->next;
	if (str && en != NULL && ft_strncmp(en->content,
			str, ft_strlen(str) - 1) == 0)
	{
		o.i = ft_check_equal(en->content);
		s = ft_neww_strdup(en->content, o.i);
	}
	return (s);
}

int	ft_her_doc(t_env *en, char *argv)
{
	t_doc			o;
	struct termios	a2;

	tcgetattr(0, &a2);
	if (pipe(o.fd) == -1)
		perror("pipe");
	o.id = fork();
	if (o.id == 0)
	{
		a2.c_cc[VQUIT] = _POSIX_VDISABLE;
		(tcsetattr(0, 0, &a2), signal(SIGINT, handel_her)
			, signal(SIGQUIT, SIG_IGN));
		o.p = ft_strjoin(argv, "\n");
		o.t = norm_herdoc2(&o.p);
		ft_fct(&o, en);
		(free(o.l), close(o.fd[1]), exit(0));
	}
	else
		if (norm_herdoc1(o.fd[1], o.t, o.id) == -1)
			return (-1);
	return (o.fd[0]);
}

void	open_in_files(t_global **w, int i)
{
	int		fi;
	char	*j;

	fi = 0;
	while (((*w)->x->data).infile[++i] != NULL)
	{
		j = ft_strdup(((*w)->x->data).infile[i]);
		if (ft_strncmp(((*w)->x->data).infile[i], "<<", 2) == 0)
			fi = (*w)->h->i;
		else
		{
			j = check_ambiguous((*w)->env, j, 0);
			if (j != NULL && ft_strcmp(j, "") != 0)
				fi = open(o_trim(((*w)->x->data).infile[i]), O_RDONLY);
			if (fi == -1 || fi == 0)
			{
				if (fi == -1 && if_amb(**w, ((*w)->x->data).infile[i]) == 0)
					(ft_pri_er("Minishell : ", j,
							" No such file or directory\n"));
				(free(j), exit(1));
			}
		}
		free(j);
	}
	dup2(fi, 0);
}

void	open_out_files(t_global **w, int j, int fi)
{
	while (++j < ((*w)->x->data).max && ((*w)->x->data).outfile[j] != NULL)
	{
		if (ft_strncmp(((*w)->x->data).outfile[j], ">>", 2) == 0)
		{
			((*w)->x->data).outfile[j] = check_ambiguous((*w)->env,
					((*w)->x->data).outfile[j], 0);
			if (((*w)->x->data).outfile[j] != NULL
				&& ft_strcmp(((*w)->x->data).outfile[j], "") != 0)
				fi = open(((*w)->x->data).outfile[j],
						O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		else
		{
			((*w)->x->data).outfile[j] = check_ambiguous((*w)->env,
					((*w)->x->data).outfile[j], 0);
			if (((*w)->x->data).outfile[j] != NULL
				&& ft_strcmp(((*w)->x->data).outfile[j], "") != 0
				&& if_amb(**w, ((*w)->x->data).outfile[j]) == 0)
				fi = open(((*w)->x->data).outfile[j],
						O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		if ((fi == -1 || fi == 0))
			norm_out_file(fi, ((*w)->x->data).outfile[j], **w);
	}
	dup2(fi, 1);
}
