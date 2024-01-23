/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:44:36 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 11:41:03 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_iszero(int n)
{
	char	*zero;

	if (n == 0)
	{
		zero = (char *) malloc(2 * sizeof(char));
		if (!zero)
			return (NULL);
		zero[0] = '0';
		zero[1] = '\0';
		return (zero);
	}
	return (NULL);
}

static int	ft_len(int n)
{
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	int		sign;
	int		i;

	if (n == 0)
		return (ft_iszero(n));
	len = ft_len(n);
	result = (char *) malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	sign = ft_sign(n);
	result[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		result[i] = '0' + (char)(sign * (n % 10));
		n /= 10;
		i--;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
