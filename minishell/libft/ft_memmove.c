/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:43:38 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/02 16:07:24 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*x;
	char		*y;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		x = (char *)dst;
		y = (char *)src;
		while (len-- > 0)
			x[len] = y[len];
	}
	else
		ft_memcpy (dst, src, len);
	return (dst);
}
