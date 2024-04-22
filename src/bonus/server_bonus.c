/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:25:34 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/22 18:19:07 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mini_talk.h"
#include "../../inc/ft_printf/ft_printf.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	actual_char;
	static int				bit_position;

	(void)context;
	actual_char |= (sig == SIGUSR1);
	bit_position++;
	if (bit_position == 8)
	{
		if (actual_char == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", actual_char);
		bit_position = 0;
		actual_char = 0;
	}
	else
		actual_char <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID of the server : %ld\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
