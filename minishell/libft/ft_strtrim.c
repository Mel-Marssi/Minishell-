/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:56:40 by mel-mars          #+#    #+#             */
/*   Updated: 2023/02/16 09:34:53 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_trim_start_ps(char const *s1, char const *set)
{
	int	j;
	int	i;
	int	count_set;

	count_set = 0;
	j = 0;
	i = 0;
	while (s1[j] != '\0')
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (s1[j] == set[i])
			{
				count_set++;
				break ;
			}
			i++;
		}
		if (set[i] == '\0')
			break ;
		j++;
	}
	return (count_set);
}

static int	check_trim_end_ps(char const *s1, char const *set)
{
	int	j;
	int	i;
	int	count_set;

	count_set = 0;
	j = ft_strlen(s1) - 1;
	i = 0;
	while (j >= 0)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (s1[j] == set[i])
			{
				count_set++;
				break ;
			}
			i++;
		}
		if (set[i] == '\0')
			break ;
		j--;
	}
	return (count_set);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		x;
	int		y;
	int		lent;
	int		i;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	x = check_trim_start_ps(s1, set);
	y = check_trim_end_ps(s1, set);
	lent = ft_strlen(s1) - (x + y);
	if (lent < 0)
		return (ft_calloc(1, 1));
	i = 0;
	trimmed = ft_calloc(lent + 1, 1);
	if (trimmed == 0)
		return (NULL);
	while (i < lent)
	{
		trimmed[i] = s1[x + i];
		i++;
	}
	return (trimmed);
}
