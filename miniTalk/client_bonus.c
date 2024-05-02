/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:20:49 by bmakhama          #+#    #+#             */
/*   Updated: 2024/05/02 13:32:22 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void signal_handler(int signum) {
    // static int count = 0;
    // count++;
    ft_printf("Recieved signal:%d\n", signum);
}

void ft_ascii_to_binary(char c, int binary[8])
{
    int i = 7;
    int ascii_value = c;
    while (i >= 0)
    {
        binary[i] = (ascii_value >> (7 - i)) & 1;
        i--;
    }
}
//SIGUSR1 = 0;
//SIGUSR2 = 1;
void ft_send_message(int server_pid, char c)
{
    int binary[8];
    ft_ascii_to_binary(c, binary);
    int i = 0;
    while (i < 8)
    {
        int signal_type = 0;
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

int main(int arc, char **arv)
{
    pid_t server_pid;

    if (arc == 3)
    {
        signal(SIGUSR1, signal_handler);
        server_pid = ft_atoi(arv[1]);
        if (server_pid <= 0)
        {
            ft_printf("\033[1;31mError in getting pid");
            exit(EXIT_FAILURE);
        }
        int i = 0;
        while(arv[2][i] != '\0')
        {
            ft_send_message(server_pid, arv[2][i]);
            i++;
        }
        ft_send_message(server_pid, '\0');
        ft_send_message(server_pid, '\n');
    }
    else
    {
        ft_printf("Arguments must be 2: <PID> <Message>");
        return (1);
    }
    return (0);
}
