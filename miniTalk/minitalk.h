/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:21:41 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/02 12:48:24 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h> 
#include <stdio.h> 
#include "./lib/ft_printf/ft_printf.h" 
#include "./lib/libft/libft.h" 

void ft_ascii_to_binary(char c, int binary[8]);
void ft_send_message(int server_pid, char c);
void ft_recieve_char(int sig_type);
#endif