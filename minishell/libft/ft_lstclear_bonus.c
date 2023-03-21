/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:11:01 by mel-mars          #+#    #+#             */
/*   Updated: 2022/10/27 10:11:07 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*plt;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		plt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = plt;
	}
}
