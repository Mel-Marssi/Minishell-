/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:14:54 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/12 10:14:57 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((haystack == NULL || need == NULL) && len == 0)
		return (NULL);
	if (need[i] == '\0')
		return (((char *)haystack + i));
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == need[j] && haystack[i + j] != '\0')
			j++;
		if (need[j] == '\0' && i + j <= len)
			return (((char *)haystack + i));
	i++;
	}
	return (0);
}
