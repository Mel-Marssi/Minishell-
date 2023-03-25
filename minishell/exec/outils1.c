/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:22:12 by majmani           #+#    #+#             */
/*   Updated: 2023/03/18 13:54:24 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_add(char **str, int i, char *com_total, char *com)
{
	free(com);
	if (str[i] == NULL)
	{
		free(com_total);
		ft_free_dbl(str);
		return (0);
	}
	ft_free_dbl(str);
	return (1);
}

int	ft_count_f(char **arr, int i)
{
	int	count;

	count = 0;
	while (i < ft_dbl_len(arr))
	{
		if (ft_strcmp(arr[i], "") == 0)
			i++;
		count++;
		i++;
	}
	return (count);
}

int	check_dbl_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], "") == 0)
		{
			while (arr[i] && ft_strcmp(arr[i], "") == 0)
				i++;
			if (arr[i] != NULL && ft_strcmp(arr[i], "") != 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	count_empty(char **arr, int i)
{
	while (arr[i] && ft_strcmp(arr[i], "") != 0)
		i++;
	if (arr[i] == NULL)
		return (0);
	while (arr[i] && ft_strcmp(arr[i], "") == 0)
		i++;
	if (arr[i] == NULL)
		return (1);
	return (0);
}

void	signal_c(int sig)
{
	ft_printf("\n");
	(void)sig;
}
