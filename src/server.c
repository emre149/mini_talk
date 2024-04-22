/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:55:07 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/20 13:30:55 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"
#include "../inc/ft_printf/ft_printf.h"

#define END '\0'

void    signal_handler(int sig)
{
    static unsigned char actual_char;
    static int  bit_position;

    actual_char |= (sig == SIGUSR1);
    bit_position++;
    if (bit_position == 8)
    {
        if (actual_char == END)
            ft_printf("\n");
        else
            ft_printf("%c", actual_char);
        bit_position = 0;
        actual_char = 0;
    }
    else
        actual_char <<= 1;
}

int main(void)
{
    ft_printf("PID of the server : %ld\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
        pause();
    return (0);
}