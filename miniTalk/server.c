/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:48:18 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/02 12:52:42 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_recieve_char (int sig_type)
{
	static char	c;
	static int	bit;

	if (sig_type == SIGUSR1)
		c = c << 1;
	else if (sig_type == SIGUSR2)
		c = (c << 1) + 1;
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
		c = 0;
		bit = 0;
	}      
}

int	main(void)
{
	struct sigaction signal_ac;
	
	signal_ac.sa_handler = ft_recieve_char;
	signal_ac.sa_flags = 0;

	if (sigaction(SIGUSR1, &signal_ac, NULL) == -1 ||
		sigaction(SIGUSR2, &signal_ac, NULL) == -1)
	{
		ft_printf ("\033[1;31mError registering signal handler");
		return (1);
	}

	pid_t pid = getpid();
	ft_printf("\033[94mServer PID\033[0m \033[96m->\033[0m %d\n", pid);
	if (!pid)
	{
		ft_printf ("\033[1;31mError in printing PID!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
