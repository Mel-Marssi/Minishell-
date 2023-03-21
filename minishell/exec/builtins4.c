/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:08:01 by majmani           #+#    #+#             */
/*   Updated: 2023/03/19 17:22:54 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*del_plus(char *str)
{
	int		i;
	char	*s;
	int		j;

	j = 0;
	s = malloc(sizeof(char) * ft_strlen(str));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != '+')
			s[j++] = str[i];
		i++;
	}
	s[j] = '\0';
	return (s);
}

int	my_strcmp(const char *s1, const char *s2)
{
	int		i;
	char	*s;

	s = malloc(ft_strchr_int(s2, '+') + 2);
	if (s == NULL)
		return (0);
	i = 0;
	while (s2[i] != '+')
	{
		s[i] = s2[i];
		i++;
	}
	s[i] = '\0';
	i = 0;
	while ((s1[i] || s[i]) && s1[i] != '=' )
	{
		if (s1[i] != s[i])
		{
			free(s);
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s + i));
		}
		i++;
	}
	free(s);
	return (0);
}

char	*my_getenv(t_env *env, char *str)
{
	char		*s;
	t_boucle	o;
	t_env		*en;

	boucle_init(&o);
	en = env;
	s = NULL;
	if (ft_strcmp(str, "?") == 0)
		return (ft_itoa(g_exit_status));
	if (ft_strcmp(str, "$") == 0)
		return (ft_strdup("$"));
	if (ft_strlen(str) == 0)
		return (NULL);
	while (str && en != NULL && ft_strncmp(en->content, str,
			ft_strchr_int(en->content, '=')) != 0)
		en = en->next;
	if (str && en != NULL && ft_strncmp(en->content, str, ft_strlen(str)) == 0)
	{
		o.i = ft_check_equal(en->content);
		s = ft_neww_strdup(en->content, o.i);
	}
	return (s);
}

int	ft_check_param(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	join_export(t_env **env, char *l, int k)
{
	t_env	*tmp;
	t_help	i;

	tmp = (*env);
	i.j = 0;
	i.s = malloc(sizeof(char) * ft_strlen(l) - k + 1);
	if (i.s == NULL)
		return ;
	while (l[k])
			i.s[i.j++] = l[k++];
	i.s[i.j] = '\0';
	while (tmp)
	{
		if (my_strcmp(tmp->content, l) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		(ft_lstadd_back(env, ft_lstnew(del_plus(l), 0, 1)), free(i.s));
		return ;
	}
	i.copier = ft_strdup(tmp->content);
	norm_join_export(env, i.copier, i.s);
}
