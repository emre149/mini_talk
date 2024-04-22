/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:56:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/22 16:03:32 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mini_talk.h"
#include "../../inc/ft_printf/ft_printf.h"

void    signal_sender(int pid, unsigned char c)
{
    int             bits;
    unsigned char   tmp;

    bits = 8;
    while (bits--)
    {
        tmp = c >> bits;
        if (tmp % 2  == 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(50);
    }
}

void    reception_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message succesfully received.\n");
}

int main(int argc, char **argv)
{
    pid_t           server_pid;
    const char      *message;
    int             byte;

	signal(SIGUSR1, reception_handler);
	signal(SIGUSR2, reception_handler);

    if (argc != 3)
    {
        ft_printf("Format : ./client <PID> <MESSAGE_TO_SEND>\n");
        exit(0);
    }

    server_pid = ft_atoi(argv[1]);
    message = argv[2];
    byte = -1;
    
    while (message[++byte] != '\0')
        signal_sender(server_pid, message[byte]);
    signal_sender(server_pid, '\0');
    return (0);
}