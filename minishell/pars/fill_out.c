/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:11:20 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/18 14:00:23 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**fill_outfil(t_env *en, char **arr, int i, int j)
{
	char	**outfile;

	outfile = ft_calloc(count_outfil(arr, i, j) + 2, sizeof(char *));
	while (arr[i])
	{
		if (arr[i] && (ft_strcmp(arr[i], "|") == 0
				|| ft_strchr(arr[i], '|') != 0))
			break ;
		if (arr[i] && ft_strcmp(arr[i], ">") == 0)
			outfile[j++] = ft_strtrim(arr[++i], ">");
		if (arr[i] && check_herdoc(arr[i]) == '>'
			&& check_the_first(arr[i], 0) == 0)
			outfile[j++] = ft_strdup(arr[i++]);
		else
			i++;
	}
	outfile = leave_trash(outfile, 0);
	if (ft_dbl_strchr(outfile) == 0)
		get_v_variable(en, outfile, -1);
	else
		s_trim(outfile, 0);
	return (outfile);
}

int	count_plus(char *arr, char c, int i, int j)
{
	int	a;

	a = 0;
	while (arr[i])
	{
		if (arr[i] == '\'' || arr[i] == '\"')
			norm_pipe(arr[i], &a);
		if (a == 0 && arr[i + 1] == c && arr[i] != c)
			norm_plus(&i, &j);
		if (a == 0 && arr[i + 1] == c && arr[i + 2] == '<')
			norm_plus(&i, &j);
		if (a == 0 && arr[i + 1] == c && arr[i + 2] == '>')
			norm_plus(&i, &j);
		if (a == 0 && arr[i] == c && arr[i + 1] != c)
			norm_plus(&i, &j);
		else
			norm_cnt_cmd(&i, &j);
	}
	return (j);
}

void	norm_pipe(char arr, int *a)
{
	if (arr == '\'' && (*a) == 0)
		(*a) = 1;
	else if (arr == '\"' && (*a) == 0)
		(*a) = 2;
	else if ((arr == '\'' && (*a) == 1) || (arr == '\"' && (*a) == 2))
		(*a) = 0;
}

void	norm_arr(char *arr2, char *arr, int *i, int *j)
{
	arr2[(*j)++] = arr[(*i)++];
	arr2[(*j)++] = ' ';
}

t_var	fill_x(char **arr, int j, int *i)
{
	t_var	x;

	x.left = ft_lost_var_l(arr[j], *i);
	x.right = ft_lost_var_r(arr[j], *i);
	x.var = ft_get_var(arr[j], i, 0);
	return (x);
}
