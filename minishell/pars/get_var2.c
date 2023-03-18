/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:27:06 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/18 14:01:21 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	norm_get0(char *arr, int i)
{
	while (arr[i] && arr[i] != '$')
	{
		while (arr[i] && arr[i] == '\'' && count_s_quote(arr) % 2 == 0
			&& check_the_first(&arr[i], 0) == 1)
		{
			i++;
			while (arr[i] && arr[i] != '\'')
				i++;
			if (arr[i] == '\'')
				break ;
		}
		i++;
	}
	if (arr[i] == '$' && ft_strchr(" +*-\'\"|:$#;<?>\t\r,.=/", arr[i + 1]))
		return (norm_get0(arr, i + 1));
	if (arr[i] != '\0')
		i++;
	return (i);
}

char	*ft_get_var(char *arr, int *i, int j)
{
	char	*str;

	if (ft_strcmp(arr, "$") == 0)
		return (ft_strdup("$"));
	(*i) = norm_get0(arr, (*i));
	if (arr[*i] == '$')
		return (ft_strdup("$"));
	if (*i < (int)ft_strlen(arr) && arr[*i] == '?')
		return (ft_strdup("?"));
	while (arr[*i] && !ft_strchr(" -*#+\'\":;|<$?>\t\r.,/=", arr[*i]))
	{
		(*i)++;
		j++;
	}
	str = ft_calloc(j + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	*i = *i - j;
	j = 0;
	while (arr[*i] && !ft_strchr("+*#- \'\"$|;:<?>\t\r.,/=", arr[*i]))
		str[j++] = arr[(*i)++];
	return (str);
}

void	add_back_cmd(t_inf	**old, t_inf *new)
{
	t_inf	*last;

	if (*old)
	{
		last = last_inf(*old);
		last->next = new;
	}
	else
		*old = new;
}

void	boucle_init(t_boucle *x)
{
	x->i = 0;
	x->j = 0;
}
