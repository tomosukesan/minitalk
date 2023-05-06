/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:35:12 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/06 23:41:25 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_bit(unsigned char uc, pid_t pid)
{
	unsigned int	count;
	int				error_check;

	count = 0;
	while (count < 8)
	{
		usleep(300);
		if (uc % 2 == 1)
			error_check = kill(pid, SIGUSR1);
		else
			error_check = kill(pid, SIGUSR2);
		if (error_check == -1)
			exit(1);
		count++;
		uc = uc >> 1;
	}
}

static void	get_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Transmission Complete!!\n", 1);
}

static void	send_pid(pid_t client_pid, pid_t server_pid)
{
	unsigned int	count;
	int				error_check;
	unsigned int	type;

	count = 0;
	type = sizeof(pid_t) * 8;
	while (count < type)
	{
		usleep(270);
		if (client_pid % 2 == 1)
			error_check = kill(server_pid, SIGUSR1);
		else
			error_check = kill(server_pid, SIGUSR2);
		if (error_check == -1)
			exit(1);
		count++;
		client_pid = client_pid >> 1;
	}
}

static void	check_trans(pid_t server_pid)
{
	struct sigaction	act;
	pid_t				client_pid;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = get_signal;
	client_pid = getpid();
	send_pid(client_pid, server_pid);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		exit(1);
	pause();
}

int	main(int argc, char *argv[])
{
	pid_t			pid;
	size_t			i;
	unsigned char	send_char;

	if (argc != 3)
		exit(1);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char = argv[2][i];
		send_bit(send_char, pid);
		i++;
	}
	send_bit('\0', pid);
	check_trans(pid);
	return (0);
}

// bonus change