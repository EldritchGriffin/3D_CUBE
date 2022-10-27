/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:33:43 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/08 15:33:45 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*ptr;

	i = 0;
	ptr = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return (ptr);
	while (ptr[i] != '\0' && i < len)
	{
		j = 0;
		while (ptr[i + j] != '\0' && needle[j] != '\0'
			&& ptr[i + j] == needle[j] && i + j < len)
			j++;
		if (j == n_len)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
