/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_her.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:10:56 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/19 18:51:22 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_lost_var_r0(char *arr, int i)
{
	char	*str;

	i = find_dolr(arr, i);
	if (i < (int )ft_strlen(arr) && arr[i] == '?')
		return (ft_strdup(&arr[i + 1]));
	while (arr[i] && !ft_strchr(" +*-\'\"|:;$<?>\t\r,.=/", arr[i]))
		i++;
	str = ft_strdup(&arr[i]);
	return (str);
}

static char	*ft_lost_var_l0(char *arr, int i)
{
	char	*str;
	int		j;

	i = find_dol_l(arr, i);
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	j = i;
	i = 0;
	while (arr[i] && i < j)
	{
		str[i] = arr[i];
		i++;
	}
	return (str);
}

static char	*ft_get_var0(char *arr, int *i, int j)
{
	char	*str;

	if (ft_strcmp(arr, "$") == 0)
		return (ft_strdup("$"));
	(*i) = find_dol_v(arr, *i);
	if (arr[*i - 1] == '$' && arr[*i] == '\n')
		return (ft_strdup("$"));
	if (*i < (int)ft_strlen(arr) && arr[*i] == '?')
		return (ft_strdup("?"));
	while (arr[*i] && !ft_strchr(" +*#-\'\"|:;$<?>\t\r,.=/", arr[*i]))
	{
		(*i)++;
		j++;
	}
	str = ft_calloc(j + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	(*i) = (*i) - j;
	j = 0;
	while (arr[*i] && !ft_strchr(" +*#-\'\"|:;$<?>\t\r,.=/", arr[*i]))
		str[j++] = arr[(*i)++];
	return (str);
}

static t_var	fill_y(char *arr, int *i)
{
	t_var	x;

	x.left = ft_lost_var_l0(arr, 0);
	x.right = ft_lost_var_r0(arr, 0);
	x.var = ft_get_var0(arr, i, 0);
	return (x);
}

char	*get_v_her(t_env *en, char *arr, int i)
{
	t_var	x;
	char	*str;

	while (arr[i])
	{
		if (ft_strcmp(arr, "$") == 0 || stop_loop(arr, 0) != 2)
			break ;
		x = fill_y(arr, &i);
		str = my_getenv_her(en, x.var);
		if (str == NULL)
		{
			x.left = ft_strjoin_gnl(x.left, str);
			x.left = ft_strjoin_gnl(x.left, x.right);
			free(arr);
			arr = ft_strdup(x.left);
			(free(x.var), free(x.right), free(x.left));
			continue ;
		}
		x.left = ft_strjoin_gnl(x.left, str);
		x.left = ft_strjoin_gnl(x.left, x.right);
		(free(arr), free(str));
		arr = ft_strdup(x.left);
		(free(x.var), free(x.right), free(x.left));
	}
	return (arr);
}
