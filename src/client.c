/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:56:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/18 17:24:02 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"
#include "../inc/ft_printf/ft_printf.h"

void    signal_sender(int pid, unsigned char c)
{
    int             bits;
    unsigned char   tmp;

    bits = 8;
    tmp = c;
    while (bits > 0)
    {
        bits--;
        tmp = c >> bits;
        if (tmp % 2  == 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(50);
    }
}

int main(int argc, char **argv)
{
    pid_t   server_pid;
    char    *message;
    int     byte;

    server_pid = ft_atoi(argv[1]);
    message = argv[2];
    byte = 0;

    if (argc != 3)
    {
        ft_printf("Format : ./client <PID> <MESSAGE_TO_SEND>");
        exit(0);
    }

    while (!message)
        signal_sender(server_pid, message[byte]);
    signal_sender(server_pid, '\0');
    return (0);
}
