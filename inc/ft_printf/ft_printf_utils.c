/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:56:10 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/22 17:40:16 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdigit(long n, int base, char specifier)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (specifier == 'X')
		hex = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putdigit(-n, base, specifier) + 1);
	}
	else if (n < base)
		return (ft_putchar(hex[n]));
	else
	{
		i = ft_putdigit(n / base, base, specifier);
		return (i + ft_putdigit(n % base, base, specifier));
	}
}

int	ft_putudigit(unsigned long n)
{
	int		i;

	if (n < 10)
		return (ft_putchar(n + '0'));
	else
	{
		i = ft_putudigit(n / 10);
		return (i + ft_putudigit(n % 10));
	}
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putptr(unsigned long n, char specifier)
{
	char	*hex;
	int		i;

	i = 0;
	if (specifier == 'p')
		hex = "0123456789abcdef";
	else if (specifier == 'P')
		hex = "0123456789ABCDEF";
	if (n > 15)
	{
		i += ft_putptr(n / 16, specifier);
		i += ft_putptr(n % 16, specifier);
	}
	else if (n < 10)
		i += ft_putchar(n + '0');
	else
		i += ft_putchar(hex[n]);
	return (i);
}

int	ptr_null(unsigned long long p, char specifier)
{
	int	i;

	i = 0;
	if (p == 0)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		i += ft_putptr(p, specifier);
	}
	return (i);
}
