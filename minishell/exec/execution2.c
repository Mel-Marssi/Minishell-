/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:08:44 by majmani           #+#    #+#             */
/*   Updated: 2023/03/17 16:57:45 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	utils_multiple_pipe(t_global **w, int t, int id, int i)
{
	if (count_herdoc_2((*w)->x) > 0)
	{
		free((*w)->h);
		(*w)->h = (*w)->h->next;
	}
	id = fork();
	if (id == 0 && t > 1)
	{
		disable_signal_handler(w);
		del_nod((*w)->x);
		(*w)->x = (*w)->x->next;
		second_proc(w, i++);
	}
	else
	{
		(*w)->proc[(*w)->count] = id;
		(close((*w)->f[0][1]), close((*w)->f[0][0]));
	}
}

void	multiple_pipe(t_global **w, int t)
{
	int			id[2];
	t_boucle	y;

	boucle_init(&y);
	if (pipe((*w)->f[0]) == -1)
		perror("pipe");
	id[0] = fork();
	if (id[0] == 0)
		(disable_signal_handler(w), first_proc(w));
	else
		(*w)->proc[(*w)->count++] = id[0];
	while ((int)++y.j < (t - 1) && t > 2)
	{
		if (count_herdoc_2((*w)->x) > 0)
		{
			free((*w)->h);
			(*w)->h = (*w)->h->next;
		}
		del_nod((*w)->x);
		(*w)->x = (*w)->x->next;
		x_proc(w, y.i++);
	}
	if (t > 1)
		utils_multiple_pipe(w, t, id[1], y.i);
}
