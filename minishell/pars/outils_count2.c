/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_count2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:36:33 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/11 09:20:31 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	norm_count(char *cmd, int i, char c)
{
	while (cmd[i] && cmd[i + 1] == c)
		i++;
	return (i);
}

static int	norm_count1(char *cmd, int i, char c)
{
	i++;
	while (cmd[i] && cmd[i] != c)
		i++;
	return (i);
}

int	ft_count_strings(char *cmd, int i, int count)
{
	while (cmd[++i])
	{
		if (cmd[i] == ' ' && cmd[i] != '\"' && cmd[i] != '\'')
		{
			i = norm_count(cmd, i, ' ');
			count++;
		}
		else if (cmd[i] == '\"')
		{
			i = norm_count1(cmd, i, '\"');
			if (cmd[i] == '\"')
				count++;
			else
				return (-1);
		}
		else if (cmd[i] == '\'')
		{
			i = norm_count1(cmd, i, '\'');
			if (cmd[i] == '\'')
				count++;
			else
				return (-1);
		}
	}
	return (count + 1);
}

int	check_herdoc(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		while (arr[i] && arr[i] == ' ')
			i++;
		if (arr[i] == '<' && arr[i + 1] == '<')
			return ('<');
		else if (arr[i] == '>' && arr[i + 1] == '>')
			return ('>');
		else if (arr[i] == '|' && arr[i + 1] == '|')
			return (-1);
		i++;
	}
	return (0);
}

void	norm_plus(int *i, int *j)
{
	(*j) += 2;
	(*i)++;
}
