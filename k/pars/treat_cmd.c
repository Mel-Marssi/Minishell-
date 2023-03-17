/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 08:50:32 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/12 08:50:38 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_outfil(char **arr, int i, int j)
{
	while (arr[i])
	{
		if (arr[i] && (ft_strcmp(arr[i], "|") == 0
				|| ft_strchr(arr[i], '|') != 0))
		{
			i++;
			j++;
		}
		if (arr[i] && ft_strcmp(arr[i], ">") == 0)
		{
			i++;
			j++;
		}
		if (arr[i] && check_herdoc(arr[i]) == '>'
			&& check_the_first(arr[i], 0) == 0)
		{
			i++;
			j++;
		}
		else
			i++;
	}
	return (j);
}

int	ft_dbl_strchr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_strchr(arr[i], '$') != 0
			&& (arr[i][ft_strchr_int(arr[i], '$') + 1] != '\0'
			|| arr[i][ft_strchr_int(arr[i], '$') + 1] != ' '))
			return (0);
		i++;
	}
	return (i);
}

char	**fill_cmd(t_env *en, char **arr, int i, int j)
{
	char	**cmd;

	cmd = ft_calloc(cnt_fill_cmd(arr, i, j) + 2, sizeof(char *));
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
		else if (arr[i] && arr[i][0] == '<')
			i++;
		else
			cmd[j++] = ft_strdup(arr[i++]);
	}
	cmd = leave_trash(cmd, 0);
	if (ft_dbl_strchr(cmd) == 0)
		get_v_variable(en, cmd, -1);
	else
		s_trim(cmd, 0);
	return (cmd);
}

void	change_var(t_env *en, char **infile)
{
	int	i;

	i = 0;
	while (infile[i])
	{
		if (check_herdoc(infile[i]) == 0 && ft_strchr(infile[i], '$') != 0)
			get_v_variable(en, &infile[i], -1);
		i++;
	}
}

char	**fill_infil(t_env *en, char **arr, int i, int j)
{
	char	**infile;

	infile = ft_calloc(count_infil(arr, i, j) + 2, sizeof(char *));
	while (arr[i])
	{
		if (arr[i] && ft_strcmp(arr[i], "|") == 0)
			break ;
		if (arr[i] && ft_strcmp(arr[i], "<") == 0
			&& check_the_first(arr[i], 0) == 0)
			infile[j++] = ft_strdup(arr[++i]);
		if (arr[i] && check_herdoc(arr[i]) == '<'
			&& check_the_first(arr[i], 0) == 0)
			infile[j++] = ft_strdup(arr[i++]);
		else
			i++;
	}
	infile = leave_trash(infile, 0);
	change_var(en, infile);
	return (infile);
}
