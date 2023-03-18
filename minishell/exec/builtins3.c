/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:57:44 by majmani           #+#    #+#             */
/*   Updated: 2023/03/14 21:16:10 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	position_plus(char *str)
{
	if (ft_strchr(str, '+') != 0)
	{
		if (str[ft_strchr_int(str, '=') - 1] != '+')
			return (1);
	}
	else if (ft_strchr(str, '+') == 0)
		return (1);
	return (0);
}

int	norm_check_value(char *str)
{
	int	e;

	e = 0;
	while (str[e] && str[e] != '=')
			e++;
	return (e);
}

int	check_value(char *str, int c)
{
	int	i;
	int	e;

	i = 0;
	if (c == 0)
		e = norm_check_value(str);
	else
		e = ft_strlen(str);
	while (str[i] && i < e)
	{
		if (c == 0)
		{
			if (ft_isalnum(str[i]) == 0 && str[i] != '_'
				&& position_plus(str) == 1)
				return (0);
		}
		else
		{
			if (ft_isdigit(str[0]) == 1 || (ft_isalnum(str[i]) == 0
					&& str[i] != '_'))
				return (0);
		}
		i++;
	}
	return (1);
}

t_env	*sort_export(t_env *env, int (*cmp)(const char *, const char *))
{
	char	*s;
	t_env	*tmp;

	tmp = env;
	while (env->next != NULL)
	{
		if (((*cmp)(env->content, env->next->content)) > 0)
		{
			s = env->content;
			env->content = env->next->content;
			env->next->content = s;
			env = tmp;
		}
		else
			env = env->next;
	}
	env = tmp;
	return (env);
}

void	ft_unset_e(t_env **env, char *l)
{
	t_env	*c;
	t_env	*p;

	c = *env;
	p = NULL;
	while (c != NULL && ft_check_variable_env(c->content, l) == 0)
	{		
		p = c;
		c = c->next;
	}
	if (c == NULL)
		return ;
	p->next = c->next;
	if (c->content != NULL && ft_strcmp(c->content, "") != 0 && c->old == 1)
		free(c->content);
	free(c);
}
