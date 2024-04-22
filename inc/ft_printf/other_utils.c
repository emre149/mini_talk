/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:23:19 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/22 17:41:33 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char *specifier, va_list ptr)
{
	int	i;

	i = 0;
	if (ft_strcmp(specifier, "c") == 0)
		i += ft_putchar(va_arg(ptr, int));
	else if (ft_strcmp(specifier, "s") == 0)
		i += ft_putstr(va_arg(ptr, char *));
	else if (ft_strcmp(specifier, "d") == 0 || ft_strcmp(specifier, "i") == 0)
		i += ft_putdigit((long)va_arg(ptr, int), 10, specifier[0]);
	else if (ft_strcmp(specifier, "x") == 0 || ft_strcmp(specifier, "X") == 0)
		i += ft_putdigit((long)va_arg(ptr, unsigned int), 16, specifier[0]);
	else if (ft_strcmp(specifier, "u") == 0)
		i += ft_putudigit(va_arg(ptr, unsigned int));
	else if (ft_strcmp(specifier, "p") == 0 || ft_strcmp(specifier, "P") == 0)
		i += ptr_null(va_arg(ptr, unsigned long long), specifier[0]);
	else if (ft_strcmp(specifier, "ld") == 0
		|| ft_strcmp(specifier, "li") == 0)
		i += ft_putdigit(va_arg(ptr, long int), 10, specifier[1]);
	else
		i += write(1, specifier, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str && str[i])
	{
		ft_putchar((int)str[i]);
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *first, const char *second)
{
	int	i;

	i = 0;
	while (first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	if (first[i] == '\n' && second[i] == '\0')
		return (0);
	if (first[i] == '\0' && second[i] == '\n')
		return (0);
	return (first[i] - second[i]);
}
