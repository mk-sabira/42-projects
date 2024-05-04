/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:55:31 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/04 14:04:21 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_recieve_char(int sig_type, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;

	(void)context;
	if (sig_type == SIGUSR1)
		c = c << 1;
	else if (sig_type == SIGUSR2)
		c = (c << 1) + 1;
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	signal_ac;
	pid_t				pid;

	signal_ac.sa_flags = SA_SIGINFO;
	signal_ac.sa_sigaction = ft_recieve_char;
	sigemptyset(&signal_ac.sa_mask);
	if (sigaction(SIGUSR1, &signal_ac, NULL) == -1 || \
		sigaction(SIGUSR2, &signal_ac, NULL) == -1)
	{
		ft_printf("\033[1;31mError registering signal handler");
		return (1);
	}
	pid = getpid();
	ft_printf("\033[94mServer bonus PID\033[0m \033[96m->\033[0m %d\n", pid);
	if (!pid)
	{
		ft_printf("\033[1;31mError in printing PID!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
