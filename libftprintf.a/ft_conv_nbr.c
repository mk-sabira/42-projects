/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:34:17 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/17 17:32:04 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_check(int nb)
{
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		if (ft_check(nb) == -1)
			return (-1);
	}
	else if (nb > 9)
	{
		if (ft_check(nb / 10) == -1)
			return (-1);
		if (ft_check(nb % 10) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(nb + 48) == -1)
		{
			return (-1);
		}
	}
	return (1);
}

int	ft_putnbr(int nb)
{
	int	count;

	if (nb == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	count = num_len(nb);
	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
		{
			return (-1);
		}
	}
	else
	{
		if (ft_check(nb) == -1)
			return (-1);
	}
	return (count);
}

int	ft_conv_nbr( const char *s, va_list arg)
{
	int	count;
	int	nb;
	int	temp;

	count = 0;
	nb = va_arg(arg, int);
	temp = ft_putnbr(nb);
	if (temp == -1)
		return (-1);
	count += temp;
	s++;
	return (count);
}
