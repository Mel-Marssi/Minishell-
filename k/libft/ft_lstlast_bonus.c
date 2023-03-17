/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:09:41 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/12 21:38:33 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_env	*ft_lstlast(t_env *lst)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
