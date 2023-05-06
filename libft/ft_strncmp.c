/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:36:25 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/17 17:34:24 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;
	size_t	eos_flag;

	count = 0;
	eos_flag = 0;
	while (count < n && eos_flag == 0)
	{
		if (s1[count] == '\0' || s2[count] == '\0')
			eos_flag++;
		if (s1[count] != s2[count])
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		count++;
	}
	return (0);
}
