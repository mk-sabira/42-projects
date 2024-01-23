/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:52:27 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 12:33:16 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*ptr2;

	ptr2 = ptr;
	while (len > 0)
	{
		*ptr2 = c;
		ptr2++;
		len--;
	}
	return (ptr);
}
