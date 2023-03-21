/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_h_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:16:00 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/19 17:19:21 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_dolr(char *arr, int i)
{
	while (arr[i] && arr[i] != '$')
		i++;
	if (arr[i] == '$' && ft_strchr(" +*-\'\"|:$#;<>\t\r,.=/", arr[i + 1]))
		return (find_dolr(arr, i + 1));
	if (arr[i] != '\0')
		i++;
	return (i);
}

int	find_dol_l(char *arr, int i)
{
	while (arr[i] && arr[i] != '$')
		i++;
	if (arr[i] == '$' && ft_strchr(" +*-\'\"|:$#;<>\t\r,.=/", arr[i + 1]))
		return (find_dol_l(arr, i + 1));
	return (i);
}

int	find_dol_v(char *arr, int i)
{
	while (arr[i] && arr[i] != '$')
		i++;
	if (arr[i] == '$' && ft_strchr(" +*-\'\"|:$#;<>\t\r,.=/", arr[i + 1]))
		return (find_dol_v(arr, i + 1));
	if (arr[i] != '\0')
		i++;
	return (i);
}
