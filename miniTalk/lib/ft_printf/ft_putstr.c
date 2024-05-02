/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:09:35 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/02 12:48:24 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (ft_putstr("(null)") == -1)
		{
			return (-1);
		}
		return (6);
	}
	while (*str != '\0')
	{
		if (write(1, str, 1) == -1)
		{
			return (-1);
		}
		str++;
		i++;
	}
	return (i);
}
