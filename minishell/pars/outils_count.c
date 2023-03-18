/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:28:39 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/14 14:44:41 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_boucle	norm_lenght0(char *cmd, t_boucle x)
{
	while (cmd[x.i] && cmd[x.i] != ' ' && cmd[x.i] != '\t'
		&& cmd[x.i] != '\"' && cmd[x.i] != '\'')
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

int	ft_lenght(char *cmd)
{
	t_boucle	x;

	boucle_init(&x);
	while (cmd[x.i])
	{
		if (cmd[x.i] && (cmd[x.i] == ' ' || cmd[x.i] == '\t'))
			break ;
		if (cmd[x.i] != ' ' && cmd[x.i] != '\t'
			&& cmd[x.i] != '\"' && cmd[x.i] != '\'')
			x = norm_lenght0(cmd, x);
		else if (cmd[x.i] == '\"')
			x = norm_lenght1(cmd, x);
		else if (cmd[x.i] == '\'')
			x = norm_lenght2(cmd, x);
	}
	return (x.j);
}

char	**cmd_trim(char **arr, int i)
{
	char	**arr2;
	char	*set;

	arr2 = ft_calloc(ft_dbl_len(arr) + 2, sizeof(char *));
	if (arr2 == NULL)
		return (NULL);
	while (arr[i])
	{
		if (arr[i][0] == '\'')
			set = ft_strdup("\'");
		else
			set = ft_strdup("\"");
		arr2[i] = ft_strtrim(arr[i], set);
		i++;
		free(set);
	}
	ft_free_dbl(arr);
	return (arr2);
}
