/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:11:04 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/14 22:08:18 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s;

	uc_s = (const unsigned char *)s;
	while (n--)
	{
		if (uc_s[0] == (unsigned char)c)
			return ((void *)uc_s);
		uc_s++;
	}
	return (NULL);
}
