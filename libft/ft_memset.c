/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:35:24 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/07 20:15:45 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			count;
	unsigned char	*uc_buf;

	count = 0;
	uc_buf = (unsigned char *)buf;
	while (count < n)
	{
		uc_buf[count] = (unsigned char)ch;
		count++;
	}
	return ((void *)uc_buf);
}
