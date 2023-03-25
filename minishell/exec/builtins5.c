/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:07:17 by majmani           #+#    #+#             */
/*   Updated: 2023/03/18 15:26:48 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*copier_env(t_env *e)
{
	t_env	*i;

	i = NULL;
	while (e)
	{
		ft_lstadd_back(&i, ft_lstnew(ft_strdup(e->content), 0, 1));
		e = e->next;
	}
	return (i);
}

void	del_env(t_env *x)
{
	if (x->content != NULL)
		free(x->content);
	if (x != NULL)
		free(x);
}

void	free_env(t_env **x)
{
	t_env	*y;

	if (x == NULL || (x) == NULL)
		return ;
	while (*x)
	{
		y = (*x)->next;
		if ((*x)->content != NULL)
			free((*x)->content);
		if ((*x) != NULL)
			free((*x));
		*x = y;
	}
}

void	print_export(t_env *env, int file)
{
	int		t;
	int		i;
	t_env	*e;

	e = copier_env(env);
	e = sort_export(e, ft_strcmp);
	while (e)
	{
		t = 1;
		i = -1;
		ft_putstr_fd("declare -x ", file);
		while (e->content[++i])
		{
			ft_putchar_fd(e->content[i], file);
			if (e->content[i] == '=' && t == 1)
			{
				ft_putstr_fd("\"", file);
				t = 0;
			}
		}
		if (t == 0)
			ft_putstr_fd("\"", file);
		(ft_putstr_fd("\n", file), del_env(e));
		e = e->next;
	}
}

void	ft_export2(t_env **env, char *l)
{
	int	i;

	i = ft_check_double(*env, l);
	if (i != 0 && ft_strchr_int(l, '=') == -1)
		return ;
	if (ft_strchr(l, '+') != 0
		&& (ft_strchr_int(l, '+') < ft_strchr_int(l, '=')))
		join_export(env, l, ft_strchr_int(l, '+') + 2);
	else if (i == 0 && ft_strchr_int(l, '=') != 0)
	{
		if (ft_check_equal(l) != 0)
			ft_lstadd_back(env, ft_lstnew(ft_strdup(l), 0, 1));
		else if (ft_check_equal(l) == 0)
			ft_lstadd_back(env, ft_lstnew(ft_strdup(l), 1, 1));
	}
	else if (i != 0 && ft_strchr_int(l, '=') != 0)
	{
		ft_unset_e(env, l);
		if (ft_check_equal(l) != 0)
			ft_lstadd_back(env, ft_lstnew(ft_strdup(l), 0, 1));
		else if (ft_check_equal(l) == 0)
			ft_lstadd_back(env, ft_lstnew(ft_strdup(l), 1, 1));
	}
}
