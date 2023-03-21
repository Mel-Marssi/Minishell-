/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:39:03 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/09 19:15:17 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	h;

	i = 0;
	h = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
		dst[i] = src[i];
		i++;
		}
	dst[i] = '\0';
	}
	return (h);
}
