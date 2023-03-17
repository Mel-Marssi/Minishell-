/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_her.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:10:56 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/14 09:56:19 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_lost_var_r0(char *arr, int i)
{
	char	*str;

	while (arr[i] && arr[i] != '$')
		i++;
	if (arr[i] != '\0')
		i++;
	while (arr[i] && !ft_strchr(" +*-\'\"|:;$<?>\t\r,.=/", arr[i]))
		i++;
	str = ft_strdup(&arr[i]);
	return (str);
}

static char	*ft_lost_var_l0(char *arr, int i)
{
	char	*str;
	int		j;

	while (arr[i] && arr[i] != '$')
		i++;
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

static char	*ft_get_var0(char *arr, int i, int j)
{
	char	*str;

	while (arr[i] && arr[i] != '$')
		i++;
	if (arr[i] != '\0')
		i++;
	while (arr[i] && !ft_strchr(" +*-\'\"|:;$<?>\t\r,.=/", arr[i]))
	{
		i++;
		j++;
	}
	str = ft_calloc(j + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = i - j;
	j = 0;
	while (arr[i] && !ft_strchr(" +*-\'\"|:;$<?>\t\r,.=/", arr[i]))
	{
		str[j] = arr[i];
		j++;
		i++;
	}
	return (str);
}

static t_var	fill_y(char *arr)
{
	t_var	x;

	x.left = ft_lost_var_l0(arr, 0);
	x.right = ft_lost_var_r0(arr, 0);
	x.var = ft_get_var0(arr, 0, 0);
	return (x);
}

char	*get_v_her(t_env *en, char *arr)
{
	t_var	x;

	while (ft_strchr(arr, '$') != 0)
	{
		x = fill_y(arr);
		if (my_getenv_her (en, x.var) == NULL)
		{
			x.left = ft_strjoin_gnl(x.left, my_getenv_her(en, x.var));
			x.left = ft_strjoin_gnl(x.left, x.right);
			arr = ft_strdup(x.left);
			(free(x.var), free(x.right), free(x.left));
			continue ;
		}
		x.left = ft_strjoin_gnl(x.left, my_getenv_her(en, x.var));
		x.left = ft_strjoin_gnl(x.left, x.right);
		arr = ft_strdup(x.left);
		(free(x.var), free(x.right), free(x.left));
	}
	return (arr);
}
