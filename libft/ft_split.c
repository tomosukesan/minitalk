/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:15:19 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/20 11:42:37 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_str(char const *s, char c);
static char		*get_word(char const *s, char c, size_t str_num);
static char		*set_tail(char **head, char c, size_t str_num);
static void		*ft_free(char **result, size_t str_num);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	str_num;

	if (s == NULL)
		return (NULL);
	i = 0;
	str_num = count_str(s, c);
	result = malloc(sizeof(char *) * (str_num + 1));
	if (result == NULL)
		return (NULL);
	while (i < str_num)
	{
		result[i] = get_word(s, c, i);
		if (result[i] == NULL)
			return ((char **)ft_free(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}

static size_t	count_str(char const *s, char c)
{
	size_t	str_num;

	str_num = 0;
	if (s[0] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		str_num++;
		s = ft_strchr(s, (int)c);
		if (s == NULL)
			break ;
		while (*(s + 1) == c)
			s++;
		if (*s != '\0')
			s++;
	}
	return (str_num);
}

static char	*get_word(char const *s, char c, size_t str_num)
{
	char	*head;
	char	*tail;
	char	*result;

	if (s[0] == '\0')
		return (NULL);
	if (c == '\0')
		return (ft_strdup(s));
	head = (char *)s;
	while (*head == c)
		head++;
	tail = set_tail(&head, c, str_num);
	result = malloc(sizeof(char) * (tail - head + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, head, tail - head + 1);
	return (result);
}

static char	*set_tail(char **head, char c, size_t str_num)
{
	size_t	str_count;
	char	*tail;

	str_count = 0;
	tail = *head;
	while (str_count <= str_num)
	{
		tail = ft_strchr((const char *)*head, (int)c);
		if (tail == NULL)
			return (ft_strchr((const char *)*head, '\0'));
		if (str_count == str_num)
			return (tail);
		while (*(tail + 1) == c)
			tail++;
		if (*tail != '\0')
		{
			tail++;
			*head = tail;
		}
		str_count++;
	}
	return (tail);
}

static void	*ft_free(char **result, size_t str_num)
{
	while (str_num > 0)
		free(result[str_num--]);
	free(result[0]);
	free(result);
	return (NULL);
}
