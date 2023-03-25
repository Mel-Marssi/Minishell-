/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:15:25 by majmani           #+#    #+#             */
/*   Updated: 2023/03/25 15:02:19 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	utils_echo(char **str, int *etat, int *i, int *j)
{
	while (str[(*i)] && ft_strncmp(str[(*i)], "-n", 2) == 0)
	{
		if (ft_strncmp(str[(*i)], "-n", 2) == 0)
		{
			(*j) = 2;
			while (str[(*i)][(*j)] == 'n')
				(*j)++;
			if ((*j) == (int)ft_strlen(str[(*i)]))
				(*etat) = 1;
			else
				break ;
			(*i)++;
		}
	}
}

void	utils_cd(t_env **en)
{
	char	*dest;
	char	*str;

	dest = my_getenv(*en, "PWD");
	str = ft_pwd(1, 1);
	if (dest != NULL)
	{
		ft_unset_e(en, "OLDPWD");
		ft_lstadd_front(en,
			ft_lstnew(ft_strjoin("OLDPWD=", dest), 0, 1));
		ft_unset_e(en, "PWD");
		ft_lstadd_front(en, ft_lstnew(ft_strjoin("PWD=", str), 0, 1));
	}
	else
	{
		ft_unset_e(en, "OLDPWD");
		ft_lstadd_front(en, ft_lstnew("OLDPWD=", 0, 1));
	}
	if (str != NULL)
		free(str);
	if (dest != NULL)
		free(dest);
}

int	utils_cd2(t_env **en)
{
	int		r;
	char	*dst;

	dst = my_getenv(*en, "OLDPWD");
	r = chdir(dst);
	free(dst);
	return (r);
}
