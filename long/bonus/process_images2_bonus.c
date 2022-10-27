/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_images2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:40:05 by aelyakou          #+#    #+#             */
/*   Updated: 2022/03/02 21:40:07 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	render_exit_closed(t_mlx m, char **level)
{
	t_img	exit;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	exit = image_creator(m, "Assets/Exit_closed.xpm");
	while (level[i][j] && level[i])
	{
		x = j * 56;
		y = i * 56;
		if (level[i][j] == 'E')
			mlx_put_image_to_window(m.mp, m.mw, exit.img, x, y);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (exit);
}

t_img	render_exit_open(t_mlx m, char **level)
{
	t_img	exit;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	exit = image_creator(m, "Assets/Exit_open.xpm");
	while (level[i][j] && level[i])
	{
		x = j * 56;
		y = i * 56;
		if (level[i][j] == 'E')
			mlx_put_image_to_window(m.mp, m.mw, exit.img, x, y);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (exit);
}

t_img	render_enemy(t_mlx mlx, char **level)
{
	t_img	enemy;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	enemy = image_creator(mlx, "Assets/Enemy_character.xpm");
	while (level[i][j] && level[i])
	{
		x = (j * 56) + 7;
		y = (i * 56) + 7;
		if (level[i][j] == 'N')
			mlx_put_image_to_window(
				mlx.mp, mlx.mw, enemy.img, x, y);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (enemy);
}

t_assets	render_level(t_assets assets)
{
	mlx_clear_window(assets.m.mp, assets.m.mw);
	assets.enemy = render_enemy(assets.m, assets.level);
	assets.wall = render_walls(assets.m, assets.level);
	assets.player = render_player(assets.m, assets.level);
	assets.coin = render_collectible(assets.m, assets.level);
	assets.exit_closed = render_exit_open(assets.m, assets.level);
	if (assets.cc > 0)
		assets.exit_open = render_exit_closed(assets.m, assets.level);
	return (assets);
}
