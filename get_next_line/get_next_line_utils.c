/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:51:02 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/28 11:01:15 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*end;

	end = 0;
	while (*s)
	{
		if (*s == (char) c)
			end = s;
		s++;
	}
	if (*s == (char) c)
		return ((char *)s);
	else
		return ((char *)end);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	int		i;

	if ((!s1) || (!s2))
		return (0);
	if (*s1 == '\0')
		len = ft_strlen(s2) + 1;
	else
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	i = 0;
	while (*s1)
		ptr[i++] = *(s1)++;
	while (*s2)
		ptr[i++] = *(s2)++;
	ptr[i] = '\0';
	return (ptr);
}
