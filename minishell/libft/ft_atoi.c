/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:26:00 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/12 11:26:16 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_spaces(const char *str)
{
	int	u;

	u = 0;
	while ((str[u] >= 9 && str[u] <= 13) || str[u] == 32)
		u++;
	return (u);
}

int	ft_atoi(const char *str)
{
	size_t	mem;
	int		e;

	e = ft_skip_spaces(str);
	if (str[e] == '-' || str[e] == '+')
		e++;
	mem = 0;
	while (str[e] >= '0' && str[e] <= '9')
	{
		mem = mem * 10 + (str[e] - '0');
		if (mem >= 9223372036854775807 && str[ft_skip_spaces(str)] != '-')
			return (-1);
		if (mem > 9223372036854775807 && str[ft_skip_spaces(str)] == '-')
			return (0);
		e++;
	}
	if (str[ft_skip_spaces(str)] == '-')
		mem = -1 * mem;
	return (mem);
}
