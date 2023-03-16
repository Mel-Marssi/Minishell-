/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:43:29 by majmani           #+#    #+#             */
/*   Updated: 2023/03/14 14:23:38 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_switch2(char **param, int fi, t_env **en)
{
	if (ft_strcmp(ft_tolower(param[0]), "exit") == 0)
		g_exit_status = ft_exit(param);
	else if (ft_strcmp(ft_tolower(param[0]), "export") == 0)
		g_exit_status = ft_export(en, param, fi);
	else if (ft_strcmp(ft_tolower(param[0]), "unset") == 0)
		g_exit_status = ft_unset(en, param, 0, *en);
	else if (ft_strcmp(ft_tolower(param[0]), "echo") == 0)
	{
		ft_echo(param, fi);
		g_exit_status = 0;
	}
	else if (ft_strcmp(ft_tolower(param[0]), "pwd") == 0)
	{
		ft_pwd(0, fi);
		g_exit_status = 0;
	}
}

void	ft_switch(char **param, int fi, t_env **en)
{
	char	*l;

	l = my_getenv(*en, "PATH");
	if (ft_strcmp(ft_tolower(param[0]), "cd") == 0)
		g_exit_status = cd(param, en);
	else if (ft_strcmp(ft_tolower(param[0]), "env") == 0)
	{
		if (l != NULL)
		{
			ft_env(*en, 0, fi);
			g_exit_status = 0;
		}
		else
		{
			ft_putstr_fd("bash: env: No such file or directory\n", 2);
			g_exit_status = 127;
		}
	}
	else
		ft_switch2(param, fi, en);
	free(l);
}

int	norm_herdoc1(int fd, int t, int id)
{
	close(fd);
	waitpid(id, &t, 0);
	if (WEXITSTATUS(t) == 33)
	{
		g_exit_status = 1;
		return (-1);
	}
	wait(NULL);
	return (0);
}

int	norm_herdoc2(char **p)
{
	int	t;

	t = 0;
	if (ft_strchr((*p), '\'') != 0 || ft_strchr((*p), '\"') != 0)
	{
		(*p) = o_trim((*p));
		t = 1;
	}
	return (t);
}

void	norm_herdoc3(t_doc *o, t_env *en)
{
	if (ft_strchr_int(o->l, '$') != -1 && o->t == 0)
		(ft_putstr_fd(get_v_her(en, o->l), o->fd[1]));
	else
		ft_putstr_fd(o->l, o->fd[1]);
}
