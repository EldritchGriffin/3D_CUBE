/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:54:29 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/14 03:54:35 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*secure_cases(int n)
{
	char	*str;

	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	if (n == 0)
		str = ft_strdup("0");
	return (str);
}

static int	size_counter(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}	
	return (count);
}

static char	*fill_str(int n, char *str, int size)
{
	int	i;

	while (n != 0)
	{
		if (n < 0)
			n = -n;
			str[0] = '-';
		if (n < 10)
		{
			str[size] = n + 48;
			break ;
		}
		i = (n % 10);
		str[size] = i + 48;
		n = n / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n == -2147483648 || n == 0)
	{
		str = secure_cases(n);
		return (str);
	}
	size = size_counter(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	str = fill_str(n, str, size);
	return (str);
}
