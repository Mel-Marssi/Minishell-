/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:03:45 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/12 17:10:55 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*o_trim(char *arr)
{
	char	**str;
	char	*dest;

	str = split_var_exp(arr, 0, 0);
	str = cmd_trim(str, 0);
	free(arr);
	arr = dbl_strjoin(str);
	ft_free_dbl(str);
	dest = ft_strdup(arr);
	free(arr);
	return (dest);
}

int	ft_dbl_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_free_dbl(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	del_nod(t_inf *x)
{
	if (x->data.cmd != NULL)
		ft_free_dbl(x->data.cmd);
	if (x->data.infile != NULL)
		ft_free_dbl(x->data.infile);
	if (x->data.outfile != NULL)
		ft_free_dbl(x->data.outfile);
	if (x != NULL)
		free(x);
}

void	free_list(t_inf **x)
{
	t_inf	*y;

	if (x == NULL || (*x) == NULL)
		return ;
	while (*x)
	{
		y = (*x)->next;
		del_nod(*x);
		*x = y;
	}
}
