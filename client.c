/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:35:12 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/07 10:32:20 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(char c, pid_t pid)
{
	size_t	count;
	int		error_check;

	count = 0;
	while (count < 8)
	{
		usleep(350);
		if (c % 2 == 1)
			error_check = kill(pid, SIGUSR1);
		else
			error_check = kill(pid, SIGUSR2);
		if (error_check == -1)
			exit(1);
		count++;
		c = c >> 1;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		exit(1);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		exit(1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_bit(argv[2][i], pid);
		i++;
	}
	return (0);
}
