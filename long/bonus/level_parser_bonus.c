/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:02:08 by aelyakou          #+#    #+#             */
/*   Updated: 2022/03/02 21:02:10 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_components(char *map, int	*coin_counter)
{
	int	player;
	int	exit;
	int	index;

	player = 0;
	exit = 0;
	index = -1;
	while (map[++index])
	{
		if (map[index] != '0' && map[index] != '1'
			&& map[index] != 'P' && map[index] != 'C'
			&& map[index] != 'E' && map[index] != 'N' && map[index] != '\n')
			return (-1);
		if (map[index] == 'P')
			player++;
		if (map[index] == 'C')
			*coin_counter = *coin_counter + 1;
		if (map[index] == 'E')
			exit++;
	}
	if (player != 1 || exit < 1 || *coin_counter < 1)
		return (free(map), -1);
	return (free(map), 0);
}

int	check_borders(char **level, int	*h_size, int *index)
{
	int	i;

	i = -1;
	while (level[0][++*index])
	{
		if (level[0][*index] != '1' )
			return (-1);
	}
	*index = 0;
	while (level[++i])
	{
		if (level[i][0] != '1' || level[i][*h_size - 1] != '1'
		|| ft_strlen(level[i]) != *h_size)
			return (1);
		if (level[i + 1] == '\0')
		{
			while (level[i][++*index])
			{
				if (level[i][*index] != '1')
					return (-1);
			}
		}
	}
	return (0);
}

int	map_parser(char	**level, char *map, int	*coin_counter)
{
	int	h_size;
	int	status;
	int	map_len;
	int	index;

	index = -1;
	if (!level)
		return (ft_printf("Error: Empty map\n"), -1);
	map_len = ft_strlen(map);
	h_size = ft_strlen(level[0]);
	status = check_borders(level, &h_size, &index);
	if (map[0] == '\n' || map[map_len - 1] == '\n')
		status = -1;
	if (status != 0)
		return (ft_printf("Error: Please recheck your borders!\n"), -1);
	status = check_components(map, coin_counter);
	if (status != 0)
		return (ft_printf("Error: Please recheck your components!\n"), -1);
	return (ft_printf("Valid map, Running game ...\n"), 0);
}
