/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:56:51 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/15 17:56:53 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start || s == NULL)
		return (ft_calloc(1, 1));
	if (len >= SIZE_MAX || len + start > ft_strlen(s))
		sub = ft_calloc(ft_strlen(&s[start]) + 1, 1);
	else
		sub = ft_calloc(len + 1, 1);
	if (sub == 0)
		return (0);
	while (i < len && start + i < ft_strlen(s))
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
