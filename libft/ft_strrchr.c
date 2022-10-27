/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:06:00 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/06 12:13:45 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*res;

	res = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if (c == '\0')
		return (res + i);
	if (s[j] == (char)c)
		return (res + j);
	return (NULL);
}
