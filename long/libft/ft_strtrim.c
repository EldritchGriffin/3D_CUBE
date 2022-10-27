/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 03:31:54 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/11 03:31:56 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	contains(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (!(*s1))
		return (ft_strdup(""));
	if (!(*set))
		return (ft_strdup(s1));
	j = ft_strlen(s1) - 1;
	while (s1[i] && contains(set, s1[i]))
		i++;
	if (i == j + 1)
		return (ft_strdup(""));
	while (s1[j] && contains(set, s1[j]))
		j--;
	new = (char *)malloc((j - i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	new = ft_memcpy(new, (char *)s1 + i, j - i + 1);
	new[j - i + 1] = 0;
	return (new);
}
