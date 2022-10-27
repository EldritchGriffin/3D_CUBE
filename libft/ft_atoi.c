/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:59:18 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/06 12:11:59 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	compute_num(const char *str, int i)
{
	int	n;

	n = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			break ;
		else
		{
			n = n * 10 + (str[i] - '0');
		}
		i++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			i++;
		else
		{
			sign = sign * -1;
			i++;
		}
	}
	n = compute_num(str, i);
	return (n * sign);
}
