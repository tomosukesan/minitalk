/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:04:02 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/17 19:50:08 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
