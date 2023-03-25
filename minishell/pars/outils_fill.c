/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:44:49 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/14 14:49:51 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	skip_spaces(char *cmd, int i)
{
	if (i > (int )ft_strlen(cmd))
		return ((int )ft_strlen(cmd));
	while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
		i++;
	return (i);
}

char	**fill_array(char *cmd, int i, int j, int x)
{
	char	**arr;

	x = ft_count_strings(cmd, -1, 0);
	if (x == -1 || x == 0)
		return (NULL);
	arr = ft_calloc(x + 2, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (j <= x)
	{
		i = skip_spaces(cmd, i);
		if (cmd[i] != ' ' || cmd[i] != '\t')
		{
			arr[j] = ft_substr(cmd, i, ft_lenght(&cmd[i]));
			if (arr[j] == NULL)
			{
				ft_free_dbl(arr);
				return (NULL);
			}
		i = i + ft_lenght(&cmd[i]);
		j++;
		}
	}
	return (arr);
}

char	*put_space(char *arr, char c, int i, int j)
{
	char	*arr2;
	int		a;

	a = 0;
	arr2 = ft_calloc(count_plus(arr, c, 0, 0) + 1, sizeof(char));
	if (arr2 == NULL)
		return (NULL);
	while (arr[i])
	{
		if (arr[i] == '\'' || arr[i] == '\"')
			norm_pipe(arr[i], &a);
		if (a == 0 && arr[i + 1] == c && arr[i] != c)
			norm_arr(arr2, arr, &i, &j);
		if (a == 0 && arr[i + 1] == c && arr[i + 2] == '<')
			norm_arr(arr2, arr, &i, &j);
		if (a == 0 && arr[i + 1] == c && arr[i + 2] == '>')
			norm_arr(arr2, arr, &i, &j);
		if (a == 0 && arr[i] == c && arr[i + 1] != c)
			norm_arr(arr2, arr, &i, &j);
		else
			arr2[j++] = arr[i++];
	}
	free(arr);
	return (arr2);
}

int	count_pipe(char *arr, int i, int j)
{
	int	a;

	a = 0;
	while (arr[i])
	{
		if (arr[i] == '\'' || arr[i] == '\"')
			norm_pipe(arr[i], &a);
		if (a != 1 && arr[i + 1] == '|')
			j += 2;
		else if (a != 1 && arr[i] == '|')
			j += 2;
		else
			j++;
		i++;
	}
	return (j);
}

char	*put_space_pipe(char *arr, int i, int j)
{
	char	*arr2;
	int		a;

	a = 0;
	arr2 = ft_calloc(count_pipe(arr, 0, 0) + 1, sizeof(char));
	if (arr2 == NULL)
		return (NULL);
	while (arr[i])
	{
		if (arr[i] == '\'' || arr[i] == '\"')
			norm_pipe(arr[i], &a);
		if (a == 0 && arr[i + 1] == '|' )
			norm_arr(arr2, arr, &i, &j);
		else if (a == 0 && arr[i] == '|')
			norm_arr(arr2, arr, &i, &j);
		else
			arr2[j++] = arr[i++];
	}
	free(arr);
	return (arr2);
}
