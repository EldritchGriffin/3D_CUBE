/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:40:47 by aelyakou          #+#    #+#             */
/*   Updated: 2022/03/13 21:40:49 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(char	**level, int	*coin_counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (level[i][j])
	{
		if (level[i][j] == 'P' && level [i - 1][j] == 'C')
			*coin_counter = *coin_counter - 1;
		if (level[i][j] == 'P' && level [i - 1][j]
		!= '1' && level [i - 1][j] != 'E')
		{
			level[i][j] = '0';
			level[i - 1][j] = 'P';
			return ;
		}
		if (level[i][j] == 'P' && level [i - 1][j] == 'E' && *coin_counter == 0)
			exit (0);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
}

void	move_down(char	**level, int	*coin_counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (level[i][j])
	{
		if (level[i][j] == 'P' && level [i + 1][j] == 'C')
			*coin_counter = *coin_counter - 1;
		if (level[i][j] == 'P' && level [i + 1][j]
		!= '1' && level [i + 1][j] != 'E')
		{
			level[i + 1][j] = 'P';
			level[i][j] = '0';
			return ;
		}
		if (level[i][j] == 'P' && level [i + 1][j] == 'E' && *coin_counter == 0)
			exit (0);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
}

void	move_left(char	**level, int	*coin_counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (level[i][j])
	{
		if (level[i][j] == 'P' && level[i][j - 1] == 'C')
			*coin_counter = *coin_counter - 1;
		if (level[i][j] == 'P' && level [i][j - 1]
		!= '1' && level [i][j - 1] != 'E')
		{
			level[i][j - 1] = 'P';
			level[i][j] = '0';
			return ;
		}
		if (level[i][j] == 'P' && level [i][j - 1] == 'E' && *coin_counter == 0)
			exit (0);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
}

void	move_right(char	**level, int	*coin_counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (level[i][j])
	{
		if (level[i][j] == 'P' && level [i][j + 1] == 'C')
			*coin_counter = *coin_counter - 1;
		if (level[i][j] == 'P' && level [i][j + 1]
		!= '1' && level [i][j + 1] != 'E')
		{
			level[i][j + 1] = 'P';
			level[i][j] = '0';
			return ;
		}
		if (level[i][j] == 'P' && level [i][j + 1] == 'E' && *coin_counter == 0)
			exit (0);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
}

void	increment_position(t_assets *assets)
{
	int			i;
	int			j;
	static int	x;
	static int	y;
	static int	status;

	i = -1;
	while (assets->level[++i])
	{	
		j = -1;
		while (assets->level[i][++j])
		{
			if ((x != j || y != i) && assets->level[i][j] == 'P' && status)
			{
				ft_printf("%d\n", assets->movement_counter++);
				status = 0;
			}
			if (assets->level[i][j] == 'P')
			{
				x = j;
				y = i;
				status = 1;
			}
		}
	}
}
