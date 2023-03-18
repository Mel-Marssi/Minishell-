/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:42:17 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/09 11:37:28 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*x;
	unsigned char		*y;

	i = 0;
	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < len)
	{
		x[i] = y[i];
		i++;
	}
	return (dst);
}
