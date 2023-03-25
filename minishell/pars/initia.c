/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initia.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:21:25 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/24 14:43:50 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_inf	*ft_inf(t_env *en, char **arr, int i)
{
	t_inf	*y;

	y = malloc(sizeof(t_inf));
	if (y == 0)
		return (0);
	y->data.infile = fill_infil(en, arr, i, 0);
	y->data.outfile = fill_outfil(en, arr, i, 0);
	y->data.cmd = fill_cmd(en, arr, i, 0);
	y->data.max = count_valid(arr, i, 0);
	y->next = NULL;
	return (y);
}

t_inf	*last_inf(t_inf *dst)
{
	while (dst != NULL && dst->next != NULL)
		dst = dst->next;
	return (dst);
}

t_inf	*hold_str(t_env *en, char *str)
{
	char	**arr;
	t_inf	*x;
	int		k;

	k = check_str(str, 0, 0);
	if (str == NULL || ft_strcmp(str, "") == 0)
		return (NULL);
	if (k == -1)
	{
		(ft_putstr_fd("Minishell: ", 2), ft_putstr_fd(" Unclosed Quotes!\n", 2));
		return (NULL);
	}
	else if (k == -2)
		return (NULL);
	arr = final_str(str);
	if (arr == NULL)
		return (NULL);
	x = lst(en, arr, 0);
	return (x);
}

char	**leave_trash(char **arr, int i)
{
	char	**arr_f;
	int		j;

	j = 0;
	arr_f = ft_calloc(ft_count_f(arr, 0) + 2, sizeof(char *));
	while (i < ft_dbl_len(arr))
	{
		if (ft_strcmp(arr[i], "") == 0)
			i++;
		else
		{
			arr_f[j] = ft_strdup(arr[i]);
			j++;
			i++;
		}
	}
	ft_free_dbl(arr);
	return (arr_f);
}

char	*o_trim0(char *arr)
{
	char	**str;
	char	*dest;

	str = split_var_exp(arr, 0, 0);
	str = cmd_trim(str, 0);
	free(arr);
	arr = dbl_strjoin(str);
	ft_free_dbl(str);
	dest = ft_strdup(arr);
	return (dest);
}
