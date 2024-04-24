/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:57:12 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/24 16:39:48 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

/*INCLUDES*/

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <stddef.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
int		ft_ctb(char c, int pid);
void	reception_handler(int sig);
void	ft_putchar_fd(char c, int fd);
void	issou(int pid);

#endif