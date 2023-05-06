/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:00:31 by ttachi            #+#    #+#             */
/*   Updated: 2022/10/27 17:18:04 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;

	count = ft_strlen(s) + 1;
	while (count--)
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
	}
	return (NULL);
}
