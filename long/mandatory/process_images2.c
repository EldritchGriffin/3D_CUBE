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

#include "so_long.h"

t_img	render_exit_closed(t_mlx mlx, char **level)
{
	t_img	exit;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	exit = image_creator(mlx, "Assets/Exit_closed.xpm");
	while (level[i][j] && level[i])
	{
		x = j * 56;
		y = i * 56;
		if (level[i][j] == 'E')
			mlx_put_image_to_window(
				mlx.mlx_ptr, mlx.mlx_window, exit.img, x, y);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (exit);
}

t_img	render_exit_open(t_mlx mlx, char **level)
{
	t_img	exit;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	exit = image_creator(mlx, "Assets/Exit_open.xpm");
	while (level[i][j] && level[i])
	{
		x = j * 56;
		y = i * 56;
		if (level[i][j] == 'E')
			mlx_put_image_to_window(
				mlx.mlx_ptr, mlx.mlx_window, exit.img, x, y);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (exit);
}

t_assets	render_level(t_assets assets)
{
	mlx_clear_window(assets.mlx.mlx_ptr, assets.mlx.mlx_window);
	assets.wall = render_walls(assets.mlx, assets.level);
	assets.player = render_player(assets.mlx, assets.level);
	assets.coin = render_collectible(assets.mlx, assets.level);
	assets.exit_closed = render_exit_open(assets.mlx, assets.level);
	if (assets.coin_counter > 0)
		assets.exit_open = render_exit_closed(assets.mlx, assets.level);
	return (assets);
}
