/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambig.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:07 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/14 08:50:04 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*norm_ambig(char *outfile)
{
	char	*out;

	out = ft_strtrim(outfile, ">");
	free(outfile);
	outfile = ft_strdup(out);
	free(out);
	return (outfile);
}

char	*set_set(t_env *en)
{
	char	*set;

	set = my_getenv(en, "IFS");
	if (set == NULL)
		set = ft_strdup(" ");
	return (set);
}

char	*err(char *outfile)
{
	ft_pri_er("Minishell", outfile, ": ambiguous redirect\n");
	return (outfile);
}

char	*check_ambiguous(t_env *en, char *outfile, int i)
{
	char	*set;
	char	*out;

	if (ft_strncmp(outfile, ">>", 2) == 0)
		outfile = norm_ambig(outfile);
	if (outfile == NULL || ft_strcmp(outfile, "") == 0)
		return (err(outfile));
	set = set_set(en);
	if (ft_strcmp(set, " ") == 0)
		out = ft_strtrim(outfile, " ");
	else
		out = ft_strdup(outfile);
	while (out[i])
	{
		if (ft_strchr(set, out[i]) != 0)
		{
			ft_pri_er("Minishell", "", ": ambiguous redirect\n");
			(free(set), free(out));
			return (outfile);
		}
		i++;
	}
	(free(set), free(outfile));
	return (out);
}

void	ft_free_her(t_her *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		free(lst);
		lst = lst->next;
	}
}
