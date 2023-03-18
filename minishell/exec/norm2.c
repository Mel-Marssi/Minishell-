/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:07:56 by majmani           #+#    #+#             */
/*   Updated: 2023/03/12 22:53:27 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	norm_get_path(char *cmd)
{
	if (cmd[0] == '.' && ft_strlen(cmd) == 1)
		(ft_putstr_fd("Minishell: .: filename argument required\n", 2), exit(2));
	if (access(cmd, X_OK) == -1 && ((cmd[0] == '.' && cmd[1] == '/')
			|| cmd[0] == '.' || cmd[0] == '/'))
		(ft_putstr_fd("Minishell: ", 2), ft_putstr_fd(cmd, 2),
			ft_putstr_fd(" No such file or directory\n", 2), exit(127));
}

int	check_plus(char *l)
{
	int	i;

	i = 0;
	while (l[i] && l[i] != '+' && l[i + 1] != '=')
		i++;
	return (i);
}

void	del_env0(t_env **x)
{
	if ((*x)->content != NULL)
		free((*x)->content);
	if ((*x) != NULL)
		free((*x));
}

int	ft_condition(char *l)
{
	if (check_value(l, 0) == 0 || (ft_strchr(l, '-') != 0
			&& (ft_strchr_int(l, '-') < ft_check_equal(l)
				|| ft_check_equal(l) == 0)) || (ft_strchr_int(l, '+') != -1
			&& ft_strchr_int(l, '+') < ft_check_equal(l)
			&& l[ft_check_equal(l) - 1] != '+')
		|| ft_strchr(l, '\\') != 0 || (isalpha(l[0]) == 0 && l[0] != '_'))
		return (1);
	return (0);
}

void	ft_pri_er(char *str1, char *variable, char *str2)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(variable, 2);
	ft_putstr_fd(str2, 2);
}
