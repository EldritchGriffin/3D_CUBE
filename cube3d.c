/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:41:56 by aelyakou          #+#    #+#             */
/*   Updated: 2022/10/27 23:21:13 by aelyakou         ###   ########.fr       */
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

int main()
{
	t_data	*data;

	data = get_data();
	printf("test x = %f\n", data->ply->p_pos->x / UNIT);
	printf("test x = %f\n", data->ply->p_pos->y / UNIT);
	render_level(data);
	render_player2D(data);
	render_sky3d(data);
	render_floor3d(data);
	mlx_loop(data->mlx->mp);
	return(0);
}