/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:37:18 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/17 19:20:41 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_tail(char *head, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*head;
	char	*tail;
	char	*result;
	size_t	result_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	head = (char *)s1;
	while (ft_strchr(set, (int)(*head)) != NULL && *head != '\0')
		head++;
	if (*head == '\0')
		return (ft_calloc(1, sizeof(char)));
	tail = set_tail(head, set);
	result_len = tail - head;
	result = malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, head, result_len + 1);
	return (result);
}

static char	*set_tail(char *head, char const *set)
{
	char	*tail;

	tail = head;
	while (*tail != '\0')
		tail++;
	while (ft_strrchr(set, (int)(*tail)) != NULL)
		tail--;
	return (++tail);
}
