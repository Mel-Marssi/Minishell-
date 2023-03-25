/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:57:39 by mel-mars          #+#    #+#             */
/*   Updated: 2023/02/13 18:55:03 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		count;

	count = ft_strlen(s1);
	str = ft_calloc(count + 1, sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, count + 1);
	return (str);
}
