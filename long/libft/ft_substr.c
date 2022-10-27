/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:02:23 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/08 21:02:24 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	sizealloc(int start, int len, int s_len)
{
	if (len == 0 || start > s_len)
		return (1);
	if (s_len - start < len)
		return (s_len - start + 1);
	if (len >= s_len)
		return ((s_len - start) + 1);
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	size = sizealloc(start, len, ft_strlen(s));
	ptr = (char *)malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
