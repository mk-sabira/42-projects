/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:51:02 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/29 10:22:45 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char) c)
		return ((char *)s);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	int		i;

	if ((!s1) || (!s2))
		return (NULL);
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
