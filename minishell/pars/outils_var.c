/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:30:51 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/11 09:48:17 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_x0(t_env *en, t_var *x)
{
	char	*str;

	str = my_getenv(en, x->var);
	x->left = ft_strjoin_gnl(x->left, str);
	x->left = ft_strjoin_gnl(x->left, x->right);
	free(str);
}

void	norm_v(t_env *en, char **arr, int i)
{
	t_var	x;
	char	*str;

	x = fill_x(arr, i);
	str = my_getenv(en, x.var);
	if (str == NULL)
	{
		fill_x0(en, &x);
		free(arr[i]);
		arr[i] = ft_strdup(x.left);
		i++;
		(free(x.var), free(x.right), free(x.left));
		return ;
	}
	fill_x0(en, &x);
	(free(str), free(arr[i]));
	arr[i] = ft_strdup(x.left);
	(free(x.var), free(x.right), free(x.left));
}

char	*dbl_strjoin(char **arr)
{
	char	*dst;
	int		i;

	dst = ft_strjoin(arr[0], arr[1]);
	i = 2;
	while (arr[i])
	{
		dst = ft_strjoin_gnl(dst, arr[i]);
		i++;
	}
	return (dst);
}

void	norm_get(t_env *en, char **arr, int j)
{
	while (arr[j])
	{
		while (arr[j] && ft_strchr(arr[j], '$') != 0)
		{
			if (ft_strcmp(arr[j], "$") == 0)
				break ;
			if ((arr[j] && ft_strchr(arr[j], '$') == 0)
				|| (j >= 1 && check_herdoc(arr[j - 1]) == '<'))
				j++;
			norm_v(en, arr, j);
			if (ft_strchr(arr[j], '\'') != 0 && check_the_first(arr[j], 0) == 1)
				j++;
		}
		j++;
	}
}

char	**get_v_variable(t_env *en, char **arr0, int i)
{
	char	**arr;

	while (arr0[++i])
	{
		arr = split_var_exp(arr0[i], 0, 0);
		norm_get(en, arr, 0);
		arr = cmd_trim(arr, 0);
		free(arr0[i]);
		arr0[i] = dbl_strjoin(arr);
		ft_free_dbl(arr);
	}
	return (arr0);
}
