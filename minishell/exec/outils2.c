/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:22:59 by majmani           #+#    #+#             */
/*   Updated: 2023/03/12 11:13:14 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**cast_env(t_env *env)
{
	char	**str;
	int		i;

	str = ft_calloc(ft_lstsize1(env) + 1, sizeof(char *));
	i = 0;
	while (env)
	{
		str[i] = env->content;
		env = env->next;
		i++;
	}
	return (str);
}

void	ft_allocat_pipe(int i, int **f)
{
	int	j;

	j = 0;
	while (i > j)
	{
		f[j] = malloc(sizeof(int) * 2);
		j++;
	}
}

void	ft_close(t_global *w, int a)
{
	int	i;
	int	status;

	i = 0;
	close(w->f[a - 2][1]);
	close(w->f[a - 2][0]);
	while (i <= w->count)
	{
		waitpid(w->proc[i], &status, 0);
		i++;
	}
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_exit_status = WTERMSIG(status) + 128;
}
