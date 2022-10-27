/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:06:47 by aelyakou          #+#    #+#             */
/*   Updated: 2022/03/13 13:06:49 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_img	image_creator(t_mlx mlx, char	*filename)
{
	t_img	image;

	image.img = mlx_xpm_file_to_image(
			mlx.mlx_ptr, filename, &image.width, &image.height);
	return (image);
}

void	*window_creator(t_mlx mlx, char	**level)
{
	void	*window;
	int		height;
	int		width;
	int		i;

	i = 0;
	while (level[i])
		i++;
	height = 56 * i;
	width = 56 * ft_strlen(level[0]);
	window = mlx_new_window(mlx.mlx_ptr, width, height, "So_long");
	return (window);
}

t_img	render_walls(t_mlx mlx, char **level)
{
	t_img	wall1;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	wall1 = image_creator(mlx, "Assets/Wall1.xpm");
	while (level[i][j] && level[i])
	{
		x = j * 56;
		y = i * 56;
		if (level[i][j] == '1')
			mlx_put_image_to_window(
				mlx.mlx_ptr, mlx.mlx_window, wall1.img, x, y);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (wall1);
}

t_img	render_player(t_mlx mlx, char **level)
{
	t_img	player;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	player = image_creator(mlx, "Assets/Player_character.xpm");
	while (level[i][j] && level[i])
	{
		x = j * 56;
		y = i * 56;
		if (level[i][j] == 'P')
			mlx_put_image_to_window(
				mlx.mlx_ptr, mlx.mlx_window, player.img, x, y);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (player);
}

t_img	render_collectible(t_mlx mlx, char **level)
{
	t_img	coin;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	coin = image_creator(mlx, "Assets/Collectible_coin.xpm");
	while (level[i][j] && level[i])
	{
		x = (j * 56) + 7;
		y = (i * 56) + 7;
		if (level[i][j] == 'C')
			mlx_put_image_to_window(
				mlx.mlx_ptr, mlx.mlx_window, coin.img, x, y);
		j++;
		if (level[i][j] == '\0' && level[i + 1])
		{
			j = 0;
			i++;
		}
	}
	return (coin);
}
