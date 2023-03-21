/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:35:05 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/16 13:00:41 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strjoin = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (strjoin == 0)
		return (0);
	ft_strlcpy(strjoin, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcat(strjoin, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (strjoin);
}
