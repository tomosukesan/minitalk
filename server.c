/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 07:03:55 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/07 09:07:51 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_sig_data;

static void	restore_data(int signum)
{
	int	binary;

	if (signum == SIGUSR1)
		binary = 1;
	else
		binary = 0;
	if (g_sig_data.pos != 0)
		binary = binary << g_sig_data.pos;
	g_sig_data.conv = g_sig_data.conv | binary;
	if (g_sig_data.pos == 7)
	{
		ft_putchar_fd(g_sig_data.conv, 1);
		g_sig_data.conv = 0;
		g_sig_data.pos = 0;
	}
	g_sig_data.pos++;
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = restore_data;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	if (sigaction(SIGUSR1, &act, NULL) == -1 || \
		sigaction(SIGUSR2, &act, NULL) == -1)
		exit (1);
	while (1)
		pause();
	return (0);
}
