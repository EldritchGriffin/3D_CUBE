/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:52:20 by aelyakou          #+#    #+#             */
/*   Updated: 2021/12/22 18:52:22 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *flags, ...);
void	ft_putchar(char c, int *count);
void	print_hexa(unsigned int number, int *count, char c);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	unnbr(unsigned int n, int *count);
void	print_addr(unsigned long number, int *count);
void	check_format(char format, int *count, va_list args);
#endif