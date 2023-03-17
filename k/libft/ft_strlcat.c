/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:32:19 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/09 18:01:21 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	i = 0;
	if (dstsize == 0 || dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	d = ft_strlen(dst);
	s = ft_strlen(src);
	while (i < dstsize - d - 1 && src[i] != '\0')
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}
