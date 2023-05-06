/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:12:24 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/20 09:08:02 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str);

int	ft_atoi(const char *str)
{
	size_t		i;
	int			flag;
	long long	result;

	i = ft_isspace(str);
	flag = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		flag = ',' - str[i];
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
		{
			if (flag == -1)
				return ((int)(LONG_MIN));
			return ((int)(LONG_MAX));
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * flag));
}

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}
