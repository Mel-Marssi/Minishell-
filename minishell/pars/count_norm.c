/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:45:51 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/14 09:04:14 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	norm_check(char *str, int *i, char c)
{
	if (str[(*i)] == c)
	{
		(*i)++;
		while (str[(*i)] && str[(*i)] != c)
			(*i)++;
		if (str[(*i)] != c)
		{
			return (-1);
		}
	}
	return (0);
}

int	norm_check2(void)
{
	g_exit_status = 258;
	ft_putstr_fd("Minishell : Syntax error!\n", 2);
	return (-2);
}

int	check_str(char *str, int i, int type_err)
{
	if (str[0] == '|')
		return (norm_check2());
	while (str[i])
	{
		if (str[i] == '\'')
			return (norm_check(str, &i, '\''));
		else if (str[i] == '\"')
			return (norm_check(str, &i, '\"'));
		else if (check_syn(str, i) == -2)
			return (norm_check2());
		else
			i++;
	}
	return (type_err);
}

static int	skip_spaces(char *cmd, int i)
{
	if (i > (int )ft_strlen(cmd))
		return ((int )ft_strlen(cmd));
	while (cmd[i] && cmd[i] == ' ')
		i++;
	return (i);
}

char	**split_var_exp(char *cmd, int i, int j)
{
	char	**arr;
	int		x;

	x = ft_count_strings(cmd, -1, 0);
	if (x == -1 || x == 0)
		return (NULL);
	arr = ft_calloc(x + 2, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (j <= x)
	{
		i = skip_spaces(cmd, i);
		if (cmd[i] != ' ')
		{
			arr[j] = ft_substr(cmd, i, ft_lenght0(&cmd[i]));
			if (arr[j] == NULL)
			{
				ft_free_dbl(arr);
				return (NULL);
			}
			i = i + ft_lenght0(&cmd[i]);
			j++;
		}
	}
	return (arr);
}
