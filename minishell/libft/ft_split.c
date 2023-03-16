/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:04:57 by mel-mars          #+#    #+#             */
/*   Updated: 2023/02/07 09:10:50 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		i;
	int		count_w;

	i = 0;
	count_w = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			count_w++;
		i++;
	}
	return (count_w + 1);
}

static char	*str_w_c(char const *s, char c)
{
	char	*f;
	char	*src;

	f = ft_calloc(2, 1);
	if (f == 0)
		return (0);
	f[0] = c;
	if (s == NULL)
		return (NULL);
	src = ft_strtrim(s, f);
	if (!src)
		return (NULL);
	free(f);
	return (src);
}

static size_t	str_c(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	split_2(char **split, char *s01, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s01[i])
	{
		if (s01[i] == c)
			i++;
		if (s01[i] != c)
		{
			split[j] = ft_substr(s01, i, str_c(&s01[i], c));
			if (split[j] == NULL)
			{
				while (j > 0)
					free(split[j--]);
				return (free(split));
			}
			i = i + str_c(&s01[i], c);
			j++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*s01;

	s01 = str_w_c(s, c);
	if (s01 == NULL)
		return (NULL);
	split = ft_calloc(count_word(s01, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	split_2(split, s01, c);
	free(s01);
	return (split);
}
