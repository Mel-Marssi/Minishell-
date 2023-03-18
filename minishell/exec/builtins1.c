/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:49:59 by majmani           #+#    #+#             */
/*   Updated: 2023/03/14 17:00:03 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_replace_env(t_env *e, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_lstadd_back(&e, ft_lstnew(env[i], 0, 0));
		i++;
	}
	return (e);
}

int	ft_check_double(t_env *env, char *l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (l[i] && l[i] != '=')
		i++;
	while (env)
	{
		if (strncmp(env->content, l, i) == 0)
			return (i);
		j++;
		env = env->next;
	}
	return (0);
}

int	check_alpha_num(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9') || c == '_')
		return (1);
	return (0);
}

int	ft_check_equal(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr_int(str, '=') == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '=' && (check_alpha_num(str[i - 1]) == 1
				|| check_alpha_num(str[i - 1]) == 1))
			return (i);
		i++;
	}
	return (0);
}

int	ft_check_variable_env(char *str, char *l)
{
	int	i;

	i = 0;
	if (l == NULL)
		return (0);
	while (str[i] && str[i] != '=')
		i++;
	if (strncmp(str, l, i) == 0)
		return (1);
	return (0);
}
