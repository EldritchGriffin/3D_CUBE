/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:11:09 by aelyakou          #+#    #+#             */
/*   Updated: 2022/03/20 21:11:10 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_frames(t_assets *assets)
{
	render_enemy2(assets->m, assets->level);
	render_player2(assets->m, assets->level);
	increment_position(assets);
	return (0);
}

t_img	render_player2(t_mlx mlx, char **level)
{
	t_img	player;
	t_vec2	v1;
	t_vec2	v2;

	v1.i = 0;
	v1.j = 0;
	player = image_creator(mlx, "Assets/Player_character1.xpm");
	while (level[v1.i][v1.j] && level[v1.i])
	{
		v2.j = v1.j * 56;
		v2.i = v1.i * 56;
		if (level[v1.i][v1.j] == 'P')
			mlx_put_image_to_window(
				mlx.mp, mlx.mw, player.img, v2.j, v2.i);
		v1.j++;
		if (level[v1.i][v1.j] == '\0' && level[v1.i + 1])
		{
			v1.j = 0;
			v1.i++;
		}
	}
	return (player);
}

t_img	render_enemy2(t_mlx mlx, char **level)
{
	t_img	enemy;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	enemy = image_creator(mlx, "Assets/Enemy_character1.xpm");
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
