/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:43:14 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/02 12:48:24 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_conto_nb(unsigned int nb, int upper)
{
	if (nb <= 9)
	{
		if (ft_putchar(nb + 48) == -1)
			return (-1);
	}
	else if (upper == 0)
	{
		if (ft_putchar(nb + 97 - 10) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(nb + 65 - 10) == -1)
			return (-1);
	}
	return (1);
}

int	ft_hex(unsigned int nb, int upper)
{
	if (nb >= 16)
	{
		if (ft_hex(nb / 16, upper) == -1)
			return (-1);
		if (ft_hex(nb % 16, upper) == -1)
			return (-1);
	}
	else
	{
		if (ft_conto_nb(nb, upper) == -1)
			return (-1);
	}
	return (1);
}

int	ft_puthex( unsigned int nb, int upper)
{
	int	temp;

	if (nb == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (ft_hex(nb, upper) == -1)
			return (-1);
	}
	temp = hex_len(nb);
	if (temp == -1)
		return (-1);
	return (hex_len(nb));
}

int	ft_conv_hex(const char *s, va_list arg)
{
	int	count;
	int	nb;
	int	temp;

	count = 0;
	if (*s == 'X')
	{
		nb = va_arg(arg, unsigned int);
		temp = ft_puthex(nb, 1);
		if (temp == -1)
			return (-1);
		count += temp;
		s++;
	}
	else
	{
		nb = va_arg(arg, unsigned int);
		temp = ft_puthex(nb, 0);
		if (temp == -1)
			return (-1);
		count += temp;
		s++;
	}
	return (count);
}
