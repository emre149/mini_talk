/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:55:07 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/19 14:11:52 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"
#include "../inc/ft_printf/ft_printf.h"

void    signal_handler(int sig)
{
    static unsigned char actual_char;
    static int  bit_position;

    actual_char |= (sig == SIGUSR1);
    bit_position++;
    if (bit_position == 8)
    {
        if (actual_char == '\0')
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

}