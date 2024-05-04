/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:50:18 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/04 14:21:38 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	ft_printf("Illegal PID");
	exit(1);
}

pid_t	ft_handle_pid(char *str)
{
	int	has_sign;
	int	i;
	int	nb;

	has_sign = 0;
	if (str[0] == '\0' || str[0] == '+')
		ft_error();
	if (str[0] == '-')
		has_sign = 1;
	i = has_sign;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		if ((str[i] == '+' || str[i] == '-') && i > 0)
			ft_error();
		i++;
	}
	nb = ft_atoi(str);
	if (nb == 0 || nb == -1)
		ft_error();
	return (nb);
}

void	ft_ascii_to_binary(char c, int binary[8])
{
	int	i;
	int	ascii_value;

	i = 7;
	ascii_value = c;
	while (i >= 0)
	{
		binary[i] = (ascii_value >> (7 - i)) & 1;
		i--;
	}
}
//SIGUSR1 = 0; SIGUSR2 = 1;

void	ft_send_char(int server_pid, char c)
{
	int	binary[8];
	int	i;
	int	signal_type;

	ft_ascii_to_binary(c, binary);
	i = 0;
	while (i < 8)
	{
		signal_type = 0;
		if (binary[i] == 0)
			signal_type = SIGUSR1;
		else if (binary[i] == 1)
			signal_type = SIGUSR2;
		if (kill(server_pid, signal_type) == -1)
		{
			ft_printf("\033[1;31mError in sending signal");
			exit(1);
		}
		usleep(400);
		i++;
	}
}

int	main(int arc, char **arv)
{
	pid_t	server_pid;
	int		i;

	if (arc == 3)
	{
		server_pid = ft_handle_pid(arv[1]);
		ft_printf("ser PID:%d\n", server_pid);
		i = 0;
		while (arv[2][i] != '\0')
		{
			ft_send_char(server_pid, arv[2][i]);
			i++;
		}
		ft_send_char(server_pid, '\0');
		ft_send_char(server_pid, '\n');
	}
	else
	{
		ft_printf("Arguments must be 2: <PID> <Message>");
		return (1);
	}
	return (0);
}
