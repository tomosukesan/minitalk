/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:11:22 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/15 21:06:13 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	devisor;
	long long	abs_val;
	char		num;

	devisor = 1;
	abs_val = (long long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		abs_val *= -1;
	}
	while (n <= -10 || n >= 10)
	{
		devisor *= 10;
		n /= 10;
	}
	while (devisor != 0)
	{
		num = (char)(abs_val / devisor);
		ft_putchar_fd(num + '0', fd);
		abs_val %= devisor;
		devisor /= 10;
	}
}
