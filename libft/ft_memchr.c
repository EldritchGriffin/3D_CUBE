/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:55:02 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/06 12:12:39 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *) b;
	chr = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		if (str[i] == chr)
			return ((void *)b + i);
		i++;
	}
	return (NULL);
}
