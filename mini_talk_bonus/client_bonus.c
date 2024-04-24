/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:56:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/24 18:27:52 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"
#include "../inc/ft_printf/ft_printf.h"

static int	g_receiver;

void	signal_sender(int pid, unsigned char c)
{
	int				bits;
	int				i;
	unsigned char	tmp;

	bits = 8;
	while (bits--)
	{
		tmp = c >> bits;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i = 0;
		while (g_receiver == 0)
		{
			if (i == 50)
				exit(1);
			i++;
			usleep(100);
		}
		g_receiver = 0;
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		g_receiver = 1;
}

void	issou(int pid)
{
	signal_sender(pid, '\n');
	signal_sender(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;
	char				*message;
	int					byte;

	if (argc != 3)
	{
		ft_printf("Format : ./client <PID> <MESSAGE_TO_SEND>\n");
		exit(0);
	}
	server_pid = atoi(argv[1]);
	message = argv[2];
	byte = -1;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error sigaction\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error sigaction\n");
	while (message[++byte] != '\0')
		signal_sender(server_pid, message[byte]);
	issou(server_pid);
	ft_printf("Message successfully sended !\n");
	return (0);
}
