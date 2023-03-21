/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:49:02 by majmani           #+#    #+#             */
/*   Updated: 2023/03/19 18:32:29 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**one_to_dbl(char *p)
{
	char	**dbl;

	dbl = ft_calloc(2, sizeof(char *));
	dbl[0] = p;
	dbl[1] = NULL;
	return (dbl);
}

void	handel_her(int sig)
{
	(void)sig;
	exit(33);
}

int	count_herdoc(t_inf *x)
{
	int	i;
	int	count;

		count = 0;
	while (x)
	{
		i = 0;
		while (x->data.infile[i] != NULL)
		{
			if (ft_strncmp(x->data.infile[i], "<<", 2) == 0)
				count++;
			i++;
		}
		x = x->next;
	}
	if (count > 16)
		return (1);
	return (0);
}

int	count_herdoc_2(t_inf *x)
{
	int	i;
	int	count;

	count = 0;
	while (x)
	{
		i = 0;
		while (x->data.infile[i] != NULL)
		{
			if (ft_strncmp(x->data.infile[i], "<<", 2) == 0)
				count++;
			i++;
		}
		x = x->next;
	}
	return (count);
}
