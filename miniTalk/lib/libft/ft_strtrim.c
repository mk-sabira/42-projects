/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:33:45 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 11:43:11 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_trim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_trim(s1[end - 1], set))
		end--;
	trimmed = (char *) malloc(sizeof(*s1) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed[i++] = s1[start++];
	}
	trimmed[i] = '\0';
	return (trimmed);
}
