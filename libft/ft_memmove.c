/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:06:39 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/08 12:13:23 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (len && !dst && !src)
		return (dst);
	if (dst >= src)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else
	{
		while (src && i++ < len)
		{
			*d++ = *s++;
		}
	}
	return (dst);
}
