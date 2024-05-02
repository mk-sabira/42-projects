/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:25:07 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 11:41:08 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *) ptr + i);
		i++;
	}
	return (NULL);
}
