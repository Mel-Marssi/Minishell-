/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:35:17 by majmani           #+#    #+#             */
/*   Updated: 2023/03/18 10:35:44 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	norm_join_export(t_env **env, char *copier, char *s)
{
	ft_unset_e(env, copier);
	if (ft_strchr(copier, '=') != 0)
		ft_lstadd_back(env, ft_lstnew(ft_strjoin(copier, s), 0, 1));
	else
		ft_lstadd_back(env,
			ft_lstnew(ft_strjoin_gnl(ft_strjoin(copier, "="), s), 0, 1));
	(free(s), free(copier));
}

void	norm_unset3(t_env **p, int *t, int h)
{
	p = NULL;
	(*t) = h;
	if ((*t) == 0)
		(*t)++;
}

int	norm_unset4(char **l, int *t)
{
	ft_pri_er("Minishell: unset:`", l[(*t)], "':not a valid identifier\n");
	if ((*t) + 1 >= ft_dbl_len(l))
		return (1);
	else
		(*t)++;
	return (0);
}

void	norm_out_file(int fi, char *file, t_global w)
{
	if (fi == -1 && if_amb(w, file) != 1)
		(ft_pri_er("Minishell :",
				file, ": Is a directory\n"));
	exit(1);
}
