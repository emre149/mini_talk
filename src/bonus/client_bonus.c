/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:56:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/24 16:43:15 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mini_talk.h"
#include "../../inc/ft_printf/ft_printf.h"

static int	g_receiver;

void	signal_sender(int n, siginfo_t *info, void *context)
{
	static int	bits;

	(void)n;
	(void)info;
	(void)context;
	g_receiver = 1;
	if (n == SIGUSR2)
		bits++;
}

int	ft_ctb(char c, int pid)
{
	int	i;
	int	bit_position;

	bit_position = 7;
	while (bit_position >= 0)
	{
		i = 0;
		if ((c >> bit_position) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (i == 50)
				exit(1);
			i++;
			usleep(100);
		}
		g_receiver = 0;
		bit_position--;
	}
	return (0);
}

void	issou(int pid)
{
	ft_ctb('\n', pid);
	ft_ctb('\0', pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					byte_position;
	int					pid;

	if (argc != 3)
	{
		ft_printf("Format : ./client <PID> <MESSAGE_TO_SEND>\n");
		exit(0);
	}
	byte_position = 0;
	pid = ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_sender;
	ft_printf("Message succesfully sended.\n");
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error sigaction\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error sigaction\n");
	while (argv[2][byte_position])
		ft_ctb(argv[2][byte_position++], pid);
	issou(pid);
	return (0);
}
