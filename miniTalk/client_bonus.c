/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:20:49 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/04 16:42:00 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int signum)
{
	ft_printf("Recieved signal:%d\n", signum);
}

void	ft_error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}

pid_t	ft_check_pid(char *str)
{
	int	has_sign;
	int	i;
	int	nb;

	has_sign = 0;
	if (str[0] == '\0' || str[0] == '+')
		ft_error("PID can't be empty or '+'!");
	if (str[0] == '-')
		has_sign = 1;
	i = has_sign;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("PID is not digigt!");
		if ((str[i] == '+' || str[i] == '-') && i > 0)
			ft_error("PID can't start with '+'!");
		i++;
	}
	nb = ft_atoi(str);
	if (nb == 0 || nb == -1)
		ft_error("PID can't be 0 or -1!");
	return (nb);
}

void	ft_send_message(int server_pid, char c)
{
	int	i;
	int	signal_type;
	int	ascii_value;
	int	binary[8];

	ascii_value = c;
	i = 7;
	while (i >= 0)
	{
		binary[i] = ascii_value >> (7 - i) & 1;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		signal_type = 0;
		if (binary[i] == 0)
			signal_type = SIGUSR1;
		else if (binary[i] == 1)
			signal_type = SIGUSR2;
		if (kill(server_pid, signal_type) == -1)
			ft_error ("\033[1;31mError in sending signal");
		usleep(400);
		i++;
	}
}

int	main(int arc, char **arv)
{
	struct sigaction	sa;
	pid_t				server_pid;
	int					i;

	if (arc == 3)
	{
		sigemptyset(&sa.sa_mask);
		sa.sa_handler = signal_handler;
		sa.sa_flags = 0;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_error("Error setting up signal handler");
		server_pid = ft_check_pid(arv[1]);
		i = 0;
		while (arv[2][i] != '\0')
		{
			ft_send_message(server_pid, arv[2][i]);
			i++;
		}
		ft_send_message(server_pid, '\0');
		ft_send_message(server_pid, '\n');
	}
	else
		ft_error("Wrong numbers of arguments!");
	return (0);
}
