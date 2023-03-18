/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:19:36 by majmani           #+#    #+#             */
/*   Updated: 2023/03/18 13:58:53 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*norm_return1(char *pts, char *cmd)
{
	free(pts);
	return (cmd);
}

char	*norm_return2(char *pts)
{
	free(pts);
	return (NULL);
}

void	norm_int(t_global *w)
{
	w->count = 0;
	w->h = NULL;
}

void	ft_fct(t_doc *o, t_env *en)
{
	while (1)
	{
		write(1, "> ", 2);
		o->l = get_next_line(0);
		if (ft_strcmp(o->l, o->p) == 0)
			break ;
		(norm_herdoc3(o, en), free(o->l));
	}
}
