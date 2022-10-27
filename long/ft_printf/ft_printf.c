/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:52:11 by aelyakou          #+#    #+#             */
/*   Updated: 2021/12/22 18:52:15 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p'
				|| format[i] == '%' || format[i] == 'd' || format[i] == 'i'
				|| format[i] == 'c' || format[i] == 's' || format[i] == 'u')
				check_format(format[i], &count, args);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	return (count);
}
