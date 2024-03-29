/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:52:24 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/14 14:52:21 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_tolower(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (NULL);
	while (c[i])
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
			c[i] = c[i] + 32;
		i++;
	}
	return (c);
}
