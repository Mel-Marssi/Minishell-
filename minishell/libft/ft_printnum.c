/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:57:14 by mel-mars          #+#    #+#             */
/*   Updated: 2022/12/27 10:28:16 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	count_num(long nbr, int base)
{
	long	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = count_num(nb, 10);
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-1 * nb);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_hexadecimal(unsigned int nb, char c)
{
	char		*base_hxd;
	int			i;

	i = count_num(nb, 16);
	if (c == 'X')
		base_hxd = "0123456789ABCDEF";
	else
		base_hxd = "0123456789abcdef";
	if (nb > 15)
	{
		ft_hexadecimal(nb / 16, c);
		ft_putchar(base_hxd[nb % 16]);
	}
	else
		ft_putchar(base_hxd[nb % 16]);
	return (i);
}

int	ft_hex_adress(size_t nb, char c)
{
	char			*base_hxd;
	size_t			i;

	i = count_num(nb, 16);
	base_hxd = "0123456789abcdef";
	if (nb > 15)
	{
		ft_hex_adress(nb / 16, c);
		ft_putchar(base_hxd[nb % 16]);
	}
	else
		ft_putchar(base_hxd[nb % 16]);
	return (i);
}

int	ft_ip(size_t ip)
{
	char		*base_hxd;
	size_t		i;

	i = 0;
	base_hxd = "0123456789abcdef";
	i += ft_putstr("0x");
	if (ip > 15)
	{
		i += ft_hex_adress(ip / 16, 'p');
		i += ft_putchar(base_hxd[ip % 16]);
	}
	else
		i += ft_putchar(base_hxd[ip % 16]);
	return (i);
}
