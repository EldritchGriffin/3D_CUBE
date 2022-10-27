/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:53:38 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/08 11:39:38 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*str;

	i = 0;
	ptr = (unsigned char *) dst;
	str = (unsigned char *) src;
	if (n && !src && !dst)
		return (dst);
	while (i < n)
	{
		*ptr++ = *str++;
		i++;
	}
	return (dst);
}
