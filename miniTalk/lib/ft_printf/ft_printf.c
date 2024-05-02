/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:51:22 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/02 12:48:24 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_define(const char *s, va_list arg)
{
	int	count;
	int	temp;

	count = 0;
	if (*s == '%')
	{
		temp = ft_putchar('%');
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (*s == 'c')
		count += ft_conv_char(s, arg);
	else if (*s == 's')
		count += ft_conv_str(s, arg);
	else if (*s == 'i' || *s == 'd')
		count += ft_conv_nbr(s, arg);
	else if (*s == 'u')
		count += ft_conv_unnbr(s, arg);
	else if (*s == 'x' || *s == 'X')
		count += ft_conv_hex(s, arg);
	else if (*s == 'p')
		count += ft_conv_ptr(s, arg);
	return (count);
}

int	ft_per_sign(const char **s, va_list	arg)
{
	int		count;
	int		temp;

	count = 0;
	temp = 0;
	if (**s == '%')
	{
		(*s)++;
		temp = ft_define(*s, arg);
		if (temp == -1)
			return (-1);
		count += temp;
		(*s)++;
	}
	else
	{
		if (ft_putchar(**s) == -1)
		{
			return (-1);
		}
		count++;
		(*s)++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		temp;
	va_list	arg;

	count = 0;
	va_start(arg, s);
	while (*s)
	{
		temp = ft_per_sign(&s, arg);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	va_end(arg);
	return (count);
}
