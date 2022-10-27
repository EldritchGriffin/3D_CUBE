/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 02:48:06 by aelyakou          #+#    #+#             */
/*   Updated: 2021/12/25 02:48:08 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-n, count);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putchar((n % 10) + '0', count);
	}
	else
		ft_putchar(n + '0', count);
}

void	unnbr(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putchar((n % 10) + '0', count);
	}
	else
		ft_putchar(n + '0', count);
}

void	print_hexa(unsigned int number, int *count, char c)
{
	char	*bx;

	if (c == 'x')
		bx = "0123456789abcdef";
	if (c == 'X')
		bx = "0123456789ABCDEF";
	if (number >= 16)
	{
		print_hexa(number / 16, count, c);
		ft_putchar(bx[number % 16], count);
	}
	else
		ft_putchar(bx[number], count);
}
