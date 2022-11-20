/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:41:56 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/19 23:12:22 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

void	p_rotate(int keycode,	t_data	*data)
{
	if(keycode == 123)
		data->ply->pa += 5;
	if(keycode == 124)
		data->ply->pa -= 5;
	if(data->ply->pa >= 360)
		data->ply->pa = data->ply->pa - 360;
	if(data->ply->pa < 0)
		data->ply->pa = 360 + data->ply->pa;
}

void	p_move(int	keycode, t_data	*data)
{
	float rad;

	rad = deg_to_rad(data->ply->pa);
	if(keycode == 13)
	{
		data->ply->p_pos->x += cosf(rad) * 10;
		data->ply->p_pos->y -= sinf(rad) * 10;
	}
	if(keycode == 1)
	{
		data->ply->p_pos->x -= cosf(rad) * 10;
		data->ply->p_pos->y += sinf(rad) * 10;
	}
}

void	render_wall2d(int	x, int	y, t_data	*data)
{
	int i;
	int	j;
	int	n_unit;
	int	ox;

	i = 0;
	n_unit = (UNIT / 4) - 1;
	ox = x;
	while(i <= n_unit)
	{
		ox = x;
		j = 0;
		while(j <= n_unit)
		{
			pixel_put_img(data->minimp, ox, y, 0x00FF00);
			j++;
			ox++;
		}
		y++;
		i++;
	}
}

void	render_level2d(t_data	*data)
{
	int i;
	int	j;

	i = 0;
	while(data->lvl->map[i])
	{
		j = 0;
		while(data->lvl->map[i][j])
		{
			if(data->lvl->map[i][j] == '1')
				render_wall2d(j * UNIT / 4 , i * UNIT / 4, data);
			j++;
		}
		i++;
	}
}

int	keydown(int keycode, t_data	*data)
{
	if(keycode == 123 || keycode == 124)
		p_rotate(keycode, data);
	if(keycode == 13 || keycode == 1)
		p_move(keycode, data);
	mlx_clear_window(data->mlx->mp, data->mlx->w3);
	mlx_destroy_image(data->mlx->mp, data->minimp->img);
    data->minimp->img = mlx_new_image(data->mlx->mp,data->mlx->w_w, data->mlx->w_h);
	loop_rays(data);
	render_level2d(data);
	mlx_put_image_to_window(data->mlx->mp, data->mlx->w3, data->minimp->img, 0, 0);
	return (keycode);
}

int main()
{
	t_data	*data;
	int		*keycode;

	data = get_data();
	loop_rays(data);
	render_level2d(data);
	mlx_put_image_to_window(data->mlx->mp, data->mlx->w3, data->minimp->img, 0, 0);
	mlx_hook(data->mlx->w3, 2, 0, keydown, data);
	mlx_loop(data->mlx->mp);
	return(0);
}