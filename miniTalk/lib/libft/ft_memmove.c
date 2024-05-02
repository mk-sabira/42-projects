/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:40:29 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 11:41:23 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	dst2 = (char *) dst;
	src2 = (char *) src;
	i = 0;
	if (dst2 == src2)
		return (dst);
	else if (dst2 > src2)
	{
		while (len-- > 0)
			dst2[len] = src2[len];
	}
	else
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}
