/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:58:10 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/17 17:58:31 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*search_str(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if ((haystack == NULL && needle != NULL) && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	return (search_str(haystack, needle, len));
}

static char	*search_str(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	if (haystack_len < needle_len || len < needle_len)
		return (NULL);
	while (i < haystack_len - needle_len + 1 && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (j == needle_len && i + j <= len)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
