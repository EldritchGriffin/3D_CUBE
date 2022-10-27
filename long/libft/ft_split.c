/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:47:05 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/12 01:47:06 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	word_counter(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				count++;
			}
		}
		i++;
	}
	return (count);
}

static int	*words_size(const char *s, char c)
{
	int	count;
	int	*sizes;
	int	i;
	int	j;
	int	n;

	count = word_counter(s, c);
	sizes = malloc(sizeof(int) * count);
	if (!sizes)
		return (NULL);
	i = 0;
	j = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			if ((s[i + 1] == c || s[i + 1] == '\0') && n < count)
				sizes[n++] = j + 1;
		}
		if (s[i++] == c)
			j = 0;
	}
	return (sizes);
}

static char	**allocate_new(char const *s, char c)
{
	int		count;
	char	**new;
	int		n;
	int		*sizes;

	n = -1;
	sizes = words_size(s, c);
	count = word_counter(s, c);
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	while (++n < count)
	{
		new[n] = (char *)malloc(sizeof(char) * sizes[n]);
		if (!new[n])
		{
			while (--n)
				free(new[n]);
			return (free(new), free(sizes), NULL);
		}
	}
	new[count] = NULL;
	free(sizes);
	return (new);
}

void	fill_new(char **new, const char *s, char c, int count)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (j < count)
			{
				new[j][n++] = s[i];
				if ((s[i + 1] == c || s[i + 1] == '\0'))
				{
					new[j++][n] = '\0';
					n = 0;
				}
			}
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		count;

	if (!s)
		return (NULL);
	new = allocate_new(s, c);
	count = word_counter(s, c);
	if (!new)
		return (NULL);
	fill_new(new, s, c, count);
	return (new);
}
