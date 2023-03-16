/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workshop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:43:12 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/16 16:49:11 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	norm_full(t_global *w)
{
	int	status;
	int	id;

	id = fork();
	if (id == 0)
		(disable_signal_handler(*w), one_command(&w));
	else
		w->proc[w->count] = id;
	waitpid(id, &status, 0);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_exit_status = WTERMSIG(status) + 128;
}

void	full(t_global *w)
{
	int		id[2];
	int		t;
	int		h;

	h = 0;
	t = ft_lstsize(w->x) - 1;
	if (count_herdoc((w->x)) == 1)
		(ft_pri_er("maximum here-document count exceeded\n", "", ""), exit(1));
	if (count_herdoc_2(w->x) > 0)
		h = open_herdoc(w->env, &w->h, w->x);
	if (t == 1 && h == 0)
	{
		if ((w->x->data).cmd[0] != NULL
			&& check_bultins(ft_tolower((w->x->data).cmd[0])) == 1)
			(builtins(&w->env, (w->x->data).cmd, w));
		else
			norm_full(w);
	}
	else if (t > 1 && id[0] != 0 && h == 0)
	{
		w->f = malloc(sizeof(int *) * (t - 1));
		ft_allocat_pipe(t - 1, w->f);
		(multiple_pipe(&w, t), ft_close(w, t), ft_free_int(w->f, t - 1));
	}
}

void	close_all(void)
{
	int	i;

	i = 3;
	while (i < 1024)
		close(i++);
}

void	norm_main(t_global	*w, char **env)
{
	w->env = NULL;
	w->env = ft_replace_env(w->env, env);
}

int	main(int argc, char **argv, char **env)
{
	t_global	w;

	set_tcg(&w.old, &w.new);
	(norm_main(&w, env), signal(SIGQUIT, SIG_IGN));
	while (argc && argv)
	{
		(tcsetattr(0, 0, &(&w)->new), signal(SIGINT, signal_handler));
		w.count = 0;
		w.h = NULL;
		w.str = readline("Minishell $> ");
		(signal(SIGINT, SIG_IGN), add_history(w.str));
		if (w.str == NULL)
			(ft_printf("exit\n"), exit(g_exit_status));
		w.x = hold_str(w.env, w.str);
		if (ft_strcmp(w.str, "") == 0)
			g_exit_status = 0;
		if (w.x == NULL)
		{
			(free(w.str), free_list(&w.x));
			continue ;
		}
		w.proc = malloc(sizeof(int) * ft_lstsize(w.x) - 1);
		(full(&w), close_all(), free(w.str));
		(ft_free_her(w.h), free_list(&w.x), free(w.proc));
	}
}
