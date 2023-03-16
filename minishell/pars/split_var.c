/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:39:12 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/13 10:47:44 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_boucle	norm_lenght0(char *cmd, t_boucle x)
{
	while (cmd[x.i] && cmd[x.i] != ' ' && cmd[x.i] != '\"' && cmd[x.i] != '\'')
	{
		x.i++;
		x.j++;
	}
	return (x);
}

static t_boucle	norm_lenght1(char *cmd, t_boucle x)
{
	x.j++;
	x.i++;
	while (cmd[x.i] && cmd[x.i] != '\"')
	{
		x.j++;
		x.i++;
	}
	if (cmd[x.i] == '\"')
	{
		x.j++;
		x.i++;
	}
	return (x);
}

static t_boucle	norm_lenght2(char *cmd, t_boucle x)
{
	x.i++;
	x.j++;
	while (cmd[x.i] && cmd[x.i] != '\'')
	{
		x.j++;
		x.i++;
	}
	if (cmd[x.i] == '\'')
	{
		x.j++;
		x.i++;
	}
	return (x);
}

int	ft_lenght0(char *cmd)
{
	t_boucle	x;

	boucle_init(&x);
	if (cmd[x.i] != ' ' && cmd[x.i] != '\"' && cmd[x.i] != '\'')
		x = norm_lenght0(cmd, x);
	else if (cmd[x.i] == '\"')
		x = norm_lenght1(cmd, x);
	else if (cmd[x.i] == '\'')
		x = norm_lenght2(cmd, x);
	return (x.j);
}

int	count_valid(char **arr, int i, int count)
{
	while (arr[i])
	{
		if (arr[i] && ft_strcmp(arr[i], "<") == 0 && arr[1 + i])
		{
			if (open(arr[i + 1], O_RDONLY) != -1)
				i += 2;
			else
				return (count);
		}
		else if (arr[i] && (ft_strcmp(arr[i], ">") == 0
				|| ft_strncmp(arr[i], ">>", 2) == 0))
		{	
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}
