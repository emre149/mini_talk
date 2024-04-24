/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:25:34 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/24 18:28:06 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"
#include "../inc/ft_printf/ft_printf.h"

void	ft_binary_handler(int sig, char *c)
{
	if (sig == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (sig == SIGUSR2)
		*c <<= 1;
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		pid;
	static int		i;
	static char		c;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	ft_binary_handler(sig, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		ft_putchar(c);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID of the server : %ld\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error sigaction\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
