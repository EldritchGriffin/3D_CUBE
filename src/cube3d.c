/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:41:56 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/30 14:47:28 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	loop_rays(t_data	*data)
{
	int 	i;

	data->rays = malloc(sizeof(t_ray) * data->mlx->w_w - 1);
	i = data->mlx->w_w - 1;
	while(i >= 0)
	{
		data->rays[i].dist = cast_ray(data, i);
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

void	is_collided(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = x / UNIT;
	map_y = y / UNIT;
	if(data->lvl->map[map_y][map_x] && data->lvl->map[map_y][map_x] == '1')
		return ;
	else
	{
		data->ply->p_pos->x = x;
		data->ply->p_pos->y = y;
	}
	return ;
}

void	p_move(t_data	*data)
{
	float	rad;
	float	new_y;
	float	new_x;
	rad = deg_to_rad(data->ply->pa);
	new_x = data->ply->p_pos->x + cosf(rad) * MVS * data->ply->m_dir;
	new_y = data->ply->p_pos->y - sinf(rad) * MVS * data->ply->m_dir;
	is_collided(new_x, new_y, data);
}
void	p_rotate(t_data	*data)
{
	data->ply->pa += TRS * data->ply->r_dir;
	data->ply->pa = limit_angles(data->ply->pa);
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

// unsigned int	get_texel(t_data	*data, int x, int y, int slice)
// {
// 	int	off_y;
// 	int	off_x;

// 	if(data->rays[x].is_v)
// 		off_x = fmod(data->rays[x].wall_pos.y, UNIT);
// 	else
// 		off_x = fmod(data->rays[x].wall_pos.x, UNIT);
// 	off_y = (y + (data->mlx->w_h / 2) - (slice / 2)) * (UNIT / slice);
// 	return (data->north->buff[((UNIT * off_y) + off_x)]);
// }

void	render_slice(t_data	*data, int slice, int x)
{
	int	y;
	// unsigned int color;

	if(slice > data->mlx->w_h)
		slice = data->mlx->w_h;
		y = (data->mlx->w_h / 2) - (slice / 2);
		while(y <= (data->mlx->w_h / 2) + (slice / 2))
		{
			// color = get_texel(data, x, y, slice);
			pixel_put_img(data->wrld, x, y, 0x666666);
			y++;
		}
}

void	render_walls3d(t_data	*data)
{
	int				slice;
	int 			i;

	i = 0;
	while(i <= data->mlx->w_w - 1)
	{
		slice = UNIT / data->rays[i].dist * data->dsp;
		render_slice(data, slice, i);
		i++;
	}
}

int	keyup(int keycode, t_data	*data)
{
	if(keycode == 123 || keycode == 124)
		data->ply->r_dir = 0;
	if(keycode == 13 || keycode == 1)		
		data->ply->m_dir = 0;
	return (0);
}

void	get_m_dir(int keycode, t_data	*data)
{
	if(keycode == 13)
	{
		data->ply->m_dir = 1;
		return ;
	}
	if(keycode == 1)
	{
		data->ply->m_dir = -1;
		return ;
	}
}


void	get_r_dir(int keycode, t_data	*data)
{
	if(keycode == 124)
	{
		data->ply->r_dir = -1;
		return ;
	}
	if(keycode == 123)
	{
		data->ply->r_dir = 1;
		return ;
	}
}

int	update(t_data	*data)
{
	p_move(data);
	p_rotate(data);
	mlx_clear_window(data->mlx->mp, data->mlx->w3);
	mlx_destroy_image(data->mlx->mp, data->wrld->img);
	data->wrld->img = mlx_new_image(data->mlx->mp,data->mlx->w_w, data->mlx->w_h);
	render_sky(data, 0x66b3d1, data->wrld);
	render_floor(data, 0x3d874a, data->wrld);
	loop_rays(data);
	render_walls3d(data);
	// render_level2d(data);
	mlx_put_image_to_window(data->mlx->mp, data->mlx->w3, data->wrld->img, 0, 0);
	mlx_put_image_to_window(data->mlx->mp, data->mlx->w3, data->west->img,0,0);
	return (0);
}

int	keydown(int keycode, t_data	*data)
{
	get_m_dir(keycode, data);
	get_r_dir(keycode, data);
	return (keycode);
}

int main()
{
	t_data	*data;

	data = get_data();
	if (!data)
		return (0);
	mlx_hook(data->mlx->w3, 2, 0, keydown, data);
	mlx_hook(data->mlx->w3, 3, 0, keyup, data);
	mlx_loop_hook(data->mlx->mp, update, data);
	mlx_loop(data->mlx->mp);
	return(0);
}