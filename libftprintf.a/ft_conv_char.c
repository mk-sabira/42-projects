/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:51:21 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/17 15:50:13 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_char(const char *s, va_list	arg)
{
	int		count;
	int		c;

	count = 0;
	c = va_arg(arg, int);
	count = ft_putchar(c);
	if (count == -1)
		return (-1);
	s++;
	return (count);
}
