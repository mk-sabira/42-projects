/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:12 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 11:42:52 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	char	*result;
	size_t	i;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	i = 0;
	result = (char *)malloc(len_s + 1);
	if (!result)
		return (NULL);
	while (s[i] != 0)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len_s] = '\0';
	return (result);
}
