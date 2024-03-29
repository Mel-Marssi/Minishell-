/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:20:22 by mel-mars          #+#    #+#             */
/*   Updated: 2023/03/25 15:07:20 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_exit_status = 1;
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	disable_signal_handler(t_global **w)
{
	struct termios	l;

	l = (*w)->old;
	l.c_lflag |= ECHOCTL;
	tcsetattr(0, TCSANOW, &l);
}

void	set_tcg(struct termios *old, struct termios *new)
{
	tcgetattr(STDIN_FILENO, old);
	tcgetattr(STDIN_FILENO, new);
	(*new).c_lflag &= ~ECHOCTL;
}

void	ft_free_int(int **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	add_h(char *str)
{
	if (str != NULL && ft_strcmp(str, "") != 0)
		add_history(str);
}
