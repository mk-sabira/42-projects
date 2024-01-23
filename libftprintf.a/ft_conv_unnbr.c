/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:01:21 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/17 16:14:03 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unnum_len(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_putunnbr(unsigned int nb)
{
	int	count;

	count = unnum_len (nb);
	if (nb == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	else if (nb > 9)
	{
		if (ft_putunnbr(nb / 10) == -1)
			return (-1);
		if (ft_putunnbr(nb % 10) == -1)
			return (-1);
	}
	else
		if (ft_putchar(nb + 48) == -1)
			return (-1);
	return (count);
}

int	ft_conv_unnbr(const char *s, va_list arg)
{
	int	count;
	int	unnbr;
	int	temp;

	count = 0;
	unnbr = 0;
	unnbr = va_arg(arg, unsigned int);
	temp = ft_putunnbr(unnbr);
	if (temp == -1)
		return (-1);
	count += temp;
	s++;
	return (count);
}
