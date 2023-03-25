/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:11:54 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/13 11:11:58 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pn;

	if (size > 0 && count >= (SIZE_MAX / size))
		return (NULL);
	pn = malloc(count * size);
	if (pn == 0)
		return (0);
	ft_bzero(pn, count * size);
	return (pn);
}
