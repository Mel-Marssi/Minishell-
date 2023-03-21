/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:12:35 by majmani           #+#    #+#             */
/*   Updated: 2023/03/18 14:45:26 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_her	*ft_lstnew_her(int i)
{
	t_her	*new_node;

	new_node = malloc(sizeof(t_her));
	if (new_node == NULL)
		return (0);
	new_node->i = i;
	new_node->next = NULL;
	return (new_node);
}

t_her	*ft_lstlast_her(t_her *lst)
{
	t_her	*tmp;

	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back_her(t_her **lst, t_her *new)
{
	t_her	*tmp;

	if (*lst != NULL)
	{
		tmp = ft_lstlast_her(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}

int	open_herdoc(t_env *en, t_her **h, t_inf *x)
{
	int	i;
	int	j;
	int	s;

	j = 0;
	while (x)
	{
		i = 0;
		s = 0;
		while (x->data.infile[i] != NULL)
		{
			if (ft_strncmp(x->data.infile[i], "<<", 2) == 0)
				s = ft_her_doc(en, &(x->data).infile[i][2]);
			if (s == -1)
				return (2);
			i++;
		}
		ft_lstadd_back_her(h, ft_lstnew_her(s));
		x = x->next;
	}
	return (0);
}

void	ft_allocat(int i, int **f)
{
	int	j;

	j = 0;
	while (i > j)
	{
		f[j] = malloc(sizeof(int));
		if (f[j] == NULL)
			return ;
		j++;
	}
}
