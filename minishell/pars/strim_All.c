/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strim_All.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:14:29 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/11 10:03:29 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_the_first(char *arr, int i)
{
	while (arr[i])
	{
		if (arr[i] == '<' || arr[i] == '>')
			return (0);
		if (arr[i] == '\'')
			return (1);
		if (arr[i] == '\"')
			return (2);
		i++;
	}
	return (0);
}

int	count_s_quote(char *arr)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (i >= 0)
	{
		if (arr[i] == '\'')
			count++;
		i--;
	}
	return (count);
}

int	check_the_first0(char *arr, int i)
{
	while (arr[i])
	{
		if (arr[i] == '\'')
			return (1);
		if (arr[i] == '\"')
			return (2);
		i++;
	}
	return (0);
}

int	check_quotes(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		while (arr[i] && arr[i] == '\'')
		{
			i++;
			if (arr[i] == '\'')
				return (1);
		}
		while (arr[i] && arr[i] == '\"')
		{
			i++;
			if (arr[i] == '\"')
				return (2);
		}
		i++;
	}
	return (0);
}

char	**s_trim(char **arr, int i)
{
	char	**str;

	while (arr[i])
	{
		str = split_var_exp(arr[i], 0, 0);
		str = cmd_trim(str, 0);
		free(arr[i]);
		arr[i] = dbl_strjoin(str);
		ft_free_dbl(str);
		i++;
	}
	return (arr);
}
