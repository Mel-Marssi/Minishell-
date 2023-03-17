/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:15:17 by mel-mars          #+#    #+#             */
/*   Updated: 2023/02/13 13:13:15 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_check_line(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*strjoin;

	if (s1 == NULL)
		s1 = ft_calloc(1, 1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	strjoin = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (strjoin == 0)
		return (0);
	ft_strlcat(strjoin, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcat(strjoin, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (strjoin);
}
