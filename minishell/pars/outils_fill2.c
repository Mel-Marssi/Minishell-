/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_fill2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:51:00 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/19 16:47:48 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_fix_her(char **arr, int i, int j)
{
	while (arr[i])
	{
		if (arr[i] && ft_strcmp(arr[i], "<<") == 0)
		{
			j -= 1;
			i += 2;
		}
		else
		{
			j++;
			i++;
		}
	}
	return (j + 1);
}

char	**fix_her(char **arr, int i, int j)
{
	char	**arr2;

	arr2 = ft_calloc(ft_dbl_len(arr) + 2, sizeof(char *));
	while (arr[i])
	{
		if (ft_strcmp(arr[i], "<<") == 0)
		{
			arr2[j++] = ft_strjoin(arr[i], arr[i + 1]);
			i += 2;
		}
		else
			arr2[j++] = ft_strdup(arr[i++]);
	}
	ft_free_dbl(arr);
	return (arr2);
}

int	count_coll(char **arr, int i)
{
	int	j;

	j = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], ">>") == 0)
		{
			j++;
			i += 2;
		}
		j++;
		i++;
	}
	return (j);
}

char	**fix_exp(char **arr, int i)
{
	char	**arr2;
	int		j;

	j = 0;
	arr2 = ft_calloc(count_coll(arr, 0) + 2, sizeof(char *));
	if (arr2 == NULL)
		return (NULL);
	while (arr[i])
	{
		if (ft_strcmp(arr[i], ">>") == 0)
		{
			arr2[j] = ft_strjoin(arr[i], arr[i + 1]);
			j++;
			i += 2;
		}
		else
			arr2[j++] = ft_strdup(arr[i++]);
	}
	ft_free_dbl(arr);
	return (arr2);
}

char	**final_str(char *str)
{
	char	**arr;
	char	*dbl;

	dbl = ft_strdup(str);
	dbl = put_space_pipe(dbl, 0, 0);
	dbl = put_space(dbl, '>', 0, 0);
	dbl = put_space(dbl, '<', 0, 0);
	arr = fill_array(dbl, 0, 0, 0);
	if (arr == NULL)
	{
		free(dbl);
		return (NULL);
	}
	arr = fix_her(arr, 0, 0);
	arr = fix_exp(arr, 0);
	free(dbl);
	return (arr);
}
