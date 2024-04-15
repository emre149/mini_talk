/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:55:07 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/15 14:43:13 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"
#include "../inc/ft_printf/ft_printf.h"
#include <stdio.h>
int main(void)
{
    pid_t pid = getpid();
    ft_printf("PID: %ld\n", (long)pid);
    return 0;
}