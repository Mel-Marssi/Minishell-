/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:35:35 by majmani           #+#    #+#             */
/*   Updated: 2023/03/25 15:07:48 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

int	check_bultins(char *str)
{
	if (str != NULL && (ft_strcmp(str, "pwd") == 0
			|| ft_strcmp(str, "echo") == 0
			|| ft_strcmp(str, "cd") == 0 || ft_strcmp(str, "env") == 0
			|| ft_strcmp(str, "exit") == 0 || ft_strcmp(str, "export") == 0
			|| ft_strcmp(str, "unset") == 0))
		return (1);
	return (0);
}	

int	open_in_file2(t_global *w, int fi, char **infile)
{
	int		i;
	char	*str;

	i = -1;
	while (infile[++i] != NULL)
	{
		if (ft_strncmp(infile[i], "<<", 2) != 0)
		{
			infile[i] = check_ambiguous(w->env, infile[i], 0);
			if (infile[i] != NULL && ft_strcmp(infile[i], "") != 0)
			{
				str = o_trim0(infile[i]);
				(fi) = open(str, O_RDONLY);
				free(str);
			}
			if ((fi) == -1 || fi == 0)
			{
				if ((fi) == -1 && if_amb(*w, ((w)->x->data).infile[i]) != 1)
					(ft_pri_er("", infile[i], " No such file or directory\n"));
				g_exit_status = 1;
				return (-1);
			}
		}
	}
	return (0);
}

int	open_out_file2(t_global *w, int *fi, int j, char **outfile)
{
	while (++j < (w->x->data).max && outfile[j] != NULL)
	{
		if (ft_strncmp(outfile[j], ">>", 2) == 0)
		{
			outfile[j] = check_ambiguous(w->env, outfile[j], 0);
			if (outfile[j] != NULL && ft_strcmp(outfile[j], "") != 0)
				(*fi) = open(outfile[j], O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		else
		{
			outfile[j] = check_ambiguous(w->env, outfile[j], 0);
			if (outfile[j] != NULL && ft_strcmp(outfile[j], "") != 0)
				(*fi) = open(outfile[j], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		if ((*fi) == -1 || (*fi) == 1)
		{
			if ((*fi) == -1 && if_amb(*w, ((w)->x->data).outfile[j]) != 1)
				(ft_pri_er("", outfile[j], ": Is a directory\n"));
			g_exit_status = 1;
			return (-1);
		}
	}
	return (0);
}

void	builtins(t_env **en, char **param, t_global *w)
{
	int	i;
	int	fi;
	int	h;

	h = 0;
	i = 0;
	fi = 1;
	if ((w->x->data).infile[0] != NULL)
		h = open_in_file2(w, 0, (w->x->data).infile);
	if ((w->x->data).outfile[0] != NULL && h != -1)
		h = open_out_file2(w, &fi, -1, (w->x->data).outfile);
	if (fi == -1)
		g_exit_status = 1;
	if (h != -1)
		ft_switch(param, fi, en);
}
