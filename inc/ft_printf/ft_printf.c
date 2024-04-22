/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:41:26 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/22 18:06:54 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		pointer;
	int			counter;

	counter = 0;
	va_start(pointer, format);
	counter = process_format(format, pointer, &counter);
	va_end(pointer);
	return (counter);
}

void	spec_init(char *specifier)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		specifier[i] = 0;
		i++;
	}
}

int	process_format(const char *format, va_list pointer, int *counter)
{
	char	specifier[3];

	while (*format)
	{
		if (*format == '%')
		{
			spec_init(specifier);
			specifier[0] = *(++format);
			if (*format == 'l')
			{
				specifier[1] = *(++format);
				specifier[2] = '\0';
			}
			*counter += print_format(specifier, pointer);
		}
		else
			*counter += write(1, format, 1);
		++format;
	}
	return (*counter);
}
