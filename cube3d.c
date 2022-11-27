/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:41:56 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/27 02:25:44 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	loop_rays(t_data	*data)
{
	int 	i;

	data->rays = malloc(sizeof(float) * data->mlx->w_w - 1);
	i = data->mlx->w_w - 1;
	while(i >= 0)
	{
		data->rays[i] = cast_ray(data, i);
		i--;
	}
}

void	render_sky(t_data	*data, int color, t_img	*img)
{
	int x;
	int	y;

	y = 0;
	while(y < data->mlx->w_h / 2)
	{
		x = 0;
		while(x < data->mlx->w_w)
		{
			pixel_put_img(img, x, y, color);
			x++;
		}
		y++;
	}
}
void	render_floor(t_data	*data, int color, t_img	*img)
{
	int x;
	int	y;

	y = data->mlx->w_h / 2;
	while(y < data->mlx->w_h)
	{
		x = 0;
		while(x < data->mlx->w_w)
		{
			pixel_put_img(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	p_rotate(int keycode,	t_data	*data)
{
	if(keycode == 123)
		data->ply->pa += TRS;
	if(keycode == 124)
		data->ply->pa -= TRS;
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
		data->ply->p_pos->x += cosf(rad) * MVS;
		data->ply->p_pos->y -= sinf(rad) * MVS;
	}
	if(keycode == 1)
	{
		data->ply->p_pos->x -= cosf(rad) * MVS;
		data->ply->p_pos->y += sinf(rad) * MVS;
	}
}

void	render_wall2d(int	x, int	y, t_data	*data)
{
	int i;
	int	j;
	int	n_unit;
	int	ox;

	i = 0;
	n_unit = (UNIT) - 1;
	ox = x;
	while(i <= n_unit)
	{
		ox = x;
		j = 0;
		while(j <= n_unit)
		{
			pixel_put_img(data->wrld, ox / 4, y / 4, 0xfc6f03);
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
				render_wall2d(j * UNIT , i * UNIT, data);
			j++;
		}
		i++;
	}
}

void	render_slice(t_data	*data, int slice, int x, int width)
{
	int	y;

	if(slice > data->mlx->w_h)
		slice = data->mlx->w_h;
	while(width > 0)
	{
		y = (data->mlx->w_h / 2) - (slice / 2);
		while(y <= (data->mlx->w_h / 2) + (slice / 2))
		{
			pixel_put_img(data->wrld, x, y, 0xcc4ee6);
			y++;
		}
		x++;
		width--;
	}
}
void	render_walls3d(t_data	*data)
{
	int	slice;
	int i;

	i = 0;
	while(i <= data->mlx->w_w - 1)
	{
		slice = UNIT / data->rays[i] * data->dsp;
		render_slice(data, slice, i, 1);
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
	mlx_destroy_image(data->mlx->mp, data->wrld->img);
    data->wrld->img = mlx_new_image(data->mlx->mp,data->mlx->w_w, data->mlx->w_h);
	render_sky(data, 0x66b3d1, data->wrld);
	render_floor(data, 0x3d874a, data->wrld);
	loop_rays(data);
	render_walls3d(data);
	render_level2d(data);
	mlx_put_image_to_window(data->mlx->mp, data->mlx->w3, data->wrld->img, 0, 0);
	return (keycode);
}

int main()
{
	t_data	*data;
	int		*keycode;

	data = get_data();
	loop_rays(data);
	render_level2d(data);
	render_sky(data, 0x66b3d1, data->wrld);
	render_floor(data, 0x3d874a, data->wrld);
	render_walls3d(data);
	mlx_put_image_to_window(data->mlx->mp, data->mlx->w3, data->wrld->img, 0, 0);
	mlx_hook(data->mlx->w3, 2, 0, keydown, data);
	mlx_loop(data->mlx->mp);
	return(0);
}