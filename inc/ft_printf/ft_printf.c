/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:41:26 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/15 15:58:42 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list     pointer;
	int         counter;
	char		specifier[3] = {0};

	counter = 0;
	va_start(pointer, format);
	while (*format)
	{
		if (*format == '%')
		{
			specifier[0] = *(++format);
			if (*format == 'l')
			{
				specifier[1] = *(++format);
				specifier[2] = '\0';
			}
			counter += print_format(specifier, pointer);
		}
		else
			counter += write(1, format, 1);
		++format;
	}
	va_end(pointer);
	return (counter);
}

