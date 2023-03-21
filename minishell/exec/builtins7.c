/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:51:26 by majmani           #+#    #+#             */
/*   Updated: 2023/03/14 10:02:24 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **str, int file)
{
	int	i;
	int	etat;
	int	j;

	etat = 0;
	i = 1;
	utils_echo(str, &etat, &i, &j);
	while (str[i])
	{
		ft_putstr_fd(str[i], file);
		if (str[i + 1] && ft_strcmp(str[i + 1], "") != 0)
			ft_putchar_fd(' ', file);
		i++;
	}
	if (etat == 0)
		ft_putchar_fd('\n', file);
}

int	ft_exit(char **str)
{
	if (ft_dbl_len(str) == 1)
	{
		(ft_printf("exit\n"), exit(g_exit_status));
	}
	if (ft_check_param(str[1]) == 0)
		(ft_pri_er("exit\nMinishell: exit: ", str[1],
				" numeric argument required\n"), exit(-1));
	else if (ft_dbl_len(str) > 2)
	{
		ft_putstr_fd("exit\nMinishell: exit: too many arguments\n", 2);
		return (1);
	}
	else
		exit(ft_atoi(str[1]));
	return (0);
}
