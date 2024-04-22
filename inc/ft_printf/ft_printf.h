/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:04:14 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/22 18:04:42 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		print_format(char *specifier, va_list ptr);

int		ft_putchar(int c);

int		ft_putstr(char *str);

int		ft_putdigit(long n, int base, char specifier);

int		ft_putudigit(unsigned long n);

int		ft_putptr(unsigned long n, char specifier);

int		ptr_null(unsigned long long p, char specifier);

int		ft_strcmp(const char *first, const char *second);

int		process_format(const char *format, va_list pointer, int *counter);

void	spec_init(char *specifier);

#endif