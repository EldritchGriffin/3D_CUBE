/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:41:56 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/04 23:39:49 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	render_sky3d(t_data	*data)
{
	int x;
	int	y;

	y = 0;
	while(y <= (data->lvl->l_h * UNIT) / 2)
	{
		x = 0;
		while(x <= data->lvl->l_w * UNIT)
		{
			mlx_pixel_put(data->mlx->mp, data->mlx->w3, x, y, 255);
			x++;
		}
		y++;
	}
}

void	render_floor3d(t_data	*data)
{
	int x;
	int y;

	y = (data->lvl->l_h * UNIT) / 2;
	while(y <= (data->lvl->l_h * UNIT))
	{
		x = 0;
		while(x <= data->lvl->l_w * UNIT)
		{
			mlx_pixel_put(data->mlx->mp, data->mlx->w3, x, y, (255 << 8) + 99999);
			x++;
		}
		y++;
	}
}

void	render_wall2D(int	x, int	y, t_data	*data)
{
	int	i;
	int j;
	int ox;
	ox = x;
	i = 0;
	while(i < 63)
	{
		j = 0;
		x = ox;
		while(j < 63)
		{
			mlx_pixel_put(data->mlx->mp, data->mlx->w2, x, y, 65280);
			x++;
			j++;
		}
		y++;
		i++;
	}
}

void	render_level(t_data	*data)
{
	int i;
	int j;

	i = 0;
	while(data->lvl->map[i])
	{
		j = 0;
		while(data->lvl->map[i][j])
		{
			if(data->lvl->map[i][j] == '1')
				render_wall2D(j * UNIT, i * UNIT, data);
			j++;
		}
		i++;
	}
}

void	render_player2D(t_data	*data)
{
	int i;

	
	i = data->ply->p_pos->x - 8;
	while(i <= (data->ply->p_pos->x + 8))
	{
		mlx_pixel_put(data->mlx->mp, data->mlx->w2, i, data->ply->p_pos->y, (255 << 2 * 8));
		i++;
	}
	i = data->ply->p_pos->y - 8;
	while(i <= data->ply->p_pos->y)
	{
		mlx_pixel_put(data->mlx->mp, data->mlx->w2, data->ply->p_pos->x, i, (255 << 2 * 8));
		i++;
	}
}

void	render_walls3d(float	*rays, t_data	*data)
{
	float	wh;
	int		i;
	float	j;
	float	sx;
	float	sy;
	int		index;

	sx = data->lvl->l_w * UNIT / P_W;
	sy = (data->lvl->l_h * UNIT) / P_H;
	index = data->lvl->l_w * UNIT;
	i = (P_W - 1);
	while(index >= 0 && i >= 0)
	{
		wh = UNIT / rays[i] * data->dsp;
		j = (data->lvl->l_h * UNIT / 2) - ((wh/2) * sy);
		while(j <= ((data->lvl->l_h * UNIT / 2) + ((wh / 2) * sy)))
		{
			mlx_pixel_put(data->mlx->mp, data->mlx->w3, index , j, (255 << 1 * 8));
			j++;
		}
		sx--;
		if((sx <= 0))
		{
			sx = (data->lvl->l_w * UNIT) / P_W;
			i--;
		}
		index--;
	}
}

void	loop_rays(t_data	*data)
{
	int 	i;

	data->rays = malloc(sizeof(float) * P_W - 1);
	i = P_W - 1;
	while(i >= 0)
	{
		data->rays[i] = cast_ray(data, i);
		i--;
	}
}

int	p_move(int keycode, t_data	*data)
{
	if(keycode == 0)
		data->ply->p_pos->x -= 5;
	if(keycode == 2)
		data->ply->p_pos->x += 5;
	if(keycode == 13)
		data->ply->p_pos->y -= 5;
	if(keycode == 1)
		data->ply->p_pos->y += 5;
	if(keycode == 123)
		data->ply->pa += 5;
	if(keycode == 124)
		data->ply->pa -= 5;
	mlx_clear_window(data->mlx->mp, data->mlx->w3);
	mlx_clear_window(data->mlx->mp, data->mlx->w2);
	render_level(data);
	render_player2D(data);
	render_floor3d(data);
	render_sky3d(data);
	loop_rays(data);
	render_walls3d(data->rays, data);
	return (keycode);
}

int main()
{
	t_data	*data;
	int		*keycode;

	data = get_data();
	render_level(data);
	render_player2D(data);
	render_sky3d(data);
	render_floor3d(data);
	loop_rays(data);
	render_walls3d(data->rays, data);
	mlx_hook(data->mlx->w3, 2, 0, p_move, data);
	mlx_loop(data->mlx->mp);
	return(0);
}