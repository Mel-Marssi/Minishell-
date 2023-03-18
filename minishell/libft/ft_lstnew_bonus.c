/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:08:37 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/14 17:00:43 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_env	*ft_lstnew(char *content, int c, int old)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (new_node == NULL)
		return (0);
	new_node->content = content;
	new_node->old = old;
	new_node->next = NULL;
	if (c == 0)
		new_node->option = 0;
	else
		new_node->option = 1;
	return (new_node);
}
