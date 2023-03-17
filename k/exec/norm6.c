/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:19:36 by majmani           #+#    #+#             */
/*   Updated: 2023/03/14 16:20:13 by majmani          ###   ########.fr       */
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
