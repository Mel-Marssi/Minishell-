/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:51:08 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/25 15:06:24 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

void	norm_cnt_cmd(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

int	cnt_fill_cmd(char **arr, int i, int j)
{
	while (arr[i])
	{
		if (arr[i] && ft_strcmp(arr[i], "|") == 0)
			break ;
		else if (arr[i] && (ft_strcmp(arr[i], ">") == 0
				|| ft_strcmp(arr[i], "<") == 0))
			i += 2;
		else if (ft_strncmp(arr[i], ">>", 2) == 0
			|| ft_strncmp(arr[i], "<<", 2) == 0)
			i++;
		if (arr[i] && arr[i][0] == '<')
			i++;
		else
			norm_cnt_cmd(&i, &j);
	}
	return (j);
}

int	count_infil(char **arr, int i, int j)
{
	while (arr[i])
	{
		if (arr[i] && (ft_strcmp(arr[i], "|") == 0
				|| ft_strchr(arr[i], '|') != 0))
			break ;
		if (arr[i] && ft_strcmp(arr[i], "<") == 0)
			norm_cnt_cmd(&i, &j);
		if (arr[i] && check_herdoc(arr[i]) == '<')
			norm_cnt_cmd(&i, &j);
		else
			i++;
	}
	return (j);
}

t_inf	*lst(t_env *en, char **arr, int i)
{
	t_inf	*pars;

	pars = ft_inf(en, arr, i);
	while (arr[i])
	{
		while (arr[i] && ft_strcmp(arr[i], "|") != 0)
			i++;
		add_back_cmd(&pars, ft_inf(en, arr, ++i));
	}
	ft_free_dbl(arr);
	return (pars);
}

int	check_all_am(t_env *en, char **outfile, int i)
{
	while (outfile[i])
	{
		outfile[i] = check_ambiguous(en, outfile[i], 0);
		if (outfile[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}
