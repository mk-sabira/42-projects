/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:39:24 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 11:43:06 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
