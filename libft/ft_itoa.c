/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:51:05 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/20 11:18:12 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*conv_to_text(int minus_flag, int digit, long long abs_val);

char	*ft_itoa(int n)
{
	int			minus_flag;
	int			digit;
	long long	abs_val;

	minus_flag = 0;
	digit = 1;
	abs_val = (long long)n;
	if (n < 0)
	{
		minus_flag++;
		abs_val *= -1;
	}
	while (n <= -10 || n >= 10)
	{
		digit++;
		n /= 10;
	}
	return (conv_to_text(minus_flag, digit, abs_val));
}

static char	*conv_to_text(int minus_flag, int digit, long long abs_val)
{
	char	*result;

	result = malloc(sizeof(char) * (digit + minus_flag + 1));
	if (result == NULL)
		return (NULL);
	if (minus_flag)
		result[0] = '-';
	result[digit + minus_flag] = '\0';
	if (abs_val < 10)
		result[minus_flag] = abs_val + '0';
	else
	{
		while (minus_flag <= digit)
		{
			result[digit + minus_flag - 1] = abs_val % 10 + '0';
			abs_val /= 10;
			digit--;
		}
	}
	return (result);
}
