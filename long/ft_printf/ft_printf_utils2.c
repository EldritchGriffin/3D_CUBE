/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:39:04 by aelyakou          #+#    #+#             */
/*   Updated: 2021/12/26 04:39:05 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(char format, int *count, va_list args)
{
	if (format == 'X')
		print_hexa(va_arg(args, unsigned long), count, format);
	if (format == 'x')
		print_hexa(va_arg(args, unsigned long), count, format);
	if (format == 'p')
	{
		ft_putstr("0x", count);
		print_addr(va_arg(args, unsigned long), count);
	}
	if (format == '%')
		ft_putchar('%', count);
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	if (format == 'c')
		ft_putchar(va_arg(args, int), count);
	if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	if (format == 'u')
		unnbr(va_arg(args, int), count);
}

void	print_addr(unsigned long number, int *count)
{
	char	*bx;

	bx = "0123456789abcdef";
	if (number >= 16)
	{
		print_addr(number / 16, count);
		ft_putchar(bx[number % 16], count);
	}
	else
		ft_putchar(bx[number], count);
}
