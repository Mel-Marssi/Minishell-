/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:42:12 by majmani           #+#    #+#             */
/*   Updated: 2023/03/12 22:55:45 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	norm_export(t_env *env, int file)
{
	print_export(env, file);
	return (0);
}

int	norm_cd(char *str, int c)
{
	if (c == 0)
	{
		ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (c == 1)
	{
		ft_pri_er("Minishell: cd :", str, " : No such file or directory\n");
		return (1);
	}
	return (0);
}

int	norm_unset(int *t)
{
	*t = 0;
	return (0);
}

void	norm_unset1(t_env **p, t_env **c)
{
	(*p) = (*c);
	(*c) = (*c)->next;
}

int	norm_unset2(t_env **env, t_env **c)
{
	*env = (*c)->next;
	free((*c));
	return (0);
}
