/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:55:07 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/17 15:40:41 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"
#include "../inc/ft_printf/ft_printf.h"

void    handler(int signum)
{
    if (signum == SIGUSR1)
        ft_printf("Received !\n");
}

int main(void)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    pid_t pid = getpid();
    ft_printf("PID: %ld\n", (long)pid);
    
    ft_printf("Waiting for messages...\n");
    while (1)
    {
        sleep(1);
    }
}