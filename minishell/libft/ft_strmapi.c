/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:04:50 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/19 12:05:12 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*qwert;
	unsigned int		i;
	size_t				len;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	qwert = ft_calloc(len + 1, 1);
	if (qwert == 0)
		return (NULL);
	while (s [i])
	{
		qwert[i] = f(i, s[i]);
		i++;
	}
	return (qwert);
}
