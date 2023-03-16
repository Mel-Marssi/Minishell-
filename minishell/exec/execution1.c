/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:25:40 by majmani           #+#    #+#             */
/*   Updated: 2023/03/16 17:03:28 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	one_command(t_global **w)
{
	char	*paths;

	if (((*w)->x->data).outfile[0] != NULL
		&& check_bultins(ft_tolower((*w)->x->data.cmd[0])) != 1)
		open_out_files(w, -1, 0);
	if (((*w)->x->data).infile[0] != NULL
		&& check_bultins(ft_tolower((*w)->x->data.cmd[0])) != 1)
		open_in_files(w, -1);
	if ((*w)->x->data.cmd[0])
	{
		paths = get_path1((*w)->env, (*w)->x->data.cmd[0], 0);
		if (paths == NULL || ft_strcmp((*w)->x->data.cmd[0], "") == 0)
			(ft_pri_er("Minishell: ", (*w)->x->data.cmd[0],
					" command not found\n"),
				exit(127));
		if (execve(paths, (*w)->x->data.cmd, cast_env((*w)->env)) == -1)
			exit(1);
	}
	exit(0);
}

void	first_proc(t_global **w)
{
	char	*paths;

	paths = NULL;
	close((*w)->f[0][0]);
	if (((*w)->x->data).outfile[0] != NULL)
		open_out_files(w, -1, 0);
	else
		dup2((*w)->f[0][1], 1);
	if (((*w)->x->data).infile[0] != NULL)
		open_in_files(w, -1);
	if ((*w)->x->data.cmd[0])
	{
		if (check_bultins(ft_tolower((*w)->x->data.cmd[0])) == 1)
			(builtins(&(*w)->env, (*w)->x->data.cmd, (*w)),
				exit(g_exit_status));
		paths = get_path1((*w)->env, (*w)->x->data.cmd[0], 0);
		if (paths == NULL || ft_strcmp((*w)->x->data.cmd[0], "") == 0)
			(ft_pri_er("Minishell: ", (*w)->x->data.cmd[0],
					" command not found\n"),
				exit(127));
		if (execve(paths, (*w)->x->data.cmd, cast_env((*w)->env)) == -1)
			exit(1);
	}
	exit(0);
}

void	second_proc(t_global **w, int a)
{
	char	*paths;

	close((*w)->f[a][1]);
	if (((*w)->x->data).outfile[0] != NULL)
		open_out_files(w, -1, 0);
	if (((*w)->x->data).infile[0] != NULL)
		open_in_files(w, -1);
	else
		dup2((*w)->f[a][0], 0);
	if ((*w)->x->data.cmd[0])
	{
		paths = get_path1((*w)->env, (*w)->x->data.cmd[0], 0);
		if (paths == NULL || ft_strcmp((*w)->x->data.cmd[0], "") == 0)
			(ft_pri_er("Minishell: ", (*w)->x->data.cmd[0],
					" command not found\n"),
				exit(127));
		if (check_bultins(ft_tolower((*w)->x->data.cmd[0])) == 1)
			(builtins(&(*w)->env, (*w)->x->data.cmd, (*w)),
				exit(g_exit_status));
		if (execve(paths, (*w)->x->data.cmd, cast_env((*w)->env)) == -1)
			exit(1);
	}
	exit(0);
}

void	utils_x_proc(t_global **w)
{
	char	*paths;

	paths = get_path1((*w)->env, ((*w)->x->data).cmd[0], 0);
	if (paths == NULL || ft_strcmp((*w)->x->data.cmd[0], "") == 0)
		(ft_pri_er("Minishell: ",
				((*w)->x->data).cmd[0], " command not found\n"),
			exit(127));
	if (check_bultins(((*w)->x->data).cmd[0]) == 1)
		(builtins(&(*w)->env, ((*w)->x->data).cmd, (*w)),
			exit(0));
	if (execve(paths, ((*w)->x->data).cmd, cast_env((*w)->env)) == -1)
		exit(1);
}

void	x_proc(t_global **w, int i)
{
	int		id;

	if (pipe((*w)->f[i + 1]) == -1)
		perror("pipe");
	id = fork();
	if (id == 0)
	{
		disable_signal_handler(**w);
		(close((*w)->f[i][1]), close((*w)->f[i + 1][0]));
		if (((*w)->x->data).outfile[0] != NULL)
			open_out_files(w, -1, 0);
		else
			dup2((*w)->f[i + 1][1], 1);
		if (((*w)->x->data).infile[0] != NULL)
			open_in_files(w, -1);
		else
			dup2((*w)->f[i][0], 0);
		if (((*w)->x->data).cmd[0])
			utils_x_proc(w);
		else
			(close((*w)->f[i][0]), close((*w)->f[i][1]), exit(g_exit_status));
	}
	else
		(*w)->proc[(*w)->count++] = id;
	(close((*w)->f[i][0]), close((*w)->f[i][1]));
}
