/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:34:22 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/02 12:48:24 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_str(const char *s, va_list	arg)
{
	int		count;
	char	*str;
	int		temp;

	count = 0;
	str = 0;
	if (!s)
		return (0);
	str = va_arg(arg, char *);
	temp = ft_putstr(str);
	if (temp == -1)
		return (-1);
	count += temp;
	s++;
	return (count);
}
