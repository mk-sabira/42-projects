/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:20:02 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/02 12:48:24 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h> 
#include <stdio.h> 
#include "./lib/ft_printf/ft_printf.h" 
#include "./lib/libft/libft.h" 

void ft_ascii_to_binary(char c, int binary[8]);
void ft_send_message(int server_pid, char c);
void ft_recieve_char (int sig_type, siginfo_t *info, void *context);
#endif