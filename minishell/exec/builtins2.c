/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:50 by majmani           #+#    #+#             */
/*   Updated: 2023/03/18 14:42:26 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(t_env **env, char **l, int h, t_env *c)
{
	t_env		*p;
	static int	t;

	norm_unset3(&p, &t, h);
	if (!l[t])
		return (norm_unset(&t));
	if (check_value(l[t], 1) == 0)
		if (norm_unset4(l, &t) == 1)
			return (1);
	if (c != NULL && ft_check_variable_env(c->content, l[t]) != 0)
		return (norm_unset2(env, &c));
	while (c != NULL && ft_check_variable_env(c->content, l[t]) == 0)
		norm_unset1(&p, &c);
	if (c != NULL)
	{
		p->next = c->next;
		if (c->content != NULL && ft_strcmp(c->content, "") != 0 && c->old == 1)
			free(c->content);
		free(c);
		if (l[++t] != NULL)
			ft_unset(env, l, t,*env);
	}
	else if (l[t] != NULL)
		ft_unset(env, l, ++t,*env);
	return (0);
}

void	ft_env(t_env *env, int c, int file)
{
	if (c == 0)
	{
		while (env)
		{
			if (env->option == 0)
				(ft_putstr_fd(env->content, file), ft_putstr_fd("\n", file));
			env = env->next;
		}
	}
}

int	ft_export(t_env **env, char **l, int file)
{
	int	j;

	j = 1;
	if (ft_dbl_len(l) == 1)
		return (norm_export(*env, file));
	while (j <= ft_dbl_len(l))
	{
		if (ft_condition(l[j]) == 1)
		{
			ft_pri_er("Minishell: export: `", l[j],
				"' : not a valid identifier\n");
			if (j + 1 >= ft_dbl_len(l))
				return (1);
			else
			{
				j++;
				continue ;
			}
		}
		ft_export2(env, l[j]);
		j++;
		if (j >= ft_dbl_len(l))
			break ;
	}
	return (0);
}

int	cd(char **str, t_env **en)
{
	int		r;
	char	*dst;

	r = 0;
	if (str[1] == NULL || ft_strcmp(str[1], "~") == 0)
	{
		dst = my_getenv(*en, "HOME");
		r = chdir(dst);
		free(dst);
		if (r != 0)
			return (norm_cd(NULL, 0));
	}
	else if (ft_strcmp(str[1], "-") == 0)
		r = utils_cd2(en);
	else
		r = chdir(str[1]);
	if (r == 0)
	{
		utils_cd(en);
		return (0);
	}
	else if (ft_strcmp(str[1], "") != 0)
		return (norm_cd(str[1], 1));
	return (0);
}

char	*ft_pwd(int c, int file)
{
	char	*d;
	char	*str;

	d = malloc(255);
	if (d == NULL)
		return (NULL);
	str = getcwd(d, 255);
	if (str == NULL)
		perror("");
	if (c == 0)
		(ft_putstr_fd(d, file), ft_putchar_fd('\n', file));
	if (str != NULL && c == 0)
		free(str);
	return (d);
}
