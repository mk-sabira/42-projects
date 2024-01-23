/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:25:08 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/17 16:13:06 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t nb)
{
	uintptr_t	i;

	i = 0;
	if (nb == 0)
		i = 1;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_ptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_ptr(nb / 16);
		ft_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
		{
			if (ft_putchar(nb + 48) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(nb + 97 - 10) == -1)
				return (-1);
		}
	}
	return (1);
}

int	ft_putptr(uintptr_t nb)
{
	if (ft_putstr("0x") == -1)
		return (-1);
	if (ft_ptr(nb) == -1)
		return (-1);
	return (ft_ptr_len(nb));
}

int	ft_conv_ptr(const char *s, va_list arg)
{
	int			count;
	uintptr_t	nb;
	int			temp;

	count = 2;
	nb = va_arg(arg, uintptr_t);
	temp = ft_putptr(nb);
	if (temp == -1)
		return (-1);
	count += temp;
	s++;
	return (count);
}
