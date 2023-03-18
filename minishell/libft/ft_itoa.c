/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:18:23 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/18 13:18:34 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		while (nbr > 0)
		{
			i++;
			nbr /= 10;
		}
		return (i + 1);
	}
	else if (nbr > 0)
	{
		while (nbr > 0)
		{
			i++;
			nbr /= 10;
		}
		return (i);
	}
	else
		return (1);
}

static char	*scanf_itoa(char *itoa, int len, long n)
{
	if (n > 0)
	{
		while (len-- > 0)
		{
				itoa[len] = n % 10 + '0';
			n /= 10;
		}
	}
	else if (n < 0)
	{
		n *= -1;
		while (len-- > 0)
		{
				itoa[len] = n % 10 + '0';
			n /= 10;
		}
		itoa[0] = '-';
	}
	else
		itoa[0] = '0';
	return (itoa);
}

char	*ft_itoa(int n)
{
	char		*itoa;
	int			len;
	long		nbr;

	nbr = n;
	len = count_int(nbr);
	itoa = ft_calloc(len + 1, 1);
	if (itoa == 0)
		return (NULL);
	itoa = scanf_itoa(itoa, len, nbr);
	return (itoa);
}
