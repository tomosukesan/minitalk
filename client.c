/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:35:12 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/06 23:20:08 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(char c, pid_t pid)
{
	unsigned int	count;
	int				error_check;

	count = 0;
	while (count < 8)
	{
		usleep(50);
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
	pid_t			pid;
	int				i;
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
	return (0);
}
