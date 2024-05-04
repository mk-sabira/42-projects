/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:34:07 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/04 16:36:18 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
// # include <stdint.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_conv_nbr( const char *s, va_list arg);
int	ft_conv_str(const char *s, va_list	arg);
int	ft_conv_char(const char *s, va_list	arg);
int	ft_conv_unnbr(const char *s, va_list arg);
int	ft_conv_hex(const char *s, va_list arg);
int	ft_conv_ptr(const char *s, va_list arg);
int	ft_printf(const char *s, ...);

#endif