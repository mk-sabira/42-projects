/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:07:18 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 11:43:16 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*substring;

	str_len = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[str_len] != '\0')
		++str_len;
	if (start >= str_len)
		len = 0;
	else if (len > str_len - start)
		len = str_len - start;
	substring = (char *) malloc ((len + 1) * sizeof (char));
	if (substring == NULL)
		return (NULL);
	while (i < len)
	{
		substring[i] = str[start + i];
		i++;
	}
	substring[len] = '\0';
	return (substring);
}
