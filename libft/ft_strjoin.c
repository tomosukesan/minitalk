/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:37:34 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/17 14:49:36 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	if (s1[0] == '\0')
		ft_strlcpy(result, s2, s2_len + 1);
	else
	{
		ft_strlcpy(result, s1, s1_len + 1);
		ft_strlcat(result, s2, s1_len + s2_len + 1);
	}
	return (result);
}
